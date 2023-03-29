#include <iostream>
#include <random>
#include <string.h>

using namespace std;

/*
https://en.cppreference.com/w/cpp/language/rule_of_three#:~:text=missed%20optimization%20opportunity.-,Rule%20of%20zero,-Classes%20that%20have
 - Rule of zero: Classes that have no dynamically allocated resources and no virtual functions do not need to implement any of the special member functions.
    - don't do any of the below if I don't have to
 - Rule of five: Classes that have dynamically allocated resources or virtual functions should implement all five of the special member functions.
    - if I have to do one, I have to do all five
    - post-C++11, this is the standard
 - Rule of three: Classes that have dynamically allocated resources or virtual functions should implement at least the copy constructor, copy assignment operator, and destructor.
    - if I have to do one, I have to do all three
    - pre-C++11, this was the standard

 - Single Responsibility Principle
    - For Rule of Three and Rule of Five, any class that implements all of these functions should ONLY handle resource allocation
*/

// NOTE: Foo should also implement a copy assignment operator and a move assignment operator;
//       without them, they will fall back to the copy constructor and move constructor
struct Foo {
    Foo() {
        cout << "Constructed" << endl;
        a = new int[10] {
            rand(), rand(), rand(),
            rand(), rand(), rand(),
            rand(), rand(), rand(),
            rand()
        };
    }

    Foo(const Foo & f) {  // Copy constructor (Deep Copy)
        cout << "Copy" << endl;
        a = new int[10];
        memcpy(a, f.a, 10 * sizeof(int));
    }

    Foo(Foo && f) {  // Move constructor (Shallow Copy)
        cout << "Move" << endl;
        a = f.a;
        f.a = nullptr;

        // Better implementation:
        // std::exchange(a, f.a);
    }

    ~Foo () { cout << "Destructed" << endl; }

    Foo& operator=(const Foo & f) {  // Copy assignment operator (Deep Copy)
        cout << "Copy Assignment" << endl;
        a = new int[10];
        memcpy(a, f.a, 10 * sizeof(int));
        return *this;
    }
    
    Foo& operator=(Foo && f) {  // Move assignment operator (Shallow Copy)
        cout << "Move Assignment" << endl;
        a = f.a;
        f.a = nullptr;
        return *this;

        // Better implementation:
        // std::swap(a, f.a);
    }

    void print() {
        if (a == nullptr) {
            cout << "[]" << endl;
            return;
        }

        cout << "[";

        for (int i =0; i < sizeof(a); i++) {
            cout << a[i] << ", ";
        }
        cout << "]" << endl;
    }
    
private:
    int * a = nullptr;
};


int main() {
    // Copy constructor
    cout << "---------" << endl;
    Foo bar;
    Foo bar_copied = bar;
    cout << "bar: "; bar.print();
    cout << "bar_copied: "; bar_copied.print();

    // Move constructor
    cout << "---------" << endl;
    Foo baz;
    Foo baz_moved = std::move(baz);
    cout << "baz: "; baz.print();
    cout << "baz_moved: "; baz_moved.print();

    // Copy assignment operator
    cout << "---------" << endl;
    Foo bizzle; Foo bizzle_copied;
    bizzle_copied = bizzle;
    cout << "bizzle: "; bizzle.print();
    cout << "bizzle_copied: "; bizzle_copied.print();

    // Move assignment operator
    cout << "---------" << endl;
    Foo bazzle; Foo bazzle_moved;
    bazzle_moved = std::move(bazzle);
    cout << "bazzle: "; bizzle.print();
    cout << "bazzle_moved: "; bazzle_moved.print();

    cout << "---------" << endl;

    return 0;
}