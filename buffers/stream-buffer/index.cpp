// IO in charge of the following:
// * Formatting data (accomplished through "stream")
// * Communicating data to external devices (accomplished through a "stream buffer", which is itself an internal module of stream)

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << 34 << endl;
    // Get pointer to cout's stream buffer
    streambuf* pbuf = cout.rdbuf();  // This buffer is in charge of transmitting data to stdout

    ostream myCout(pbuf);  // Create a new ostream object that uses cout's stream buffer
    myCout << "Hello world" << endl;

    // Can manipulate this stream object just like cout
    myCout.setf(ios::showpos);
    myCout.width(20);  // Set width to 20 characters (right adjusted by default)
    myCout << 34 << endl;

    // Can assign a different stream buffer to the stream object (Redirecting)
    ofstream of("log.txt");
    myCout.rdbuf(of.rdbuf());  // Assign of's stream buffer to myCout
    cout << "Hello" << endl;  // This will be written to log.txt

    // Stream buffer iterator
    istreambuf_iterator<char> i(cin);
    ostreambuf_iterator<char> o(cout);

    // Copy values from input buffer to output buffer until 'x' is encountered
    while (*i != 'x') {
        *o = *i;
        ++o;
        ++i;
    }
}
