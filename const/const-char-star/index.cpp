#include <iostream>

using namespace std;

int main() {
    const char* a = "a";  // pointer value can change, but the value it points to cannot
    char const* b = "b";  // same as above
    char* const c = "c";  // read only variable is not assignable

    a = "aa";
    b = "bb";
    // c = "cc";

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    b = a;

    cout << b << endl;

    return 0;
}