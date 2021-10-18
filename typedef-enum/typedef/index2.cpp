#include <iostream>
#include <string>


template< typename foo
        , typename bar
        , typename baz >
class Base {
private:
    foo _foo;
    bar _bar;
    baz _baz;

public:
    Base(foo f, bar br, baz bz)
        : _foo(f)
        , _bar(br)
        , _baz(bz)
    {}

    virtual std::string toString() {
        return  "(FOO {" + std::to_string(_foo)
            + "}) (BAR {" + std::to_string(_bar)
            + "}) (BAZ {" + std::to_string(_baz)
            + "})";
    }
};


// Declare specialized versions of base using templates and typedefs
typedef Base<float, int, int> FloatIntInt;
typedef Base<int, float, int> IntFloatInt;


// Alternative way of declaring specializations using class hierarchy instead of typedef
template<class Parent=Base<int, int, int>>
class IntIntInt : Parent {
public:
    IntIntInt(int foo, int bar, int baz) : Parent(foo, bar, baz) {};

    std::string toString() {
        return "Called IntIntInt's toString().. congrat's bro";
    }
};


int main() {
    FloatIntInt fis(2.99, 3, 5);
    IntFloatInt ifia(4, 3.27, 9);
    IntIntInt<> iii(3,4,5);

    std::cout << fis.toString() << std::endl;
    std::cout << ifia.toString() << std::endl;
    std::cout << iii.toString() << std::endl;

    return 0;
}