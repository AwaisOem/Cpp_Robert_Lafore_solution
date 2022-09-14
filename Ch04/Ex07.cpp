#include <iostream>
using namespace std;

enum employee_type {laborer, secretary, manager, accountant, executive, researcher};
struct date {
	int year;
	int month;
	int day;
};
struct employee {
	int number;
	float compensation;
	date _date;
	employee_type _type;
};

int main() {
	employee emp[3];
	
	string info[3] = { "first", "second", "third" };
	for (int i = 0; i < 3; i++) {
		char ch;
		cout << "\nEnter the " << info[i] << " Employee datails : " << endl;
		cout << "Enter the number of employee: ";
		cin >> emp[i].number;
		cout << "Enter the compesation of employee: ";
		cin >> emp[i].compensation;
		cout << "Enter employee type: ";
		cin >>ch;
		switch (ch) {
		case 'l':
			emp[i]._type = laborer;
			break;

		case 's':
			emp[i]._type = secretary;
			break;

		case 'm':
			emp[i]._type = manager;
			break;

		case 'a':
			emp[i]._type = accountant;
			break;

		case 'e':
			emp[i]._type = executive;
			break;

		case 'r':
			emp[i]._type = researcher;
			break;

		default:
			cout << "Invalid Input!";
		}
		cout << "Enter date of " << info[i] << " employment: ";
		cin >> emp[i]._date.day >> emp[i]._date.month >> emp[i]._date.year;
	}
	return 0;
}
