#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(){
	/****************************
	 * 		Basics
	 * **************************/
	cout << "Hello World" << endl;

	const double PI = 3.1415926535;

	char myGrade = 'A';

	bool isHappy = true;

	int myAge = 39;

	// accurate to 6 decimal places
	float favNum = 89.89;

	// accurate up to 15 digits in length
	double otherFavNum = 1.72193712937912;

	cout << "Favorite Number: " << favNum << endl;

	/* Other types: 
		short int: at least 16 bits
		long int: at least 32 bits
		long long int at least 64 bits
		unsigned int: same size as signed version
		long double: not less than double
	*/

	// get number of bytes for a variable
	cout << "Size of int " << sizeof(myAge) << endl;
	cout << "Size of char " << sizeof(myGrade) << endl;
	cout << "Size of double " << sizeof(PI) << endl;
	cout << "Size of bool " << sizeof(isHappy) << endl;

	short int si = 2222;
	cout << "Size of short int " << sizeof(si) << endl;

	int largestInt = 2147483647;
	cout << "Largest int " << largestInt << endl;

	int five1 = 5;
	cout << "5++ = " << five1++ << "; five = " << five1 << endl;
	int five2 = 5;
	cout << "++5 = " << ++five2 << "; five = " << five2 << endl;
	int five3 = 5;
	cout << "5-- = " << five3-- << "; five = " << five3 << endl;
	int five4 = 5;
	cout << "--5 = " << --five4 << "; five = " << five4 << endl;

	int five = 5;
	int ten = five += 5;
	cout << "five += 5: " << ten << endl;

	/* ORDER OF OPERATION: 
		* and /
		then + and -
	*/

	// Primitive type casting
	cout << "4 / 5: " << (float) 4/5 << endl;

	/****************************
	 * 		Conditionals
	 * 					+
	 * Boolean/Logical Operators
	 * **************************/
	int age = 70;
	int ageAtLastExam = 16;
	bool isNotIntoxicated = true;
	if (age >= 0 && age < 16) {
		cout << "You should not drice..." << endl;
	} else if (!isNotIntoxicated){
		cout << "You should not drice..." << endl;
	} else if (age >= 80 && (age > 100 || age - ageAtLastExam > 5)) {
		cout << "You should not drice..." << endl;
	} else {
		cout << "Go ahead and drive" << endl;
	}

	// case statement
	int greetingOption = 2;
	switch (greetingOption) {
		case 1:
			cout << "bonjour" << endl;
			break;
		case 2:
			cout << "hola" << endl;
			break;
		case 3:
			cout << "hallo" << endl;
			break;
		default:
			cout << "hello" << endl;
			break;
	}

	// ternary
	int largestNum = 5 > 2 ? 5 : 2;

	/****************************
	 * 		Arrays
	 * **************************/
	int myFavNums[5];

	int badNums[5] = {4, 13, 14, 24, 34};

	cout << "Bad Number 1: " << badNums[0] << endl;

	char letters[5][5] = {
		{'a', 'b', 'c', 'd', 'e'},
		{'f', 'g', 'h', 'i', 'j'},
		{'k', 'l', 'm', 'n', 'o'},
		{'p', 'q', 'r', 's', 't'},
		{'u', 'v', 'w', 'x', 'y'}
	};

	cout << letters[0][1] << endl;

	letters[3][2] = 'z';

	cout << letters[3][2] << endl;

	/****************************
	 * 		Loops
	 * **************************/
	for (int i=0; i <= 9; i++) {
		cout << i << endl;
	}

	for (int i=0; i <= 5; i++) {
		for (int j=0; j <= 5; j++) {
			cout << letters[i][j];
		}
		cout << endl;
	}

	// Get random number
	int min = 1;
	int max = 20;
	int randNum = (rand() % max) + min;
	while (randNum != max) {
		cout << randNum << ", ";
		randNum = (rand() % max) + min;
	}
	cout << endl;

	// simulate for with while
	int index = 0;
	while (index < 10) {
		cout << index++;
	}
	cout << endl;

	/****************************
	 * 		User Input
	 * **************************/
	string numGuessed = "";
	int intNumGuessed = 0;
	do {
		cout << "Guess between 1 and 10 (its 4): ";
		getline(cin, numGuessed);
		intNumGuessed = stoi(numGuessed);
		cout << intNumGuessed << endl;
	} while (intNumGuessed != 4);
	cout << "You win!" << endl;
	
	/****************************
	 * 		Strings
	 * **************************/
	// strings in c were character arrays ending with \0
	char happyArray[6] = {'H', 'a', 'p', 'p', 'y', '\0'};

	string birthdayString = "birthday";

	cout << happyArray + birthdayString << endl;

	string someStringNum = "5";
	cout << "string: " << someStringNum << "; double: " << stod(someStringNum) << "; int: "
		<< stoi(someStringNum) << "; int again: " << (int) stod(someStringNum) << endl;


	string uselessString = "abcdefgh";
	cout << "size: " << uselessString.size() << endl;
	cout << "Is string empty: " << uselessString.empty() << endl;
	cout << uselessString.append(" is a really useless string!") << endl;

	// == DOES work for strings
	// s.compare(t) will return 0 if s == t
	// -1 if s < t
	// 1 if s > t
	string a1 = "a";
	string a2 = "a";
	string b = "b";
	cout << "a1 == a2: " << (a1 == a2) << endl;
	cout << "a1.compare(a2): " << (a1.compare(a2)) << endl;
	cout << "a.compare(b): " << (a1.compare(b)) << endl;
	cout << "b.compare(a): " << (b.compare(a1)) << endl;

	// assign a new value to a string
	string yourName = "bud";
	string yourAssignedName = yourName.assign("aubrey");
	// these will be equal
	cout << "yourName: " << yourName << endl;
	cout << "yourAssignedName: " << yourAssignedName << endl;

	// substrings with assign
	string fullName = "Aubrey Bud Linville";
	string middleName = fullName.substr(7, 3);
	cout << "middle name: " << "|" << middleName << "|" << endl;

	// substring with assign.. will mutate original value
	string firstName = fullName.assign(fullName, 0, 6);
	cout << "fullName: " << fullName << "; firstName: " << "|" << firstName << "|" << endl;

	// find word in string
	string sentence = "This is some random writing, cha' feel?";
	int posOfRandom = sentence.find("random", 0);	// 0 is optional
	cout << "Position of 'random' in sentence: " << posOfRandom << endl;

	// insert
	sentence.insert(13, "really ");
	cout << "Updated sentence: " << sentence << endl;

	string name = "Aubrey Bud Linville";
	name.replace(7, 3, "Maximus");
	cout << "new name: " << name << endl;

	/****************************
	 * 		Vectors
	 * **************************/
	vector <int> lotteryNumVect(10);
	int lotteryNumArray[5] = {4, 13, 14, 24, 34};
	// TODO : I don't understand the paramaters to insert... what is the point of the second paramater?
	//lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray+3);
	cout << lotteryNumVect.at(3) << endl;

	lotteryNumVect.insert(lotteryNumVect.begin()+5, 44);
	cout << lotteryNumVect.at(5) << endl;

	lotteryNumVect.push_back(64);
	cout << "Final Value: " << lotteryNumVect.back() << endl;
	// pop_back will get back and pop it
	cout << "First Value: " << lotteryNumVect.front() << endl;
	cout << "Vector Size: " << lotteryNumVect.size() << endl;
	cout << "Last value (accessed directly): " << lotteryNumVect.at(lotteryNumVect.size() - 1) << endl;

	return 0;
}
