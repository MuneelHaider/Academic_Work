#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

class BakeryLock {

public:
    
    int choosing[10];
    int number[10];
    
    mutex mutex1;

    BakeryLock() {
    
        for (int i = 0; i < 10; ++i) {
    
            choosing[i] = 0;
            number[i] = 0;
        }
    }

    void lock_acquire(int thread_id) {
    
        mutex1.lock();
    
        choosing[thread_id] = 1;
        int max = 0;
    
        for (int i = 0; i < 10; ++i) {
    
            int num = number[i];
            max = num > max ? num : max;
        }
    
        number[thread_id] = max + 1;
        choosing[thread_id] = 0;
    
        mutex1.unlock();

        for (int i = 0; i < 10; ++i) {

            if (i == thread_id) continue;

            while (choosing[i]) {}

            while (number[i] != 0 && (number[i] < number[thread_id] || (number[i] == number[thread_id] && i < thread_id))) {}
        }
    }

    void lock_release(int thread_id) {
        
        mutex1.lock();
        
        number[thread_id] = 0;
        
        mutex1.unlock();
    }
};

mutex print_mutex;

void synchronized_print(const string &message) {
    
    lock_guard<mutex> guard(print_mutex);
    cout << message;
}

struct ThreadArg {
    
    int thread_id;
    BakeryLock *lock;
};

void thread_func(ThreadArg *thread_arg) {
    
    int thread_id = thread_arg->thread_id;
    BakeryLock *lock = thread_arg->lock;

    synchronized_print("Thread " + to_string(thread_id) + " is waiting to acquire the lock...\n");
    lock->lock_acquire(thread_id);

    synchronized_print("Thread " + to_string(thread_id) + " has entered the critical section\n");
    this_thread::sleep_for(chrono::seconds(2));

    lock->lock_release(thread_id);
    synchronized_print("Thread " + to_string(thread_id) + " has released the lock and exited the critical section\n");
}

int main() {

    thread threads[10];
    ThreadArg args[10];
    
    BakeryLock lock;

    for (int i = 0; i < 10; ++i) {
    
        args[i].thread_id = i;
        args[i].lock = &lock;
        threads[i] = thread(thread_func, &args[i]);
    }

    for (int i = 0; i < 10; ++i) {
    
        threads[i].join();
    }

    return 0;
}