// Run with g++ -pthread threads.cpp && ./a.out

#include <iostream>
#include <list>
#include <thread>
#include <mutex>

using namespace std;


list<int> g_data;
const int SIZE = 5000000;
std::mutex g_mutex;


void simulateDownload() {
    for (int i=0; i < SIZE; i++) {
        std::lock_guard<std::mutex> guard{g_mutex};
        if (i == 50) return;  // Simulate an error... Would result in deadlock if we didn't use lock_guard
        g_data.push_back(i);
    }
}

void simulateDownload2() {
    for (int i=0; i < SIZE; i++) {
        std::lock_guard<std::mutex> guard{g_mutex};
        g_data.push_back(i);
    }
}

int main() {
    std::thread thDownloader1(simulateDownload);
    std::thread thDownloader2(simulateDownload2);


    thDownloader1.join();
    thDownloader2.join();
    
    cout << "[main] size : " << g_data.size() << endl;

    return 0;
}