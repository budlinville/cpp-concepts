#include <vector>
#include <iostream>

using namespace std;

/*
	Vector resizing is expensive.. Let's fix that..
*/

struct Vertex {
	float x, y, z;
	// Using initialization list here... good for:
	//	1. Calling base class constructors
	//	2. Initalising member variables before body of constructor executes
	//	3. Also just clean amiright
	Vertex(float x, float y, float z) : x(x), y(y),  z(z) {}

	// Copy constructor
	Vertex(const Vertex& vertex) : x(vertex.x), y(vertex.y), z(vertex.z) { cout << "copied" << vertex.x << endl; }
};

// Vectors are not super optimal by default, b/c frequent resizing is expensive
int main() {
	// Note that copy constructor gets called 6 times
	// 3 resize
	// 1st resize: copy v1 to new vector
	// 2nd resize: copy v1 and v4
	// 3rd resize: copy v1, v4, and v7 to new vector
	vector<Vertex> vertices;
	vertices.push_back(Vertex(1, 2, 3));	// v1
	vertices.push_back(Vertex(4, 5, 6));	// v4
	vertices.push_back(Vertex(7, 8, 9));	// v7

	cout << "-----------" << endl;

	// small fix : reserve space if we know how many elements we need
	// now only get three copies
	vector<Vertex> vertices2;
	vertices2.reserve(3);
	vertices2.push_back(Vertex(1, 2, 3));	// v1
	vertices2.push_back(Vertex(4, 5, 6));	// v4
	vertices2.push_back(Vertex(7, 8, 9));	// v7

	cout << "-----------" << endl;

	// supposedly this will remove the remaining copies...
	// but I don't have this funtion??
	/*
	vector<Vertex> vertices3;
	vertices3.reserve(3);
	vertices3.emplace_back(1, 2, 3);	// v1
	vertices3.emplace_back(4, 5, 6);	// v4
	vertices3.emplace_back(7, 8, 9);	// v7
	*/

	return 0;
}