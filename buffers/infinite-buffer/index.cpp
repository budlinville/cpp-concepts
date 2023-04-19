#include <iostream>
#include <stdlib.h>

using namespace std;

#define BUFFER_SIZE 3

int main() {
    // Simple approach
    int buffer[BUFFER_SIZE];
    for (int i=0; i < BUFFER_SIZE; i++) {
        cout << "Enter: ";
        cin >> buffer[i];
    }

    double sum = 0;
    for (int i=0; i < BUFFER_SIZE; i++) {
        sum += buffer[i];
    }

    cout << "Average is: " << sum / BUFFER_SIZE << endl;


    // Infinite buffer
    // This was stupid and obvious in C++... Didn't finish the video or this file
    int size = 2;
    int* buffer = new int(size);

    int input = 0;
    int num_data = 0;
    while (true) {
        cout << "Enter (-1 to quit): ";
        cin >> input;
        if (input == -1) {
            break;
        } else {
            buffer[num_data] = input;
            num_data++;
            if (num_data == size) {
                // Resize buffer
                size *= 2;
                int* new_buffer = new int(size);
                for (int i=0; i < num_data; i++) {
                    new_buffer[i] = buffer[i];
                }
                delete[] buffer;
                // buffer = new_buffer;
            }
        }
    }
}