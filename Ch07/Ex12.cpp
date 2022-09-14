#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class bMoney {
private:
	string smoney;
	long double ldmoney;
public:
	void getmoney();
	void putmoney();
	void madd(bMoney, bMoney);
	void mstold();
	void ldtoms();
};

int main() {
	bMoney m1, m2, msum;
	char q = 'y';

	while (q == 'y' || q == 'Y') {
		cout << "Enter amount m1($xxx,xxx.xxx,xx format): ";
		m1.getmoney();
		cout << "Enter amount m2($xxx,xxx.xxx,xx format): ";
		m2.getmoney();

		msum.madd(m1, m2);
		cout << "Sum of two amounts(msum=m1+m2): ";
		msum.putmoney();

		cout << "\nGo again(y/n)?: ";
		cin >> q;
	}

	return 0;
}

void bMoney::getmoney() {
	cin >> smoney;
	mstold();
}

void bMoney::madd(bMoney m1, bMoney m2) {
	ldmoney = m1.ldmoney + m2.ldmoney;
	ldtoms();
}

void bMoney::putmoney() {
	cout << smoney;
}

void bMoney::mstold() {
	string m = smoney;
	m.erase(0, 1);
	while (m.find(',') > 0 && m.find(',') < m.size() - 1)
		m.erase(m.find(','), 1);

	stringstream ss;
	ss << m;

	ss >> ldmoney;
}

void bMoney::ldtoms() {
	stringstream ss;

	ss << fixed << ldmoney;
	ss >> smoney;

	int pos = smoney.find('.');
	for (int i = pos - 3; i > 0; i -= 3)
		smoney.insert(i, ",");

	pos = smoney.find('.');
	for (int i = pos + 4; i < smoney.size(); i += 4)
		smoney.insert(i, ",");
	smoney.insert(0, "$");

}

