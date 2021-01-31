#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/*
 * Macro Operators
 * 		#		: causes a replacement-text token to be converted to a string surrounded by quotes
 * 		##	: used to concatenate two tokens
 * 
 * Built-in C++ Macros:
 * 		__LINE__ :	current line number of the program when it is being compiled
 * 		__FILE__ :	current file name of the program when it is being compiled
 * 		__DATE__ :	contains a string of the form month/day/year that is the date
 * 								of the translation of the source file into object code
 * 		__TIME__ :	contains a string of the form hour:minute:second that is the
 * 								time at which the program was compiled
 * 		etc.		 :	There are more, but these seem to be the basics..
 */

#define MKSTR( x ) #x
#define CONCAT_ERROR( a, b, c, d, e, f, g, h ) a ## b ## c ## d ## e ## f ## g ## h

#define NUMERATOR 5
#define DENOMINATOR 0	// set to 0 to see the magic

using namespace std;

double divide(int num, int denom) {
	if (DENOMINATOR == 0) {
		cout << "Error occurred in " << __FILE__ << " near line " << __LINE__ << " on " << __DATE__ << " at " << __TIME__ << endl;
		return -1;
	} else {
		// Side-note: this does NOT calculate (double)(num/denom)
		// Rather it calculates ((double) num) / denom
		// a double divided by an int returns a double
		// (double)(num/denom) would return 2.0
		return (double) num / denom;
	}
}

int main() {
	double result = divide(NUMERATOR, DENOMINATOR);
	if (result != -1) {
		cout << "Result is " << result << endl;
	}
	return 0;
}