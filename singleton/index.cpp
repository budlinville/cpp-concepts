#include <iostream>

using namespace std;

// could accomplish pretty much everything you want to do with a Singleton with a namespace
class Singleton {
	public:
		// do not allow copy constructor to be called
		Singleton(const Singleton&) = delete;
		static Singleton& get() { return s_instance; }
		int getNum() { return num; }
		void setNum(int n) { num = n; }
	private:
		int num;
		static Singleton s_instance;
		Singleton() {}
};

Singleton Singleton::s_instance;

int main() {
	// won't work, b/c will fire copy constructor, which we deleted
	//Singleton mySingleton = Singleton::get();

	Singleton& mySingleton = Singleton::get();
	mySingleton.setNum(5);

	Singleton& mySameSingleton = Singleton::get();
	cout << mySameSingleton.getNum() << endl;

	return 0;
}