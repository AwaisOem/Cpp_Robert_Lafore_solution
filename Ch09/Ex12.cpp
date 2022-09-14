#include<iostream>
#include<cmath>  
using namespace std;

class sterling {
protected:
	long pounds;  
	int shillings, pence;  
public:
	sterling() {}  
	sterling(double new_pounds);  
	sterling(long po, int sh, int pe) :pounds(po), shillings(sh), pence(pe) {}

	void getsterling() {
		char c; cin >> pounds >> c >> shillings >> c >> pence;
	}
	void putsterling()const {
		cout << pounds << "." << shillings << "." << pence;
	}
};
class sterfrac :public sterling {
private:
	int eighth;
public:
	sterfrac() :sterling(), eighth(0) {}
	sterfrac(long po, int sh, int pe, int ei)
		:sterling(po, sh, pe), eighth(ei) {}
	sterfrac(sterling s, int ei) :sterling(s), eighth(ei) {}

	void getsterling() {
		cout << "(Note: Pounds(start at 0),shillings(0 to 19), pence(0 to 11), "
			<< "\nn-no. of eights(1 to 7))";
		cout << "\n(format: pounds.shillings.pence-n/8)= ";
		sterling::getsterling();
		char c;
		cin >> c >> eighth >> c >> c;
	}
	void putsterling() {
		sterling::putsterling(); cout << "-" << eighth << "/8";
	}

	sterfrac operator +(sterfrac s2) {
		double dd = double(sterfrac(pounds, shillings, pence, eighth)) + double(s2);
		return sterfrac(sterling(dd), int((dd - floor(dd)) * 8));
	}
	sterfrac operator -(sterfrac s2) {
		double dd = fabs(double(sterfrac(pounds, shillings, pence, eighth)) - double(s2));
		return sterfrac(sterling(dd), int((dd - floor(dd)) * 8));
	}
	sterfrac operator *(double dd) {
		dd *= double(sterfrac(pounds, shillings, pence, eighth));
		return sterfrac(sterling(dd), int((dd - floor(dd)) * 8));
	}
	double operator /(sterfrac s2) {
		return double(sterfrac(pounds, shillings, pence, eighth)) / double(s2);
	}
	sterfrac operator /(double dd) {
		dd = double(sterfrac(pounds, shillings, pence, eighth)) / dd;
		return sterfrac(sterling(dd), int((dd - floor(dd)) * 8));
	}

	operator double() {
		return double(pounds * 240 + shillings * 12 + pence + eighth / 8.0);
	}
};

int main() {
	sterling st(23, 14, 5);
	sterfrac s1(34, 15, 9, 6), s2(23, 11, 3, 4), s3(st, 7), ssum, sdif, sprod, sdiv;
	double dd;
	cout << "Sterling: 1 pound = 20 shillings = 240 pence. ranges: shillings(0-19), pence(0-11).";

	cout << "\ns1= "; s1.putsterling();
	cout << "\ns2= "; s2.putsterling();
	cout << "\ns2= "; s3.putsterling();

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

sterling::sterling(double dd) {
	pounds = long(dd / 240);
	shillings = int(int(dd) % 240 / 12);
	pence = int(dd) % 12;

}
