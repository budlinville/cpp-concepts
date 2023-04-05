#include <iostream>

using namespace std;

struct Foo {
    Foo() { cout << "Constructing" << endl; };
    Foo(int foo) {
        cout << "Constructing element "
             << foo
             << " at buffer index "
             << sizeof(this) * foo
             << endl;
    };

    ~Foo() { cout << "Destructing" << endl; };
};

int main() {
    // Normal case
    cout << "Normal case" << endl;
    Foo * a = new Foo();
    delete a;

    cout << "------------------" << endl;

    // Placement new
    const int NUM_ELEMENTS = 3;

    // 1st approach
    cout << "Placement new (1st approach)" << endl;
    char *buffer = new char[NUM_ELEMENTS * sizeof(Foo)];

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        Foo *obj = new (&buffer[i * sizeof(Foo)]) Foo(i);
        obj->~Foo();
    }

    delete[] buffer;

    // 2nd approach
    // Notice that we don't need manually call the destructor
    cout << "Placement new (2nd approach)" << endl;

    Foo * b = new Foo[NUM_ELEMENTS];

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        Foo* obj = new (&b[i]) Foo(i);
    }

    delete[] b;

    return 0;
}
