#include <iostream>
#include <string>

using namespace std;

class Distance {
	int feet;
	float inches;
public:
	Distance() : feet(0), inches(0.0) {}
	Distance(float fltfeet) {
		feet = int(fltfeet);
		inches = 12 * (fltfeet - feet);
	}
	Distance(int ft, float in) : feet(ft), inches(in) {}
	void showdist() {
		cout << feet << ", " << inches << endl;
	}
	friend Distance operator *(Distance, Distance);
};

Distance operator *(Distance d1, Distance d2) {
	float fltfeet1 = d1.feet + d1.inches / 12;
	float fltfeet2 = d2.feet + d2.inches / 12;
	float mulfeet = fltfeet1 + fltfeet2;
	return Distance(mulfeet);
}

int main() {
	Distance dist1(3, 6.0);
	Distance dist2(2, 2.0);
	Distance dist3;
	Distance wdist1;

	dist3 = dist1 * dist2;
	dist3 = 7.5 * dist3;

	cout << "dist1 ==> "; dist1.showdist();
	cout << "dist2 ==> ";  dist2.showdist();
	cout << "dist3 ==> "; dist3.showdist();



	return 0;
}
