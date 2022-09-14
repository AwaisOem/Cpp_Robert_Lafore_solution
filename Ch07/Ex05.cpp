#include <iostream>
using namespace std;

class fraction {
private:
	int numerator;
	int denominator;
public:
	void set_fraction(int, int);
	fraction calc_fraction(fraction, fraction, char);
	void display();
	void lowestTerms();
	fraction average(fraction, int);
};
void fraction::set_fraction(int n, int d) {
	numerator = n;
	denominator = d;
}
fraction fraction::calc_fraction(fraction f1, fraction f2, char op) {
	fraction f3;
	switch (op) {
	case '+':
		f3.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
		f3.denominator = f1.denominator * f2.denominator;
		return f3;
		break;
	case '*':
		f3.numerator = f1.numerator * f2.numerator;
		f3.denominator = f2.denominator * f2.denominator;
		return f3;
		break;
	case '-':
		f3.numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
		f3.denominator = f1.denominator * f2.denominator;
		return f3;
		break;
	case '/':
		f3.numerator = f1.numerator * f2.denominator;
		f3.denominator = f1.denominator * f2.numerator;
		return f3;
		break;
	}
}
void fraction::lowestTerms() {
	long tnum, tden, temp, gcd;

	tnum = labs(numerator);
	tden = labs(denominator);

	if (tden == 0) {
		cout << "Illegasl fraction: division by 0";
		exit(1);
	}
	else if (tnum == 0) {
		numerator = 0;
		denominator = 1;
		return;
	}

	while (tnum != 0) {
		if (tnum < tden) {
			temp = tnum;
			tnum = tden;
			tden = temp;
		}
		tnum = tnum - tden;
	}
	gcd = tden;
	numerator = numerator / gcd;
	denominator = denominator / gcd;
	cout << "The result of this frations is: " << numerator << "/" << denominator;
	cout << endl;
}
void fraction::display() {
	cout << "The result of this frations is: " << numerator << "/" << denominator << endl;
}
fraction fraction::average(fraction f, int i) {
	f.denominator *= i;
	return f;
}

int main() {
	fraction f[10], result, average;
	for (int i = 0; i < 9; i++) {
		int nn, dd, j = i+1;
		char ch;
		cout << "Ener the fraction(in this format x/y): ";
		cin >> nn >> ch >> dd;
		f[i].set_fraction(nn, dd);
		cout << "Ener the fraction(in this format x/y): ";
		cin >> nn >> ch >> dd;
		f[i + 1].set_fraction(nn, dd);
		cout << "Enter the operator (+, *, /, -): ";
		cin >> ch;
		result = result.calc_fraction(f[i], f[i + 1], ch);
		average = average.average(result, j);
		average.lowestTerms();
	}

	return 0;
}

