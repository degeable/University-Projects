#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>
#include <time.h>
#include<stdio.h>
#include <signal.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include<semaphore.h>
#include <mutex>
#include <unistd.h>
#include <map>
/*
 *
 */

using namespace std;

vector<thread> m_readers;
sem_t lock_readers = sem_t();
pthread_mutex_t m_printMutex = PTHREAD_MUTEX_INITIALIZER;
vector<thread> m_writers;
sem_t writing = sem_t();
pthread_mutex_t m_mutex = PTHREAD_MUTEX_INITIALIZER;

vector<int> buffer;
map<thread::id,unsigned int> reader_id;
map<thread::id,unsigned int> writer_id;

void writer_function();
void reader_function();
void sigint_handler(int s);

bool stopping = false;
bool writingPending = false;
int int_readers;

int main(int argc, char** argv) {
    
    srand((unsigned) time(NULL));
    
    
    signal(SIGINT, sigint_handler);
    
    string size;
    string n_readers;
    string n_writers;
    if (argc == 4) {
        size = argv[1];
        n_readers = argv[2];
        n_writers = argv[3];
    } else {
        std::cout << "Input: Data-Size, Number of Reader, Number of Writer\n";
        return 1;
    }
    
    int int_size = stoi(size);
    int_readers = stoi(n_readers);
    int int_writers = stoi(n_writers);
    
    for (int i = 0; i < int_size; i++) {
        buffer.push_back(rand() % 1000);
    }
    
    //Vorbereiten der semaphore
    for (int i = 0; i < buffer.size(); i++) //reader semaphore auf die anzahl der readers bringen
        sem_post(&lock_readers);
    sem_post((&writing)); //writing darf nur 1 sein!
    
    //erstellen der threads nach gegebener anzahl an elementen
    for (int i = 0; i < int_readers; i++){
        m_readers.push_back(thread(reader_function));
        reader_id.insert({m_readers.at(i).get_id(),i});
    }
    
    for (int i = 0; i < int_writers; i++){
        m_writers.push_back(thread(writer_function));
        writer_id.insert({m_writers.at(i).get_id(),i});
    }
    
    
    //Zusammenführen der einzelnen threads vor return 0;
    for (int i = 0; i < int_readers; i++)
        m_readers.at(i).join();
    
    for (int i = 0; i < int_writers; i++)
        m_writers.at(i).join();
    
    sem_destroy(&writing);
    sem_destroy(&lock_readers);
    return 0;
}

void writer_function() {
    while (!stopping) {
        
        sem_wait(&writing); //der einzige der schreiben will
        //jetzt alle reader blockieren
        for (int i = 0; i < buffer.size(); i++) //holt sich suggzesiv mit entsprechenden wartepausen alle reader locks, da diese fertig sein müssen bis geschrieben werden kann
            sem_wait(&lock_readers);
        
        pthread_mutex_lock(&m_mutex);
        
        //cout << " writer begin " << endl;
        
        for(int i = 0; i < buffer.size(); i++)
            buffer.at(i) = rand()%1000;
        
        //sleep(1);
        
        //cout << " writer finished " << endl;
        
        pthread_mutex_unlock(&m_mutex);
        
        //alle reader wieder freigeben
        for (int i = 0; i < buffer.size(); i++)
            sem_post(&lock_readers);
        sem_post(&writing);
        
        sleep(1);
    }
}

void reader_function() {
    
    while (!stopping) {
        
        //pthread_mutex_lock(&m_mutex);
        sem_wait(&writing); //überprüfen ob gerade jemand schreibt dann warten bis fertig
        sem_post(&writing); //den semaphor direkt wieder erhöhen da die anderen nicht auf diesen reader warten dürfen müssen
        //pthread_mutex_unlock(&m_mutex);
        
        sem_wait(&lock_readers); //decrementiert den reader lock um eins.
        
        //cout << " reader begin " << endl;
        
        int pos = rand()%buffer.size();
        pthread_mutex_lock(&m_printMutex);
        cout << "reader nr.: " << reader_id.at(this_thread::get_id()) << " value at [" << pos << "] = " << buffer.at(pos) << endl;
        pthread_mutex_unlock(&m_printMutex);
        
        //sleep(1);
        
        //cout << " reader finished ";
        
        
        sem_post(&lock_readers);
        
        sleep(1);
    }
}

void sigint_handler(int s) {
    
    stopping = true;
    
    
}

