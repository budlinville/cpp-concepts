#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// This all works much better with C++11
enum Skill {
	Bad = 0,	// starts at 0 by default, but can override
	Average,	// can override this as well; else will be 1
	Good			// 2
};

enum class Pokemon {
	Charmander,
	Squirtle,
	Bulbosaur
};

int main() {
	Skill basketballSkills = Bad;
	Skill lacrosseSkills = Good;

	// can change name as well
	typedef Skill Ability;

	Ability cookingSkills = Average;

	cout << "Basketball skills: " << basketballSkills << endl;
	cout << "Lacrosse skills: " << lacrosseSkills << endl;
	cout << "Cooking skills: " << cookingSkills << endl;

	// But what if I want to name something 'Bad'
	int Bad = 9;
	// Then try to use Skill's Bad. Below line will not work
	// Skill runningSkills = Bad;	// Type mismatch.. Skill != int

	// Therefor, we have class enums
	Pokemon starter = Pokemon::Bulbosaur;
	// can't print them out like before though.. I guess they're not implemented with ints..?
	// cout << "My starting pokemon: " << starter << endl;
	switch(starter) {
		case Pokemon::Charmander : cout << "Charmander" << endl; break;
		case Pokemon::Squirtle : cout << "Squirtle" << endl; break;
		case Pokemon::Bulbosaur : cout << "Bulbosaur" << endl; break;
		default: cout << "Pikachu" << endl; break;
	}

	return 0;
}