//Betriebssysteme Praktikum WS17/18 - Buchard
//Bennet Wilhelm    751205
//Jan-Henrik Keller 750612

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <iostream>
#include <vector>

using namespace::std;

int childForegroundPID;
vector<int> parentsBgChildPidVector_RUNNING;
vector<int> parentsBgChildPidVector_INTERRUPTED;
vector<int> parentsBgChildPidVector_STOPPED;

int exe_logout();
void deleteElementInVector(vector<int>&, int);

void SIGINT_Handler(int signum) //SIGINT == 2
{
	cout << " [caught SIGINT]\n";

	if (childForegroundPID == -1) {
		cout << "There is no forgroundprocess\n";
		exe_logout();
		exit(EXIT_SUCCESS);
	}
	else {
		kill(childForegroundPID, SIGINT);
		parentsBgChildPidVector_INTERRUPTED.push_back(childForegroundPID);
		childForegroundPID = -1;
	}
}

void SIGTSTP_Handler(int signum) //SIGTSTP == 20
{
	cout << " [caught SIGTSTP]\n";

	if (childForegroundPID == -1) {
		cout << "Error: There is no forgroundprocess\n";
	}
	else {
		kill(childForegroundPID, SIGTSTP);
		parentsBgChildPidVector_STOPPED.push_back(childForegroundPID);
		childForegroundPID = -1;
	}
}

void clearVector(vector<int>& vector) { //Einen Vector durchgehen und Zombie-Einträge löschen
	int localStatus;

	for (int counter = 0; counter < vector.size(); counter++) {
		waitpid(vector[counter], &localStatus, WNOHANG);
		if (WIFEXITED(localStatus)) {
			deleteElementInVector(vector, vector[counter]);
		}
		else if (WIFSTOPPED(localStatus)) {
			deleteElementInVector(vector, vector[counter]);
			kill(vector[counter], SIGKILL);
		}
		else if (WIFSIGNALED(localStatus)) {
			deleteElementInVector(vector, vector[counter]);
			kill(vector[counter], SIGKILL);
		}
	}
}

void SIGCHLD_Handler(int signum) {
	cout << " [caught SIGCHLD]\n";

	clearVector(parentsBgChildPidVector_RUNNING);
	clearVector(parentsBgChildPidVector_INTERRUPTED);
	clearVector(parentsBgChildPidVector_STOPPED);
}

void deleteElementInVector(vector<int>& vector, int item) {
	for (int counter = 0; counter < vector.size(); counter++) {
		if (vector[counter] == item) {
			vector.erase(vector.begin() + counter);
			return;
		}
	}
}

char *read_line() {

	int pos = 0;
	int maxBuf = 512;
	int character;  //Muss ein Int statt einem Char sein, weil EOF sonst nicht funktioniert
	char *buffer = (char*)malloc(sizeof(char) * maxBuf); //Reserviert Speicherplatz in der Größe eines Chars * maximale Anzahl der Chars und gibt einen Pointer auf den ersten Speicherplatz zurück

	while (1) {
		character = getchar();

		if (character == EOF || character == '\n') {
			buffer[pos] = '\0';
			return buffer;
		}
		else {
			buffer[pos] = character;
			++pos;
		}

		if (pos > maxBuf) {
			cout << "Error: Line-Buffer is full.\n";
			return buffer;
		}
	}
}

char **tokenise(char *line) {  //Teilt die Lines in Tokens

	int pos = 0;
	int bufSize = 64;
	char **tokens = (char**)malloc(bufSize * sizeof(char*));
	char *token;

	token = strtok(line, " \t\r\n\a");
	while (token != NULL) {
		tokens[pos] = token;
		pos++;

		if (pos > bufSize) {
			cout << "Error: Parse-Buffer is full.\n";
			return tokens;
		}

		token = strtok(NULL, " \t\r\n\a");
	}

	tokens[pos] = NULL;  //Sicherstellen dass die Tokens von einem NULL abgeschlossen werden (wichtig für execute)
	return tokens;
}

bool backgroundCheck(char **tokens) {

	int i = 0;
	int tmp = '&';

	while (tokens[i + 1] != NULL) {
		i++;
	}

	if (strcmp(tokens[i], "&") == 0) {
		tokens[i] = NULL;
		return true;
	}
	else {
		return false;
	}
}

void waitingForWho() {
	cout << "parentsBgChildPidVector_RUNNING: ";
	for (int counter = 0; counter < parentsBgChildPidVector_RUNNING.size(); counter++) {
		cout << parentsBgChildPidVector_RUNNING[counter] << ", ";
	}
	cout << endl;

	cout << "parentsBgChildPidVector_INTERRUPTED: ";
	for (int counter = 0; counter < parentsBgChildPidVector_INTERRUPTED.size(); counter++) {
		cout << parentsBgChildPidVector_INTERRUPTED[counter] << ", ";
	}
	cout << endl;

	cout << "parentsBgChildPidVector_STOPPED: ";
	for (int counter = 0; counter < parentsBgChildPidVector_STOPPED.size(); counter++) {
		cout << parentsBgChildPidVector_STOPPED[counter] << ", ";
	}
	cout << endl << endl;
}

int exe_logout() {

	clearVector(parentsBgChildPidVector_RUNNING);
	clearVector(parentsBgChildPidVector_INTERRUPTED);
	clearVector(parentsBgChildPidVector_STOPPED);

	if ((parentsBgChildPidVector_STOPPED.empty() == false) || (parentsBgChildPidVector_STOPPED.empty() == false) || (parentsBgChildPidVector_RUNNING.empty() == false)) {
		cout << "Error: Cant logout - You still got some backgroundprocesses.\n";
		waitingForWho();
		return 1;
	}

	cout << "Are you sure you want to logout? (y/n)\n";
	int character = getchar();
	if (character == 'y' || character == 'Y') {
		return 0;
	}
	else {
		return 1;
	}
}

int exe_fg() {
	if (parentsBgChildPidVector_STOPPED.empty()) {
		cout << "Error: There are no stopped backgroundprocesses.\n";
		return 1;
	}
	else {
		int status;
		childForegroundPID = parentsBgChildPidVector_STOPPED[0];	//Es wird nur einmal auf den Vector zugegriffen, da sonst ein kritischer Abschnitt entsteht!!
		deleteElementInVector(parentsBgChildPidVector_STOPPED, childForegroundPID);

		kill(childForegroundPID, SIGCONT);							//dem ersten Kindprozess aus dem Vector SIGCONT schicken
		int wpid = waitpid(childForegroundPID, &status, WUNTRACED); //und auf diesen Warten
		childForegroundPID = -1;

		return 1;
	}
}

int exe_bg() {
	if (parentsBgChildPidVector_STOPPED.empty()) {
		cout << "Error: There are no stopped backgroundprocesses.\n";
		return 1;
	}
	else {
		int childToBeContinuedPID = parentsBgChildPidVector_STOPPED[0];	//Es wird nur einmal auf den Vector zugegriffen, da sonst ein kritischer Abschnitt entsteht!!
		deleteElementInVector(parentsBgChildPidVector_STOPPED, childToBeContinuedPID);

		kill(childToBeContinuedPID, SIGCONT);							//dem ersten Kindprozess aus dem Vector SIGCONT schicken
		return 1;
	}
}

int exe_morphMyself(char **tokens) {
	if (execvp(tokens[0], tokens) == -1) {
		cout << "Error: Couldnt execute " << tokens[0] << "\n";
	}
}

int exe_launch(char **tokens, int executeInBackground, pid_t pid, pid_t wpid) {
	setpgid(pid, pid); //Signalgruppe des Kindes anpassen

	int status;
	if (executeInBackground == 1) {
		parentsBgChildPidVector_RUNNING.push_back(pid);		//ToDo: Prozesse aus dem Vector entfernen, wenn sie terminieren und sie zwischen den Vectoren bewegen
		cout << "Pid vom Hintergrundprozess: " << pid << "\n";
	}
	else { //Execute in Foreground
		childForegroundPID = pid;
		wpid = waitpid(pid, &status, WUNTRACED);
		childForegroundPID = -1;
	}
}

int execute(char **tokens) {

	if (tokens[0] == NULL) { //Leerer Befehl
		return 1;
	}
	else if (strcmp(tokens[0], "logout") == 0) {
		return exe_logout();
	}
	else if (strcmp(tokens[0], "fg") == 0) {
		return exe_fg();
	}
	else if (strcmp(tokens[0], "bg") == 0) {
		return exe_bg();
	}

	int executeInBackground = 0;
	if (backgroundCheck(tokens) == true) {
		executeInBackground = 1;
	}

	pid_t pid, wpid;
	int status;
	pid = fork();

	if (pid == 0) {
		exe_morphMyself(tokens);
		exit(EXIT_FAILURE); //If no error occurs the method never returns and exit is never reached
	}
	else if (pid < 0) {
		cout << "Error with forking!\n";
		exit(EXIT_FAILURE);
	}
	else {
		exe_launch(tokens, executeInBackground, pid, wpid);
	}

	return 1;
}

void daLoop() {

	char *line;
	char **tokens;
	int status = 1;

	while (status) {
		printf("> ");
		line = read_line();
		tokens = tokenise(line);
		status = execute(tokens);

		free(line);
		free(tokens);
	}

	return;
}

int main() {

	signal(SIGINT, SIGINT_Handler);
	signal(SIGTSTP, SIGTSTP_Handler);
	signal(SIGCHLD, SIGCHLD_Handler);

	cout << "Welcome to my Shell!\n";

	daLoop();

	cout << "Goodbye!\n";
}

