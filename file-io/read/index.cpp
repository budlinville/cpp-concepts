#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	ifstream myFile("players.txt");

	int id;
	string name;
	double money;

	// looping through a file of structured data is super easy
	// how does loop end though? When ifstream gets to the eof,
	// it returns a nullptr, so the below line of code looks like
	// while (nullptr)
	// which is basically while (false)
	while (myFile >> id >> name >> money) {
		cout << id << ", " << name << ", " << money << endl;
	}

	// Also, when eof is reached, C++ knows to close the file,
	// so we do not have to do it manually

	ifstream sameFile("players.txt");	// Open new file stream.. old one was closed
	string line;	// file lines saved here
	// Reading files line by line
	while (std::getline(sameFile, line)) {
		// don't need c_str here b/c just printing to screen, but this
		// will convert to string which would be helpful in real program
		cout << line.c_str() << endl;
	}

	return 0;
}