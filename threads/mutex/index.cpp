#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int myAmount = 0;
int myMutexAmount = 0;
std::mutex m;

void addMoney() {
	myAmount++;
}

void addMoneySafely() {
	m.lock();
	myMutexAmount++;
	m.unlock();
}

// unlike .lock(), .try_lock() is non-blocking... if a thread cannot obtain lock,
// it will skip over the mutex code and proceedAsNormal
// try_lock returns true if lock obtaines; false otherwise
int counter = 0;
std::mutex mtx2;
void demonstrateTryLock(int end) {
	for (int i = 0; i < end; i++) {
		if(mtx2.try_lock()) {
			++counter;
			mtx2.unlock();
		}
	}
}

int main() {
	thread t1(addMoney);
	thread t2(addMoney);

	t1.join();
	t2.join();

	// no guarantee this will be 2
	cout << myAmount << endl;

	thread t3(addMoneySafely);
	thread t4(addMoneySafely);

	t3.join();
	t4.join();

	// guaranteed to be 2
	cout << myAmount << endl;

	cout << "-----------" << endl;
	int end = 100000;
	std::thread t5(demonstrateTryLock, end);
	std::thread t6(demonstrateTryLock, end);

	t5.join();
	t6.join();

	cout << "Counter should be at " << 2 * (end - 1) << ", but is actually at " << counter << endl;

	return 0;
}