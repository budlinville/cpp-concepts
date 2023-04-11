#include <mutex>
#include <thread>

// mutex example
bool foo(std::mutex &m, auto* src) {
    std::lock_guard<std::mutex> lock { m };  // lock_guard is a RAII wrapper for mutexes
    const char * buffer;
    if (not src->readIntoBuffer(buffer)) {
        return false;
    }

    return true;
}

struct Bar {
    int b = 6;
};

// Smart pointer
bool bar () {
    std::unique_ptr<Bar> b { new Bar()};

    return true;
}

// std::jthread is a RAII wrapper for std::thread

// std::fstream is a RAII wrapper for std::ifstream and std::ofstream