#include <string>
#include <vector>
#include <fstream>		// header for file input
#include <iostream>		// header for reading/writing to file

using namespace std;

int main() {
	ofstream myFile;
	myFile.open("tuna.txt");	// if file doesn't exist, will create one

	myFile << " hello " << endl;
	myFile.close();

	// Better way
	ofstream myOtherFile("salmon.txt");

	if (myOtherFile.is_open()) {
		cout << "File was indeed open" << endl;
	} else {
		cout << "Fuke was not open" << endl;
	}
	
	myOtherFile.close();
}