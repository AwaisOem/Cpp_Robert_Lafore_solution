#include <iostream>
#include <process.h> 

using namespace std;

const int LIMIT = 100;
class safearray {
	int arr[LIMIT];
public:
	safearray();
	int& operator [](int index);
};

class safehilo : public safearray {
	int max, min;
public:
	safehilo() : min(0), max(0) {}
	safehilo(int mx, int mn) : max(mx), min(mn) {}
	int& operator [](int index);
	void arange();
};

int main() {
	safehilo sh;
	char ch, choise;
	int index, value;
	cout << "-------------------- Enter the range of upper and lower ----------------------- " << endl;
	sh.arange();
	do {
		cout << "Press P to put element, S to search about element: ";
		cin >> choise;
		if (choise == 'p' || choise == 'P') {
			cout << "Enter index and value to put: ";
			cin >> index >> value;
			sh[index] = value;
		}
		else if (choise == 's' || choise == 'S') {
			cout << "Enter index to search about its vlue: ";
			cin >> index;
			cout << "The value of this index is: " << sh[index] << endl;
		}
		cout << "Would you want to continue?(y/n)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	return 0;
}

safearray::safearray() {
	for (int i = 0; i < LIMIT; i++) {
		arr[i] = 0;
	}
}
int& safearray::operator[](int index) {
		return arr[index];
}
int& safehilo::operator[](int index) {
	if (index > max || index < min) {
		cout << "Index is out of bounds.";
		exit(1);
	}
	return safearray::operator[](index);
}
void safehilo::arange() {
	cout << "Enter the upper of array: "; cin >> max;
	cout << "Enter the lower of array: "; cin >> min;
	if (max - min >= LIMIT) {
		cout << "No of element greater than array size" << endl;
		exit(1);
	}
}
