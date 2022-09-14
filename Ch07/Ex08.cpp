#include <iostream>

using namespace std;

class safearay {
	enum { LIMIT = 100 };
	int arr[LIMIT];
public:
	void putel(int, int);
	int getel(int index);
};

int main() {
	safearay ar;
	char ch;
	do {
		char c;
		cout << "If you want to insert elements press 'I' if you want to search anout element press 's' :";
		cin >> c;
		if (c == 'i' || c == 'I') {
			int in, va;
			cout << "Enter the index and its value: "; cin >> in >> va;
			ar.putel(in, va);
		}
		else if (c == 'S' || c == 's') {
			int in;
			cout << "Enter the index : "; cin >> in;
			ar.getel(in);
		}
		cout << "Would you want to continue? (Y/N) "; cin >> ch;
	} while (ch == 'Y' || ch == 'y');

	return 0;
}

void safearay::putel(int index, int value) {
	if (index >= 0 && index < LIMIT) {
		arr[index] = value;
	}
	else
		cout << "The index is out of bounds." << endl;
}
int safearay::getel(int index) {
	int temp;
	if (index >= 0 && index < LIMIT) {
		temp = arr[index];
		cout << "The item " << index << " is equal to " << temp << endl;
	}
	else
		cout << "The index is out of bounds." << endl;
	return temp;
}

