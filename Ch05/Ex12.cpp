#include<iostream>
using namespace std;

struct fraction {
	int numerator;
	int denomerator;
	char ch;
};
fraction fadd(fraction, fraction);
fraction fmul(fraction, fraction);
fraction fsub(fraction, fraction);
fraction fdiv(fraction, fraction);

int main() {
	fraction f1, f2, f3;
	cout << "Enter the first fraction (like this format x/y): ";
	cin >> f1.numerator >> f1.ch >> f1.denomerator;
	cout << "Enter the second fraction (like this format x/y): ";
	cin >> f2.numerator >> f2.ch >> f2.denomerator;
	char op;
	cout << "Enter an operator to claculate the fractions you have entered(+, *, -, /): ";
	cin >> op;
	switch (op) {
	case '+':
		f3 = fadd(f1, f2);
		cout << "The sum of this fractions is: " << f3.numerator << "/" << f3.denomerator << endl;
		break;
	case '*':
		f3 = fmul(f1, f2);
		cout << "The multiple of this fractions is: " << f3.numerator << "/" << f3.denomerator << endl;
		break;
	case '-':
		f3 = fsub(f1, f2);
		cout << "The substraction of this fractions is: " << f3.numerator << "/" << f3.denomerator << endl;
		break;
	case '/':
		f3 = fdiv(f1, f2);
		cout << "The division of this fractions is: " << f3.numerator << "/" << f3.denomerator << endl;
		break;
	}
	
	return 0;
}
fraction fadd(fraction f1, fraction f2) {
	fraction f3;
	f3.numerator = f1.numerator * f2.denomerator + f1.denomerator * f2.numerator;
	f3.denomerator = f1.denomerator * f2.denomerator;
	return f3;
}
fraction fmul(fraction f1, fraction f2) {
	fraction f3;
	f3.numerator = f1.numerator * f2.numerator;
	f3.denomerator = f2.denomerator * f2.denomerator;
	return f3;
}
fraction fsub(fraction f1, fraction f2) {
	fraction f3;
	f3.numerator = f1.numerator * f2.denomerator + f1.denomerator * f2.numerator;
	f3.denomerator = f1.denomerator * f2.denomerator;
	return f3;
}
fraction fdiv(fraction f1, fraction f2) {
	fraction f3;
	f3.numerator = f1.numerator * f2.denomerator;
	f3.denomerator = f1.denomerator * f2.numerator;
	return f3;
}
