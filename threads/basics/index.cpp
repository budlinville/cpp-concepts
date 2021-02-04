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

	/*
		There is also .detach() which functions like .join() in that it creates a seperate thread of execution
		It differs though, because join creates a C++ thread object that is linked to the OS thread.
		When the OS thread is finished, we are aware of it. 

		.detach(), on the other hand, just detaches the thread , then C++ forgets about it
		If we need to know when a thread is finished executing, do not use .detach()
	*/

	cout << "Finished thread id=" << this_thread::get_id() << endl;

	return 0;
}