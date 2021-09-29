#include <iostream>

// Variadic templates... unknown number of template args of unknown types...

struct Foo {
    int x;
    int y;
    Foo(int& _x, int& _y) : x(_x), y(_y) {}
};

template <typename T, typename...Params>
T CreateObject(Params... args) {
    T obj = T(args...);
    return obj;
}

int main() {
    int obj = CreateObject<int>(4);
    std::cout << obj << std::endl;

    Foo obj2 = CreateObject<Foo>(4, 5);
    std::cout << obj2.x << ", " << obj2.y << std::endl;
}