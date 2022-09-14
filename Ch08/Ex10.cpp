#include <iostream>
#include <cmath>
#define Pi 3.14

using namespace std;

class Polar {
	float radius, angled, angler, xcoo, ycoo;
public:
	Polar() {}
	Polar(float r, float a) : radius(r), angled(a) { deg_to_rad(); polar_to_rect(); }
	void deg_to_rad() {
		angler = angled * Pi / 180;
	}
	void rad_to_deg() {
		angled = angler * 180 / Pi;
	}

	void polar_to_rect();
	void rect_to_polar();

	void get_polar();
	void display()const;

	Polar operator +(Polar);
};

int main() {
	Polar p1, p2, ps;

	cout << "Enter polar coordinate p1: \n";
	p1.get_polar();
	cout << "Enter polar coordinate p2: \n";
	p2.get_polar();

	cout << "p1= "; p1.display();
	cout << "\np2= "; p2.display();

	ps = p1 + p2;
	cout << "\nps(=p1+p2)= "; ps.display();


	return 0;
}
void Polar::polar_to_rect() {
	xcoo = radius * cos(angler);
	ycoo = radius * sin(angler);
}
void Polar::rect_to_polar() {
	radius = sqrt(pow(xcoo, 2) + pow(ycoo, 2));
	angler = atan(ycoo / xcoo);
	rad_to_deg();
}
void Polar::get_polar() {
	cout << "Enter radius: "; cin >> radius;
	cout << "Enter angle in degrees: "; cin >> angled;
	deg_to_rad();
	polar_to_rect();
}
void Polar::display()const {
	cout << radius << "\u2220" << angled << "ْْْْْْْْ°";
}
Polar Polar::operator +(Polar p2) {
	Polar p;
	p.xcoo = xcoo + p2.xcoo;
	p.ycoo = ycoo + p2.ycoo;
	p.rect_to_polar();
	p.rad_to_deg();
	return p;
}
