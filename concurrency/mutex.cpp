// Run with g++ -pthread threads.cpp && ./a.out

#include <iostream>
#include <list>
#include <thread>
#include <mutex>

using namespace std;


list<int> g_data;
const int SIZE = 5000000;
std::mutex g_mutex;


void simulateDownload(bool useMutex) {
    for (int i=0; i < SIZE; i++) {
        if (useMutex) g_mutex.lock();
        g_data.push_back(i);
        if (useMutex) g_mutex.unlock();
    }
}

void simulateDownload2(bool useMutex) {
    for (int i=0; i < SIZE; i++) {
        if (useMutex) g_mutex.lock();
        g_data.push_back(i);
        if (useMutex) g_mutex.unlock();
    }
}

int main() {
    std::thread thDownloader1(simulateDownload, false);
    std::thread thDownloader2(simulateDownload2, false);


    thDownloader1.join();
    thDownloader2.join();
    
    cout << "[main] Expected : " << SIZE * 2 << endl;
    cout << "[main] Actual   : " << g_data.size() << endl;
    cout << "[main] BAD! race condition" << endl;

    //--------------------------------------------------------------

    g_data.clear();

    std::thread thDownloader3(simulateDownload, true);
    std::thread thDownloader4(simulateDownload2, true);

    thDownloader3.join();
    thDownloader4.join();
    
    cout << "[main] Expected : " << SIZE * 2 << endl;
    cout << "[main] Actual   : " << g_data.size() << endl;
    cout << "[main] GOOD! mutex used" << endl;

    return 0;
}