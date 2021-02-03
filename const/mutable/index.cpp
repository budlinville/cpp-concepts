#include <iostream>

class Foo {
	private:
		int bar;
		mutable int baz;	// useful for debugging.. e.g. count variable for const functions 
	public:
		Foo(int br, int bz) : bar(br), baz(bz) {}
		int getBar() const {
			//bar = 4;	// BAD : cant do
			// Below is fine.. Can change mutable values inside a const function
			baz = 3;
			return bar;
		}
};

int main() {
	Foo foo(4, 8);

	foo.getBar();

	
	return 0;
}