#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Golf {
	private:
		static int s_score;
		static int s_par;

		void tallyScore(int score, int par){
			cout << ((score <= par) ? "Good job!" : "Tough luck!") << endl;
			s_score += score;
			s_par += par;
		}

	public:
		// static methods/variables must be defined outside the scope
		static string greeting;
		
		static int getScore();
		static int getPar();

		// non-static methods/variables can be defined inside the struct
		string game = "GOLF";	// this works but throws a warning

		void eagle(int par) {
			int score = par - 2;
			cout << "Par was " << par << "; You scored " << score << "; ";
			tallyScore(score, par);
		}

		void birdie(int par) {
			int score = par - 1;
			cout << "Par was " << par << "; You scored " << score << "; ";
			tallyScore(score, par);
		}

		void par(int par) {
			cout << "Par was " << par << "; You scored " << par << "; ";
			tallyScore(par, par);
		}

		void bogie(int par) {
			int score = par + 1;
			cout << "Par was " << par << "; You scored " << score << "; ";
			tallyScore(score, par);
		}

		void doubleBogie(int par) {
			int score = par + 2;
			cout << "Par was " << par << "; You scored " << score << "; ";
			tallyScore(score, par);
		}
};

int Golf::s_score = 0;
int Golf::s_par = 0;
string Golf::greeting = "Welcome to the PGA Tour!";

int Golf::getScore() {
	return Golf::s_score;
}

int Golf::getPar() {
	return Golf::s_par;
}
