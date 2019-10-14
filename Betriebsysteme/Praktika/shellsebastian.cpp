[12:16, 23.11.2017] Kai H_da: /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sebastian
 *
 * Created on 28. Oktober 2017, 12:37
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <signal.h>
#include <vector>
#include <utility>

using namespace std;

bool fetchInput();
bool start(string cmd);
void sigint_handler(int s);
void sigstp_handler(int s);
void sigchld_handler(int s);
void jobs();
void fg(int l_pid);
void bg(int l_pid);
char path[FILENAME_MAX];
pid_t m_pid = -1;
vector<pair<pid_t, bool>> process; //second argument is true if running
pair<pid_t, bool> t = pair<pid_t, bool>();
/*
 * 
 */
int main(int argc, char** argv) {
    
    //SIgnale
    signal(SIGINT,sigint_handler);
    signal(SIGTSTP, sigstp_handler);
    signal(SIGCHLD, sigchld_handler);
    
    process = vector<pair<pid_t,bool>>();
    getcwd(path,sizeof(path));
    
    while (fetchInput()) 
        ;

    return 0;
}

bool fetchInput() {
    string arg = "";
    cout << path << " >>> ";
    getline(cin,arg);

    if(arg == "")
        ;
    else if(arg == "exit"){
        if(process.size() > 0){
            cerr << endl <<"Es wird noch ein Hintergrundprozess ausgeführt!" << endl;
            return 1;
        } 
        return 0;}
    else if(arg == "logout"){
        cout << "Wollen Sie die Shell wirklich beenden (J/N) ";
        cin >> arg;
        if(process.size() > 0){
            cerr << endl <<"Es wird noch ein Hintergrundprozess ausgeführt!" << endl;
            return 1;
        }   
        else if(arg.at(0) == 'J' || arg.at(0) == 'j' || arg.at(0) == 'Y' || arg.at(0) == 'y')
            return 0;
    }
    else if(arg.substr(0,3) == "fg "){
        string tmp;
        int l_pid;
        stringstream ss(arg);
        ss >> tmp;
        ss >> l_pid;
        fg(l_pid);
    }
    else if(arg.substr(0,3) == "bg "){
        string tmp;
        int l_pid;
        stringstream ss(arg);
        ss >> tmp;
        ss >> l_pid;
        bg(l_pid);
    }
    else if(arg == "jobs")
        jobs();
    else
        return start(arg);
    return 1;

}

bool start(string cmd) {
    int status;
    int length = count(cmd.cbegin(), cmd.cend(), ' ') + 2;
    bool keepGoing = false;
    char* args[length];
    string var = "";
    stringstream stream(cmd); //nach execvp springt das programm hierhin zurück und wirft einen fehler wenn vfork() genutzt wird
    int i = 0;
    do{
        stream >> args[i];
        var = args[i];
        if (var.at(0) == 38){
            length--;
            args[i] = NULL;
            keepGoing = true;}
        i++;
    }   while(length > (i+1));
    
    args[i] = NULL;
    
    m_pid = fork();     //mit vfork() stürtzt die shell ab.
    setpgid(m_pid, m_pid);
    //int pid = 0;
    if(m_pid == 0){ 
        execvp(args[0], args);
        return 0;
    }
    else{ 
        if(keepGoing){
            cout << "pid: " << (int) m_pid << endl;
            waitpid(m_pid,&status,WUNTRACED | WNOHANG);
            t.first = m_pid;
            t.second = true;
            process.push_back(t);
            m_pid = -1;
        }
        else{
            /*t.first = m_pid;
            t.second = true;
            process.push_back(t);*/
            waitpid(m_pid,&status,WUNTRACED);
            m_pid = -1;
        }
        return 1;
    }
}

void sigint_handler(int s){
    string arg;
    if(process.size() == 0 && m_pid == -1){
        cout << endl << "Wollen Sie die Shell wirklich beenden (J/N) ";
        cin >> arg;
        if(arg.at(0) == 'J' || arg.at(0) == 'j' || arg.at(0) == 'Y' || arg.at(0) == 'y')
            exit(0);
    }    
    else if(m_pid > 0){
        cout << "Killed " << m_pid;
       kill(m_pid,SIGINT);
       m_pid = -1;
    }
    cout << endl;
    
}

void sigstp_handler(int s){
    
    if(m_pid > 0){
        kill(m_pid,SIGTSTP);
        t.first = m_pid;
        t.second = false;
        process.push_back(t);
        cout << "Stopped process " << m_pid;
        m_pid = -1;
        
    }
    cout << endl;        
    
}

void sigchld_handler(int s){
    pid_t l_pid;
    int   status;
    l_pid = waitpid(-1, &status, WNOHANG);
    if(l_pid == -1)
        ; //Wenn der aktuelle vordergrundprozess beended wird landet man hier, momentan aber noch keine notwendigkeit dann etwas zu tun
    else{
        for(int i = 0; i < process.size(); i++){
            if(process.at(i).first == l_pid){
                process.erase(process.begin()+i);
                cout << endl << "process " << l_pid << " terminated" << endl;
                m_pid = -1;
                return;
            }
        }
    }
    
    
} 

void jobs(){
    for(int i = 0; i < process.size(); i++){
        cout << "[" << i << "]       " << process.at(i).first << " status ";
        if(process.at(i).second)
            cout << "running" << endl;
        else
            cout << "stopped" << endl;
    }
}


void fg(int l_pid){
    for(int i = 0; i < process.size(); i++){
        if(process.at(i).first == l_pid){
            if(process.at(i).second == false){
                 kill(process.at(i).first, SIGCONT);
            }
            m_pid = process.at(i).first;
            process.erase(process.begin()+i);
            waitpid(m_pid,0,WUNTRACED);
            return;
        }
            
    }
    cout << "Prozess nicht in jobliste." << endl; 
}

void bg(int l_pid){
    for(int i = 0; i < process.size(); i++){
        if(process.at(i).first == l_pid){
            if(process.at(i).second == false){
                 kill(process.at(i).first, SIGCONT);
                 process.at(i).second = true;
            }
            waitpid(m_pid,0,WUNTRACED | WNOHANG);
            m_pid = -1;
            return;
        }
            
    }
    cout << "Prozess nicht in jobliste." << endl; 
}