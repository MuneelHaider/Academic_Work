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
    cout << "Thread 1 ID: " << this_thread::get_id() << " Counter value: " << counter << endl;
    mutex1.unlock();
}

void functionB() {

    int b;
    mutex1.lock();
    b = counter;
    b++;
    counter = b;
    cout << "Thread 2 ID: " << this_thread::get_id() << " Counter value: " << counter << endl;
    mutex1.unlock();
}

int main() {
    mutex1.lock();
    thread1 = thread(functionA);
    thread2 = thread(functionB);
    cout << "Thread 1 ID: " << thread1.get_id() << endl;
    cout << "Thread 2 ID: " << thread2.get_id() << endl;
    mutex1.unlock();

    thread1.join();
    thread2.join();

    mutex1.lock();
    mutex1.unlock();
    return 0;
}