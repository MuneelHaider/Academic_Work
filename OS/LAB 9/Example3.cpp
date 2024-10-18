#include <iostream>
#include <cstdlib>
#include <thread>
#include <mutex>

using namespace std;

mutex mutex1;
thread thread1, thread2;
int counter = 0;

void functionA() {
    int a;
    mutex1.lock();
    a = counter;
    a--;
    counter = a;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Thread " << this_thread::get_id() << " Counter value: " << counter << endl;
    mutex1.unlock();
}

void functionB() {
    int b;
    int mycount = 0;
    while (mutex1.try_lock() != 0) {
        while (mycount <= 800000) {
            mycount++;
        }
        mycount = 0;
        cout << "Trying to own lock" << endl;
    }
    b = counter;
    b++;
    counter = b;
    cout << "Thread " << this_thread::get_id() << " Counter value: " << counter << endl;
    mutex1.unlock();
}

int main() {
    mutex1.lock();
    thread1 = thread(functionA);
    thread2 = thread(functionB);
    cout << "Thread " << thread1.get_id() << endl;
    cout << "Thread " << thread2.get_id() << endl;
    mutex1.unlock();

    thread1.join();
    thread2.join();

    mutex1.lock();
    mutex1.unlock();
    return 0;
}