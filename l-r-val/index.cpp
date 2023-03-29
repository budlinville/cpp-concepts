#include <iostream>

struct A {
    int a = 3;
    int & getA() {
        return a;
    }

    void print() {
        std::cout << a << std::endl;
    }
};


void foo(const int & f) {
    std::cout << "[ L ] " << f << std::endl;
}

void foo(const int && f) {
    std::cout << "[ R ] " << f << std::endl;
}


// Existence of r values makes it possible to do something special with temporary values
// e.g. std::move
int main() {
    A a;
    a.print();

    a.getA() = 5;
    a.print();

    foo(3);         // R
    foo(a.getA());  // L

    return 0;
}