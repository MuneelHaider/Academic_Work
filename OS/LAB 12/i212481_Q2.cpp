#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <semaphore.h>

#define NUM_CARBON_MOLECULES 2
#define NUM_OXYGEN_MOLECULES 6

using namespace std;

sem_t carbonSemaphore;
sem_t oxygenSemaphore;

mutex outputMutex;

void signalMolecules(sem_t &moleculeSemaphore, int count) {
    
    for (int i = 0; i < count; ++i) {
    
        sem_post(&moleculeSemaphore);
    }
}

void* scientistFunction(void *arg) {
    
    int researcherId = *(int *)arg;
    
    while (true) {
        {
            lock_guard<mutex> lock(outputMutex);
            cout << "Researcher " << researcherId << " is waiting for molecules to become available." << endl;
        }

        signalMolecules(carbonSemaphore, 2);
        signalMolecules(oxygenSemaphore, 6);

        this_thread::sleep_for(chrono::seconds(1));

        {
            lock_guard<mutex> lock(outputMutex);
            cout << "Researcher " << researcherId << " is creating a Carbon Dioxide molecule." << endl;
        }
    }
    
    return nullptr;
}

void* carbonFunction(void *arg) {
    
    long id = (long)arg;
    while (true) {
    
        sem_wait(&carbonSemaphore);
        {
            lock_guard<mutex> lock(outputMutex);
            cout << "Carbon molecule " << id << " is idle." << endl;
        }

        cout << "Carbon molecule " << id << " is signaling Researcher." << endl;

        this_thread::sleep_for(chrono::seconds(1));
    }
    
    return nullptr;
}

void* oxygenFunction(void *arg) {
    
    long id = (long)arg;
    while (true) {
    
        sem_wait(&oxygenSemaphore);
        {
            lock_guard<mutex> lock(outputMutex);
            cout << "Oxygen molecule " << id << " is idle." << endl;
        }

        cout << "Oxygen molecule " << id << " is signaling Researcher." << endl;

        this_thread::sleep_for(chrono::seconds(1));
    }

    return nullptr;
}

int main() {
    
    int durationSeconds;
    
    cout << "Enter the number of seconds the program will run: ";
    cin >> durationSeconds;

    sem_init(&carbonSemaphore, 0, 0);
    sem_init(&oxygenSemaphore, 0, 0);

    thread researchers[3];
    thread carbonAgents[NUM_CARBON_MOLECULES];
    thread oxygenAgents[NUM_OXYGEN_MOLECULES];

    int researcherIds[3] = {1, 2, 3};
    
    for (int i = 0; i < 3; i++) {
    
        researchers[i] = thread(scientistFunction, &researcherIds[i]);
    }

    for (long i = 0; i < NUM_CARBON_MOLECULES; i++) {
    
        carbonAgents[i] = thread(carbonFunction, (void *)i);
    }

    for (long i = 0; i < NUM_OXYGEN_MOLECULES; i++) {
    
        oxygenAgents[i] = thread(oxygenFunction, (void *)i);
    }

    this_thread::sleep_for(chrono::seconds(durationSeconds));

    for (auto &t : researchers) {
    
        t.detach();
    }

    for (auto &t : carbonAgents) {
    
        t.detach();
    }

    for (auto &t : oxygenAgents) {
    
        t.detach();
    }

    sem_destroy(&carbonSemaphore);
    sem_destroy(&oxygenSemaphore);

    return 0;
}
