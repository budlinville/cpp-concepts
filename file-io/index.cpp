#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string steveQuote = "A day without sunshine is like, you know, night";

	ofstream writer("stevequote.txt");

	if (!writer) {
		cout << "Error opening file" << endl;
		return -1;
	} else {
		writer << steveQuote << endl;
		writer.close();
	}

	// ios:app => Opens a stream to append to what's there
	// ios:binary => Treat the file as binary
	// ios:in => Open a file to read input
	// ios::trunc => Default => Open a file to overwrite existing conten
	// ios::out => Open a file to write output
	// ios::ate => Opens a file to write output, starting at the end of the file

	ofstream writer2("stevequote.txt", ios::app);

	if (!writer2) {
		cout << "Error opening file" << endl;
		return -1;
	} else {
		writer2 << "\n - Steve Martin" << endl;
		writer2.close();
	}

	char letter;
	ifstream reader("stevequote.txt");

	if (!reader) {
		cout << "Error opening file" << endl;
		return -1;
	} else {
		for (int i = 0; !reader.eof(); i++) {
			reader.get(letter);
			cout << letter;
		}

		cout << endl;
		reader.close();
	}

	return 0;
}