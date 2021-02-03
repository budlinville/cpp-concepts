#include <iostream>

using namespace std;

class Entity {
	private:
		int m_X, m_Y;
		const int* m_Z;
	public:
		Entity(int x, int y) : m_X(x), m_Y(y) {}
		int getX() const {
			// This won't work.. const function means it won't change classes' member variables
			// m_X = 2;
			return m_X;
		}

		int getY() {
			return m_Y;
		}

		// it can actually get worse lmao
		// returns a const int* (value at pointer cannot change)
		// second const means you can't change where getZ() points to
		// third const means function will not change member variable's values
		const int* const getZ() const {
			return m_Z;
		}
};

int main() {
	Entity entity(4, 5);
	cout << "X: " << entity.getX() << endl;

	const int* z = entity.getZ();
	cout << "Z: " << z << "; *Z: " << *z << endl;

	const Entity entity2(6, 3);
	cout << "X: " << entity2.getX() << endl;		// this works
	// Below does not work. A const instance of a class can only access const functions
	// This makes sense.. Its a const, so it needs to guarantee no operations will mutate class
	//cout << "Y: " << entity2.getY() << endl;

	return 0;
}