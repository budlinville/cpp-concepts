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

    std::string toString() {
        return  "(FOO {" + std::to_string(_foo)
            + "}) (BAR {" + std::to_string(_bar)
            + "}) (BAZ {" + std::to_string(_baz)
            + "})";
    }
};


typedef Base<float, int, int> FloatIntInt;
typedef Base<int, float, int> IntFloatInt;

int main() {
    FloatIntInt fis(2.99, 3, 5);

    IntFloatInt ifia(4, 3.27, 9);

    std::cout << fis.toString() << std::endl;
    std::cout << ifia.toString() << std::endl;

    return 0;
}