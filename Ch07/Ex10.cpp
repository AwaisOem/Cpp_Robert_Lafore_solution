#include <iostream>
#include <process.h>

using namespace std;

class matrix {
	enum { SZ = 10 };
	int arr[SZ][SZ];
public:
	void putel(int, int, int);
	void getel(int, int);
};
void matrix::putel(int index1, int index2, int value) {
	if (index1 > 0 && index1 < SZ && index2>0 && index2 < SZ) {
		arr[index1][index2] = value;
	}
	else {
		cout << "The index out of bounds." << endl;
		exit(1);
	}
}
void matrix::getel(int index1, int index2) {
	cout << "The value of arr[" << index1 << "][" << index2 << "] => " << arr[index1][index2] << endl;
}

int main() {
	matrix mat;
	char ch;
	do {
		cout << "Enter P for enter an element to array of S to search about element: ";
		cin >> ch;
		int in1, in2, val;
		if (ch == 'p' || ch == 'P') {
			cout << "Enter first index and second index: "; cin >> in1>> in2;
			cout << "Enter the value: "; cin >> val;
			mat.putel(in1, in2, val);
			cout << "The value has been entered." << endl;
		}
		else if (ch == 's' || ch == 'S') {
			int in1, in2;
			cout << "Enter first index and second index: "; cin >> in1>> in2;
			mat.getel(in1, in2);
		}
		cout << "Would you want to continue? (y/n)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');


	return 0;
}

