#include <iostream>
#include <cmath>

using namespace std;

class Distance {
	int feet;
	float inches;
public:
	Distance(): feet(0), inches(0.0) {}
	Distance(int ft, float in): feet(ft), inches(in) {}
	void get_dist() {
		cout << "Enter feet: "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
	}
	void display() {
		cout << "feet: " << feet << ", inches: " << inches << endl;
	}
	Distance operator - (Distance other) {
		Distance temp;
		temp.feet = abs(other.feet - feet);
		temp.inches = abs(float(other.inches - inches));
		return temp;
	}
};

int main() {
	Distance d1(5, 7.2), d2(6, 5.4), d3;
	d3 = d1 - d2;
	cout << "d1 ==> "; d1.display();
	cout << "d2 ==> "; d2.display();
	cout << "d3 ==> "; d3.display();


	return 0;
}
