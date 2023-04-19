#include <iostream>

using namespace std;

// NOTE: Strings are expensive to copy (string literal allocaed on heap), so pass by reference
void copy_and_print(const string& s) {
    cout << "copy_and_print: " << s << endl;
}

int main() {
    string s = "bud";  // string literal = "bud\0" of type const char*
                       // Note the const-ness => immutable

    cout << "s.size(): " << s.size() << endl;       // 3 shown characters (each 1 byte)
    cout << "s.capacity(): " << s.capacity() << endl;   // 15 available characters (+1 for null terminator = 16)

    copy_and_print(s);

    // Get underlying string literal
    const char* c = s.c_str();
    cout << "As string literal: " << c << endl;

    // While string literals are immutable, you can still modify the underlying string literal
    // That is to say, you can modify the characters in the string, but the characters themselves are immutable
    // _OR_ const char* ... not char* const (The constness refers to the individual characers, not the entire string)
    // Note that would not work
    // char* const a = "abc";
    // a[0] = 'd';  // Error: assignment of read-only location '*(const char*)a
    

    // Same as c_str(), but returns a non-const char* (mutable)
    cout << "s.data(): " << s.data() << endl;

    // Iterating through string
    cout << "Iterating through string: ";
    for (auto element : s){
        cout << element << '-';
    }
    cout << endl;


    // Substring
    cout << "Substring: " << s.substr(1, 2) << endl;  // start at index 1, length 2

    // String find
    if (s.find("ud") != -1) { // Could also use string::npos for comparison
        cout << "Found 'ud' in string" << endl;
    } else {
        cout << "Did not find 'ud' in string" << endl;
    }

};