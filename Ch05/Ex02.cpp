#include<iostream>
using namespace std;
#define Pi 3.14159

double power(double n, int p) {
	if (p < 0) {
		cout << "you cant enter negative number for power";
		exit(0);
	}
	double d = 1.0;
	while (p >= 1) {
		d *= n;
		p--;
	}
	return d;
}
int main() {
	int n, p;
	char ch;
	cout << "Enter the number: ";
	cin >> n;
	cout << "Do you want to calculate the square of this number? E\\H: ";
	cin >> ch;
	if (ch == 'E' || ch == 'e') {
		cout << "the square of this number: " << n << " is: " << power(n, 2);
	}
	else {
		cout << "Enter the power that you wnat to add to the number you have entered: ";
		cin >> p;
		cout << "The power: " << p << " of the number: " << n << " is: " << power(n, p) << endl;
	}

	return 0;
}
