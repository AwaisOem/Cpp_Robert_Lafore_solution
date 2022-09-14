#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class person {
protected:
	string name;
	float salary;
public:
	person() {}
	void setData() {
		cout << "Enter name: ";		cin >> name;
		cout << "Enter salary: ";	cin >> salary;
	}
	void printData() {
		cout << name << " ==> " << salary << endl;
	}
	float getSalary() {
		return salary;
	}
};

int main() {
	void salsort(person**, int);

	person* persPtr[100];
	int n = 0; 
	char choice;
	do {
		persPtr[n] = new person;
		persPtr[n]->setData();
		n++;
		cout << "Enter another (y/n)? "; cin >> choice;
	} while (choice == 'y');

	cout << "Unsorted list: " << endl;
	for (int i = 0; i < n; i++)
		persPtr[i]->printData();

	salsort(persPtr, n);
	cout << "\nSorted list: " << endl;
	for (int i = 0; i < n; i++)
		persPtr[i]->printData();

	return 0;
}

void salsort(person** pp, int n) {
	void order(person**, person**);
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			order(pp + i, pp + j);
}
void order(person** pp1, person** pp2) {
	if ((*(pp1))->getSalary() > (*(pp2))->getSalary()) {
		person* tempptr = *pp1;
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}
