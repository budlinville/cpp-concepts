// Run with g++ -pthread threads.cpp && ./a.out

#include <iostream>
#include <list>
#include <thread>

using namespace std;


list<int> g_data;
const int SIZE = 50000000;

void simulateDownload(const std::string &filename) {
    cout << "[Downloader] Downloading " << filename << "..." << endl;
    for (int i=0; i < SIZE; i++) {
        g_data.push_back(i);
    }
    cout << "[Downloader] Download complete." << endl;
}

int main() {
    bool joinable = true;
    std::string filename { "test.mp4" };

    cout << "[main] user started an operation" << endl;
    std::thread thDownloader(simulateDownload, filename);

    // Detach the thread from the main thread. This means that the main thread will not wait for the detached thread to finish before exiting.
    if (!joinable)
        thDownloader.detach();

    cout << "[main] user started another operation" << endl;

    if (thDownloader.joinable()) {  // Check if the thread is joinable before joining it
        thDownloader.join();        // Must invoke this to be sure the thread finishes before the program exits (if it is a joinable thread)
    }

    return 0;
}