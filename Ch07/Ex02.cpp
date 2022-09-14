#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class employee {
	string name;
	long emp_number;
public:
	void getdata(string, long);
	void putdata();
};
void employee::getdata(string s, long l) { name = s; emp_number = l; }
void employee::putdata() {
	cout << "Neme of emplooyee is: " << name << endl;
	cout << "Nmber of employee: " << emp_number << endl;
}

int main() {
	employee emp[100];
	char ch;
	int x = 0;
	for (int i = 0; i < 100; i++) {
		string st;
		long nn;
		cout << "Would you insert a an employee: (Y/N): ";
		cin >> ch;
		if (ch == 'Y' || ch == 'y') {
			cout << "Enter the name of employee: ";
			cin >> st;
			cout << "Enter the number of employee: ";
			cin >> nn;
			emp[i].getdata(st, nn);
			x++;
		}
		else {
			break;
		}
	}
	cout << "\n\n----------------------The data of employees--------------------\n\n";
	for (int i = 0; i < x; i++)
		emp[i].putdata();


	return 0;
}

