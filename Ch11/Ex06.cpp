#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath> 

using namespace std;
long double mstold(string s);
string ldtoms(long double sum);

class bMoney {
	long double money;
public:
	bMoney();
	bMoney(long double m);
	void madd(bMoney m1, bMoney m2);
	void getmoney();
	void putmoney();
	bMoney operator +(bMoney other) {
		return bMoney(other.money + money);
	}
	bMoney operator -(bMoney other) {
		return bMoney(money - other.money);
	}
	bMoney operator *(bMoney other) {
		return bMoney(other.money * money);
	}
	bMoney operator /(bMoney other) {
		return bMoney(money / other.money);
	}
	bMoney operator *(long double n) {
		return bMoney(money * n);
	}
	friend bMoney round(bMoney b) {
		b.money = round(b.money);
		return b;
	}
};
bMoney::bMoney() { money = 0; }
bMoney::bMoney(long double m) { money = m; }
void bMoney::madd(bMoney m1, bMoney m2) {
	money = m1.money + m2.money;
}
void bMoney::getmoney() {
	string s;
	cin >> s;
	money = mstold(s);
}
void bMoney::putmoney() {
	string s = ldtoms(money);
	cout << s << endl;
}

int main() {
	bMoney b1, b2, b3;
	char ch;
	do {
		cout << "Enter amount of money: ";
		b1.getmoney();
		cout << "Enter amount of money: ";
		b2.getmoney();
		cout << "The sum of this money amounts: ";
		b3 = b1 + b2; 
		b3 = round(b3);
		b3.putmoney();
		cout << "The substraction of this money amounts: ";
		b3 = b1 - b2; 
		b3 = round(b3);
		b3.putmoney();
		cout << "The multiple of this money amounts: ";
		b3 = b1 * b2; 
		b3 = round(b3);
		b3.putmoney();
		cout << "The divide of this money amounts: ";
		b3 = b1 / b2; 
		b3 = round(b3);
		b3.putmoney();
		cout << "The multiple of first money amount with another which is out of class: ";
		b3 = b1 * 251348751; 
		b3 = round(b3);
		b3.putmoney();
		cout << "Would you want to continue? (y/n)";
		cin >> ch;
	} while (ch=='y');

	return 0;
}

long double mstold(string s) {
	long double sum = 0;
	int p = 0;
	for (int i = 1; i < s.size(); i++) {
		if (48 <= static_cast<int>(s[i]) && static_cast<int>(s[i]) <= 57)
			sum = sum * 10 + static_cast<int>(s[i]) - 48;
		else if (s[i] == '.')
			p = i;
	}
	long double frac_part = pow(10, s.size() - 1 - p);
	sum /= frac_part;
	return sum;
}
string ldtoms(long double sum) {
	stringstream ss(stringstream::in | stringstream::out);
	ss.setf(ios::fixed);
	ss << setprecision(2) << sum;
	string s = ss.str();
	s.insert(0, "$");
	int p = s.find('.') - 1, n = 0;
	for (int i = p; i > 0; i--)
		if (++n % 3 == 0)
			s.insert(i, ",");
	return s;
}
