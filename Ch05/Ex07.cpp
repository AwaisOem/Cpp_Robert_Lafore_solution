#include<iostream>
using namespace std;
double power(double, int);
float power(float, int);
int power(int, int);
long power(long, int);
char power(char, int);

int main() {
	double num1;
	float num2;
	int num3;
	long num4;
	char num5;
	cout << "Enter a double value for power calculation: ";
	cin >> num1;
	cout << "Power of num1: " << power(num1, 2) << endl;
	cout << "\nEnter a float value for power calculaion: ";
	cin >> num2;
	cout << "Power of num2: " << power(num2, 2) << endl;
	cout << "\nEnter a int value for power calculation: ";
	cin >> num3;
	cout << "Power of num3: " << power(num3, 2) << endl;
	cout << "\nEnter a long value for power calculation: ";
	cin >> num4;
	cout << "Power of num4: " << power(num4, 2) << endl;
	cout << "\nEnter a char value for power caculation: ";
	cin >> num5;
	cout << "Power of num5: " << power(num5, 2) << endl;

	return 0;
}
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
float power(float n, int p) {
	if (p < 0) {
		cout << "you cant enter negative number for power";
		exit(0);
	}
	float d = 1.0;
	while (p >= 1) {
		d *= n;
		p--;
	}
	return d;
}
int power(int n, int p) {
	if (p < 0) {
		cout << "you cant enter negative number for power";
		exit(0);
	}
	int d = 1;
	while (p >= 1) {
		d *= n;
		p--;
	}
	return d;
}
long power(long n, int p) {
	if (p < 0) {
		cout << "you cant enter negative number for power";
		exit(0);
	}
	long d = 1;
	while (p >= 1) {
		d *= n;
		p--;
	}
	return d;
}
char power(char n, int p) {
	if (p < 0) {
		cout << "you cant enter negative number for power";
		exit(0);
	}
	char d = 1;
	while (p >= 1) {
		d *= n;
		p--;
	}
	return d;
}
