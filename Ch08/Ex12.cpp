#include<iostream>
#include<string>
#include<sstream>  
#include<cmath>  
using namespace std;

class sterling {
private:
	long pounds;  
	int shillings, pence; 
public:
	sterling() {}  
	sterling(long pence1);  
	sterling(long po, int sh, int pe) :pounds(po), shillings(sh), pence(pe) {}
	void getsterling();  
	void putsterling() {
		cout << pounds << "." << shillings << "." << pence;
	}
	operator double() {
		return double(pounds * 240 + shillings * 12 + pence) / 240;
	} 

	long double rpence() {
		return (long double)(pounds * 240 + shillings * 12 + pence);
	}
};

class bMoney {
private:
	string smoney;
	long double ldmoney;
public:
	bMoney() {}
	~bMoney() {}
	bMoney(string sm) { smoney = sm; mstold(); }  
	bMoney(long double ldm) { ldmoney = ldm; ldtoms(); }  

	void getmoney() {
		cin >> smoney; mstold();
	}
	void putmoney() {
		cout << smoney;
	}
	void mstold();  
	void ldtoms();  

	operator sterling()const {
		return sterling(long(ldmoney / 0.2083));
	}

	void pound_to_dollar(long double ldp) {
		ldmoney = ldp; ldtoms();
	}

};

int main() {
	sterling s1;
	bMoney bm1;
	char q = 'y';
	int choice;

	while (q == 'y' || q == 'Y') {
		cout << "Enter 1 to convert from dollars to pounds, 2 to convert otherway around: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter amount in dollars(format: $xxx,xxx.xxx,xx): ";
			bm1.getmoney();
			s1 = bm1;
			cout << "= "; s1.putsterling();
			break;
		case 2:
			cout << "Enter amount in pounds ";
			s1.getsterling();
			bm1.pound_to_dollar(s1.rpence() * 0.2083);
			cout << "= "; bm1.putmoney();
		}
		cout << "Flaw: Conversion not accurate. We receive suggestions.\n";
		cout << "\nGo again(y/n)?: ";
		cin >> q;
	}
	return 0;
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

void sterling::getsterling() {
	char c;  
	cout << "(format: pounds.shillings.pence)= ";
	cin >> pounds >> c >> shillings >> c >> pence;
}

sterling::sterling(long pence1) {
	pounds = long(pence1 / 240);  
	shillings = int((pence1 % 240) / 12);  
	pence = int(pence1 % 12); 

}
