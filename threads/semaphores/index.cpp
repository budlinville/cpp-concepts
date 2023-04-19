// Semaphores are more flexible than mutexes. Any thread can call wait()
// to acquire the semaphore, and any thread can call post() to release the semaphore.
// This is useful for situations where you want to limit the number of threads
// that can access a resource at a time. For example, if you have a function that
// can only be called by 5 threads at a time, you can use a semaphore to limit the
// number of threads that can call the function at a time.

// Often used in the producer-consumer problem.

#include <iostream>
#include <semaphore.h>
#include <vector>
#include <thread>

using namespace std;


int NUM_SHARED_ITEMS = 100;
int ITEM_SIZE = sizeof(int);
int SHAREDMEM_SIZE = NUM_SHARED_ITEMS * ITEM_SIZE;


void reader(sem_t *sem, int *shared_memory, int index) {
    sem_wait(sem);
    cout << shared_memory[index * ITEM_SIZE] << endl;
    sem_post(sem);
}

void writer(sem_t *sem, int *shared_memory, int index) {
    sem_wait(sem);
    shared_memory[index * ITEM_SIZE] = index;
    sem_post(sem);
}


int main() {
    sem_t sem;
    char shared_memory[SHAREDMEM_SIZE];
    vector<thread> writer_threads;
    vector<thread> reader_threads;

    for (int i = 0; i < NUM_SHARED_ITEMS; i++) {
        thread myThread(writer, sem, (int *)shared_memory, i);
        writer_threads.push_back(move(myThread));
    }

    for (int i = 0; i < NUM_SHARED_ITEMS; i++) {
        thread myThread(reader, sem, (int *)shared_memory, i);
        reader_threads.push_back(move(myThread));
    }

    for (int i = 0; i < NUM_SHARED_ITEMS; i++) {
        writer_threads[i].join();
        reader_threads[i].join();
    }

}