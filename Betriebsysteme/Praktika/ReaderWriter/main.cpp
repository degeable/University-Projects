/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: stud
 * Based on:https://github.com/angrave/SystemProgramming/wiki/Synchronization,-Part-7:-The-Reader-Writer-Problem
 * Created on 30. November 2017, 18:51
 */
#include <iostream>
#include <thread> // std::thread
#include <cstdlib>
#include <chrono>
#include  <vector>
#include <time.h>
#include <mutex>
#include <semaphore.h>
#include <sys/sem.h>
#include <sys/time.h>
#include <condition_variable>
#include <locale>
#include <unistd.h>
#include <csignal>
using namespace std;

/*
 * 
 */
vector<thread>r; //vector für reader...
vector<thread>w; // und für writer
vector<int>data; //Random Numbers
int dataSize;
int flag = 0; //fürs beenden
sem_t writing; // 1 oder 0, da nur ein Thread schreiben darf
sem_t reading; // o oder dataSize, da nur so viele Threads lesen sollen wie der vector plätze hat...
mutex m; //reader Lock für Ausgabe
mutex m1; //writer Lock fürs SChreiben

void signal_handler(int signum)
{
    flag = 1;
}

void dataInit(int size)
{
    int var = sem_init(&writing, 0, 1); //semaphore initialisieren
    int var2 = sem_init(&reading, 0, size);

    srand((unsigned) time(NULL));
    for (int i = 0; i < size; i++) //vector erste mal befüllen
    {
        data.push_back(i);

    }
    dataSize = size;
}

void reader()
{

    while (!flag)
    {

        sem_wait(&writing); //reader schaut ob jemand schreibt
        sem_post(&writing); //wenn nicht direkt wieder abgeben

        sem_wait(&reading); //reader lock

        int ran = rand() % dataSize;

        m.lock(); //mutex für ausgabe
        cout << "ReaderThreadID[" << std::this_thread::get_id() << "]at(" << ran << ")-> " << data.at(ran) << endl;
        m.unlock();

        sem_post(&reading); //reader unlock

        sleep(1);

    }
}

void writer()
{
    while (!flag)
    {
        sem_wait(&writing); //wrirting sem locken
        for (int i = 0; i < dataSize; i++)
            sem_wait(&reading); //warten bis alle Reader geblockt sind

        m1.lock(); //Writer mutex lock
        for (int i = 0; i < dataSize; i++)
        {
            data.at(i) = rand() % 1000;
            // cout << "[" << data.at(i) << "] "<<"at("<<i<<")" << endl;
        }
        cout << "WriterThreadID[" << std::this_thread::get_id() << "] done!" << endl;

        m1.unlock();

        for (int i = 0; i < dataSize; i++)
            sem_post(&reading); //alle reader wieder freigeben

        sem_post(&writing); //writing wieder freigeben

        sleep(1);
    }
}

int main(int argc, char** argv)
{
    int read = 0;
    int write = 0;
    int sze = 0;
    cout << "Size: ";
    cin>>sze;
    dataInit(sze);
    cout << "Reader: ";
    cin>>read;
    cout << "Writer: ";
    cin>>write;

    signal(SIGINT, signal_handler);

    for (int i = 0; i < write; i++)
        w.push_back(thread(writer));

    for (int i = 0; i < read; i++)
        r.push_back(thread(reader));

    for (int i = 0; i < write; i++)
        w.at(i).join();

    for (int i = 0; i < read; i++)
        r.at(i).join();

    return 0;
}








//void writer();
//void reader();
//vector<int> buffer;
//int size = 5;
//mutex m1;
//mutex m2;
//condition_variable sema;
//sem_t semaphore;
// 
//vector<thread>waitingWriters;
//vector<thread>waitingReaders;
//
//int main(int argc, char** argv)
//{
//    m2.unlock();
//    thread t1(writer);
//    std::this_thread::sleep_for(std::chrono::milliseconds(500));
//    thread t2(reader);
//    thread t3(writer);
//    thread t4(reader);
//    thread t5(writer);
//    thread t6(writer);
//    t1.join();
//    t2.join();
//    t3.join();
//    t4.join();
//    t5.join();
//    t6.join();
//
//
//    return 0;
//}
//
//void writer()
//{
//
//
//    if (m1.try_lock())
//    {
//       
//        for (int i = 0; i < size; i++)
//        {
//            buffer.insert(buffer.begin() + i, random()%100);
//        }
//     cout<<"WriterThread: ["<<std::this_thread::get_id()<<"]"<<"hat geschrieben\n";
//        m1.unlock();
//   
//    }
//    else
//    {
//      
//        cout << "Kritischer Abschnitt bereits gelockt\n";
//    }
//
//}
//
//void reader()
//{
//
// 
//
//
//}


//// thread example
//#include <iostream>       // std::cout
//#include <thread>         // std::thread
// 
//void foo() 
//{
//  // do stuff...
//}
//
//void bar(int x)
//{
//  // do stuff...
//}
//
//int main() 
//{
//  std::thread first (foo);     // spawn new thread that calls foo()
//  std::thread second (bar,0);  // spawn new thread that calls bar(0)
//
//  std::cout << "main, foo and bar now execute concurrently...\n";
//
//  // synchronize threads:
//  first.join();                // pauses until first finishes
//  second.join();               // pauses until second finishes
//
//  std::cout << "foo and bar completed.\n";
//
//  return 0;
//}