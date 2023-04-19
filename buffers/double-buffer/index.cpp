#include <random>
#include <semaphore.h>
#include <thread>
#include <vector>

// Doesn't work

// Function for creating data
void generate_data(std::vector<int> data) {
    // Create random number generator
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    // Generate random data
    for (auto &val : data) {
        val = dist(mt);
    }
}

// Function for processing data
void process_data(std::vector<int> data) {
    for (int i = 0; i < 5; i++) {
        for (auto &val : data) {
            val %= val + 1;
        }
    }
}

int main() {
    // Create std::vector passes between generating/processing threads
    std::vector<int> data_1;
    std::vector<int> data_2;
    data_1.resize(1 << 20);     // 2^20 total elements
    data_2.resize(1 << 20);     // 2^20 total elements

    // Semaphores for coordinating work
    sem_t signal_to_process;
    sem_t signal_to_generate;

    sem_init(&signal_to_process, 0, 0);
    sem_init(&signal_to_generate, 0, 1);

    // Number of iterations to perform
    const int num_iterations = 100;

    // Work function for generating data
    auto data_generator = [&]() {
        // Run for 100 iterations
        for (int i =0; i < num_iterations; i++) {
            // Generate data
            generate_data(data_1);

            // Wait until currnet processing work is done
            sem_wait(&signal_to_generate);

            // Swap the vectors
            data_1.swap(data_2);

            // Signal the processing thread to begin
            // While our generating thread moves to next iteration,
            // processing thread can begin work on current iteration
            sem_post(&signal_to_process);
        }
    };

    // Work function for processing data
    auto data_processor = [&]() {
        // Run for 100 iterations
        for (int i =0; i < num_iterations; i++) {
            // Wait until data is ready to be processed
            sem_wait(&signal_to_process);

            // Process data
            process_data(data_2);

            // Signal the generating thread to begin
            sem_post(&signal_to_generate);
        }
    };

    // Spawn our two threads
    std::thread generator(data_generator);
    std::thread processor(data_processor);

    generator.join();
    processor.join();

    return 0;
}