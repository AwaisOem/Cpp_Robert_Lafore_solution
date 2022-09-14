#include <iostream>
#include <cmath>  

using namespace std;

class sterling {
private:
	long pounds;
	int shillings, pence;
public:
	sterling() {}
	sterling(double new_pounds);
	sterling(long po, int sh, int pe) :pounds(po), shillings(sh), pence(pe) {}
	void getsterling();
	void putsterling() {
		cout << pounds << "." << shillings << "." << pence;
	}

	sterling operator +(sterling s2) {
		cout << double(s2) << endl; return sterling(double(sterling(pounds, shillings, pence)) + double(s2));
	}
	sterling operator -(sterling s2) {
		return sterling(fabs(double(sterling(pounds, shillings, pence)) - double(s2)));
	}
	sterling operator *(double dd) {
		return sterling(double(sterling(pounds, shillings, pence)) * dd);
	}
	double operator /(sterling s2) {
		return double(sterling(pounds, shillings, pence)) / double(s2);
	}
	sterling operator /(double dd) {
		return sterling(double(sterling(pounds, shillings, pence)) / dd);
	}

	operator double() {
		return double(pounds * 240 + shillings * 12 + pence) / 240;
	}

};

int main(void)
{
	sterling s1(9.59), s2(9, 12, 9), ssum, sdif, sprod, sdiv;
	double dd;

	cout << "In old style: 1 pound = 20 shillings = 240 pence. ranges: shillings(0-19), pence(0-11).";
	cout << "\nIn new style: 1 pound = 100 pence. ranges: pence(0-99).";
	cout << "\n1*old_pound=2.4*new_pound.";

	cout << "\ns1=(new style pound=old style pound):£9.59="; s1.putsterling();
	cout << "\ns2= "; s2.putsterling();

	cout << "\nEnter amount s1"; s1.getsterling();
	cout << "Enter amount s2"; s2.getsterling();
	cout << "Enter multiplier: "; cin >> dd;

	cout << "\n----sterling = sterling + sterling----\n";
	ssum = s1 + s2;
	cout << "ssum(=s1+s2)= "; ssum.putsterling();

	cout << "\n\n----sterling = sterling - sterling----\n";
	sdif = s1 - s2;
	cout << "sdif(=s1-s2)= "; sdif.putsterling();

	cout << "\n\n----sterling = sterling * double----\n";
	sprod = s1 * dd;
	cout << "sprod(=s1*dd)= "; sprod.putsterling();

	cout << "\n\n----double = sterling / sterling----\n";
	dd = s1 / s2;
	cout << "dd(=s1/s2)= "; cout << dd;

	cout << "\n\n----sterling = sterling / double----\n";
	sdiv = s1 / dd;
	cout << "sdiv(=s1/dd)= "; sdiv.putsterling();

	cout << endl;
	return 0;
}

sterling::sterling(double new_pounds) {
	pounds = long(new_pounds);
	int new_pence = int((new_pounds - pounds) * 100);
	pence = int(new_pence * 2.4);
	shillings = int(pence / 12);
	pence %= 12;

}

void sterling::getsterling() {
	char c;
	cout << "(format: £pounds.shillings.pence)= ";
	cin >> pounds >> c >> shillings >> c >> pence;
}
