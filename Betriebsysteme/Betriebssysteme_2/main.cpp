/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: stud
 *
 * Created on 8. November 2017, 13:50
 */

#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <sys/wait.h>


using namespace std;

/*
 * 
 */

void shell();

int main(void)
{
    while (1)
        shell();
}

void shell()
{
    int i = 0;
    string tmp;
    int length;
    int status = 0;
    int options = WUNTRACED;
    string command;
    length = 0;
    cout << ">>";
    getline(cin, command);
    if (command == "logout")
    {
        cout << "wirklich beenden?y/n" << endl;
        cin>>tmp;
        if (tmp == "y")
        {
            exit(0);
        }else
            command="sleep 1 &";
    }
    length = count(command.begin(), command.end(), ' ') + 2;
    char *arg[length];
    stringstream str(command);
    do
    {
        str >> arg[i];
        i++;
    }
    while (length > (i + 1)&& !str.eof());
    arg[i] = NULL;
    pid_t pid = fork();
    string tmp4 = arg[length - 2];
    int flag = 1;
    if (tmp4 == "&")
    {
        flag = 0;
        arg[length - 2] = NULL;
    }
    if (pid == 0)
    {
        if (execvp(arg[0], arg) == -1)
        {
            perror("Befehl nicht gefunden...");
            exit(0);
        }
    }
    else
    {
        if (flag == 1)
        {
       //     cout << "Es wird gewartet..." << endl;
            waitpid(pid, &status, options);
        }
    }
}


