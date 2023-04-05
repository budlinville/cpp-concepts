#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

int main() {
    // Thread 1
    std::mutex mtx;

    puts("(1) T1: T1 locking mutex");
    mtx.lock();                                 // (1) Lock mutex

    std::thread t2([&mtx]() {
        // Thread 2
        puts("(2) T2: Waiting for T1 to unlock mutex");
        mtx.lock();                             // (2) Pause until mutex is unlocked, then (5) lock it for this thread
        puts("(5) T2: T1 unlocked  mutex, T2 hs now locked it");

        mtx.unlock();                           // (6) Unlock mutex
        puts("(6) T2: T2 has unlocked mutex");
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    puts("(3) T1: T1 unlocking mutex");
    mtx.unlock();                               // (3) Unlock mutex
    
    puts("(4) T1: T1 waiting for T2 to finish");
    t2.join();                                  // (4) Wait for thread 2 to finish
}