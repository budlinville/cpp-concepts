#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// If a base class has a pure virtual function, a derived class MUST implement that derived function

// interface (all pure virtual methods)
class Monster {
	public:
	virtual void roar() = 0;
	virtual void sleep() = 0;
};

class Dragon : public Monster {
	public:
	void roar(){ cout << "ARWRAWRA" << endl; }
	void sleep(){ cout << "Dragon slept 8 hours" << endl; }
};

// Abstract class... At least one virtual method
class MedievalPerson {
	public:
	virtual void payHomageToTheKing() { cout << "Wuzzgud king, you lookin real fly now, yahear?" << endl; }
	virtual void fight() = 0;
};

class King : public MedievalPerson {
	public:
	void payHomageToTheKing() { cout << "I'm the king and I'm lookin fly yo" << endl; }
	void fight() { cout << "I do not fight. I am the king" << endl; }
};

class Peasant : public MedievalPerson {
	public:
	void fight() { cout << "I fought. I died. I have no idea how I am communicating this information right now." << endl; }
};

class Knight : public MedievalPerson {
	public:
	void fight() { cout << "I killed like 8 peasant yo wtf this is mad fucked up." << endl; }
};

int main() {
	// will not work... cannot instantiate an interface
	//Monster monny;
	cout << "--- Dragon ---" << endl;
	Dragon draggy;
	draggy.roar();
	draggy.sleep();

	// also will not work cannot instantiate an abstract class
	//MedievalPerson medievalPersonny;

	cout << "--- King ---" << endl;
	King kingy;
	kingy.payHomageToTheKing();
	kingy.fight();

	cout << "--- Peasant ---" << endl;
	Peasant peasnty;
	peasnty.payHomageToTheKing();
	peasnty.fight();

	cout << "--- King ---" << endl;
	Knight knighty;
	knighty.payHomageToTheKing();
	knighty.fight();
	
	return 0;
}