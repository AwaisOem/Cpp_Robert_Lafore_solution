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

int main() {
	fraction fr1, fr2, fr3;
	char ch;
	do {
		int n, d;
		char c;
		cout << "Enter the first fraction (in this format x/y): ";
		cin >> n >> c >> d;
		fr1.set_fraction(n, d);
		cout << "Enter the second fraction (in this format x/y): ";
		cin >> n >> c >> d;
		fr2.set_fraction(n, d);
		cout << "Enter the operator(+, -, *, /): ";
		cin >> c;
		fr3 = fr3.calc_fraction(fr1, fr2, c);
		fr3.lowestTerms();
		cout << "Do you want to continue? (Y/N) ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');

	return 0;
}
