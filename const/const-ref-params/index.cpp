#include <iostream>
#include <string>

using namespace std;

// Notice below that even though we are passing a const reference to the constructor,
// the object is still copied, because we ar assigning it to a new member variable.

template<typename T>
struct Foo {
    Foo() = delete;
    Foo(const T &_foo) { foo = _foo; }

    T foo;
};

struct Bar {
    Bar() {}
    Bar(int _bar) : bar(_bar) {}
    
    int bar = 0;
};

int main() {
    Bar b(6);
    Foo<Bar> f(b);

    cout << "Foo's bar: " << f.foo.bar << "; Bar: " << b.bar << endl;

    b.bar = 5;
    cout << "Foo's bar: " << f.foo.bar << "; Bar: " << b.bar << endl;

    return 0;
}