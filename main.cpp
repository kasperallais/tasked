#include <iostream>
using namespace std;

int main() {
	int input;
	cout << "1 For Task Tracker, 2 For Habit Tracker: ";
	cin >> input;

	if (input == 1) {
		cout << "You Pressed One" << endl;
	}
	else if (input == 2) { 
		cout << "You Pressed Two" << endl;
	}
}
