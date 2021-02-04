#include <thread>
#include <iostream>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull oddCount;
ull evenCount;

void getNumOdds(ull start, ull end) {
	ull count = 0;
	for (ull i = start; i <= end; i++) {
		if (i % 2 == 1) {
			oddCount ++;
		}
	}
}

void getNumEvens(ull start, ull end) {
	ull count = 0;
	for (ull i = start; i <= end; i++) {
		if (i % 2 == 0) {
			evenCount ++;
		}
	}
}

int main() {
	ull start = 0; ull end = 1900000000;

	auto startTime = high_resolution_clock::now();

	getNumOdds(start, end);
	getNumEvens(start, end);

	auto endTime = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(endTime - startTime);

	cout << "Odds: " << oddCount << endl;
	cout << "Evens: " << evenCount << endl;
	cout << "(took " << duration.count()/1000000 << " seconds)" << endl;

	cout << "----- Now with threading -----" << endl;
	
	auto startTime2 = high_resolution_clock::now();

	thread oddThread(getNumOdds, start, end);
	thread evenThread(getNumEvens, start, end);

	oddThread.join();
	evenThread.join();

	auto endTime2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(endTime2 - startTime2);

	cout << "(took " << duration2.count()/1000000 << " seconds)" << endl;

	return 0;
}