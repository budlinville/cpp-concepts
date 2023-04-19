// Run with g++ -pthread threads.cpp && ./a.out

#include <iostream>
#include <thread>
#include <future>

using namespace std;


int Operation(int count) {
    using namespace std::chrono_literals;

    int sum{};

    for (int i=0; i < count; ++i) {
        sum += i;
        cout << ". ";
        std::this_thread::sleep_for(300ms);  // std::chrono::seconds(1)
    }
    cout << endl;

    return sum;
}

int main() {
    using namespace std::chrono_literals;

    std::launch async_policy = std::launch::async;        // asynchronous
    std::launch deferred_policy = std::launch::deferred;    // synchronous

    /*****************************************************
     * std::launch::async
     * Gives something like:
     *   . . . . [main] threading continues execution...
     *   . . . . . . 
     *   [main] sum = 45
    ******************************************************/

    std::future<int> result = std::async(async_policy, Operation, 10);
    std::this_thread::sleep_for(1s);
    cout << "[main] threading continues execution..." << endl;
    
    if (result.valid()) {
        auto sum = result.get();
        cout << "[main] sum = " << sum << endl;
    }

    /*****************************************************
     * std::launch::deferred
     * Gives something like:
     *   [main] threading continues execution...
     *   . . . . . . . . . . 
     *   [main] sum = 45
    ******************************************************/
    std::future<int> result2 = std::async(deferred_policy, Operation, 10);
    std::this_thread::sleep_for(1s);
    cout << "[main] threading continues execution..." << endl;
    
    if (result2.valid()) {
        auto sum = result2.get();
        cout << "[main] sum = " << sum << endl;
    }


    return 0;
}