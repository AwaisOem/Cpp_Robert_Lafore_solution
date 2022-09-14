#include <iostream>
#include <iomanip>
using namespace std;

struct employee {
	long long number;
	float compensation;
};

int main() {
	employee emp1, emp2, emp3;
	cout << "\nEnter the number of the first employee: ";
	cin >> emp1.number;
	cout << "\nEnter the compensation of the first employee: ";
	cin >> emp1.compensation;
	cout << "\nEnter the number of the second employee: ";
	cin >> emp2.number;
	cout << "\nEnter the compensation of the second employee: ";
	cin >> emp2.compensation;
	cout << "\nEnter the number of the third employee: ";
	cin >> emp3.number;
	cout << "\nEnter the compensation of the third employee: ";
	cin >> emp3.compensation;

	cout << "\nEmployees informations : number \t compensation" << endl;
	cout << "  \t1. Employee:\t " << emp1.number << setw(11) << emp1.compensation << endl;
	cout << "  \t2. Employee:\t " << emp2.number << setw(11) << emp2.compensation << endl;
	cout << "  \t3. Employee:\t " << emp3.number << setw(11) << emp3.compensation << endl;
	return 0;
}
