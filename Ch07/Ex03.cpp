#include <iostream>

using namespace std;

class Distance {
	int feet;
	float inches;
public:
	Distance(): feet(0), inches(0.0) {}
	Distance(int, float);
	void getdist();
	void showdist()const;
	void add_dist(Distance, Distance);
	void div_dist(Distance, int);
};
Distance::Distance(int ft, float in): feet(ft), inches(in) {}
void Distance::getdist() {
	cout << "Enter feet: "; cin >> feet;
	cout << "Enter inches: "; cin >> inches;
}
void Distance::showdist()const {
	cout << feet << " , " << inches << endl;
}
void Distance::add_dist(Distance d2, Distance d3) {
	inches = d2.inches + d3.inches;
	feet = 0;
	if (inches >= 12.0) {
		inches -= 12.0;
		feet++;
	}
	feet += d2.feet + d3.feet;
}
void Distance::div_dist(Distance d2, int divisor) {
	float fltfeet = d2.feet + d2.inches / 12.0;
	fltfeet / +divisor;
	feet = int(fltfeet);
	inches = (fltfeet - feet) * 12.0;
}

int main() {
	Distance distarr[100];
	Distance total(0, 0.0), average;
	int count = 0;
	char ch;
	do {
		cout << "\nEnter a Distance";
		distarr[count++].getdist();
		cout << "\nDo another (y/n)? ";
		cin >> ch;
	} while (ch != 'n');
	for (int j = 0; j < count; j++)
		total.add_dist(total, distarr[j]);
	average.div_dist(total, count);
	cout << "\nThe average is: ";
	average.showdist();
	cout << endl;

	return 0;
}

