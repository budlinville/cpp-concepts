#include <iostream>
#include <thread>

using namespace std;

static bool s_finished = false;

void doWork() {
	cout << "Started thread id=" << this_thread::get_id() << endl;

	while(!s_finished) {
		cout << "working..." << endl;
		// this_thread is similar to 'this' keyword. Gives you access to the current thread you are on
		std::this_thread::sleep_for(1s);
	}
}

int main() {

	std::thread worker(doWork);	// starts immediately

	cin.get();	// pause current thread until user presses enter
	s_finished = true;

	worker.join(); 	// lock the current thread until this other thread is finished

	cout << "Finished thread id=" << this_thread::get_id() << endl;

	return 0;
}