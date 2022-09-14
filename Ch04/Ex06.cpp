#include <iostream>
using namespace std;

enum employe {laborer, secretary, manager, accountant, executive, researcher};

int main() {
	char ch;

	cout << "Enter employee type(firrst letter only)"
		"\n(laborer, secretary, manger, accountant, executive, researcher): ";
	cin >> ch;

	switch (ch) {
	case 'l':
		ch = laborer;
		cout << "Employee type is laborer." << endl;
		break;
	case 's':
		ch = secretary;
		cout << "Employee type is secretary." << endl;
		break;
	case 'm':
		ch = manager;
		cout << "Employee type is manager." << endl;
		break;
	case 'a':
		ch = accountant;
		cout << "Employee type is accountant." << endl;
		break;
	case 'e':
		ch = executive;
		cout << "Employee type is executive." << endl;
		break;
	case 'r':
		ch = researcher;
		cout << "Employee type is researchet." << endl;
		break;
	default:
		cout << "Invalid selection." << endl;
	}


	return 0;
}
