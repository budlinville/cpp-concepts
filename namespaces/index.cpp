#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// namespaces are just logical groupings to avoid naming conflicts
// especially important when using many external libraries
// also good to group common functionality
namespace MemeStocks {
	void buyGME() { cout << "Easy money. heck those hedge fund managers" << endl; }
	void buyAMC() { cout << "Honestly maybe not a bad pickup.. was undervalued and movies will definitely make a comback post coronavius.." << endl; }
	void buyNOK() { cout << "Honestly heck Robinhood for clossing trading on this one.. It was about to go to the moon" << endl; }
	void toTheMoon() { cout << "to the moon" << endl; }
	void holdTheLine() { cout << "Short squeeze lets go. Just a little while longer to really stick it to Wallstreet" << endl; }

	class RobinhoodGuru {
		public: 
		static void speak() {
			cout << "Just buy some dogecoin and call it a day.. Shot up 400% in a day. Showing no signs of slowing.." << endl;
		}
	};
};

int main() {
	MemeStocks::buyGME();
	MemeStocks::buyAMC();
	MemeStocks::buyNOK();
	MemeStocks::toTheMoon();
	MemeStocks::holdTheLine();
	MemeStocks::RobinhoodGuru::speak();
	return 0;
}