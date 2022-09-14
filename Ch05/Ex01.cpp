#include<iostream>
using namespace std;
#define Pi 3.14159

float circarea(float rads) {
	return Pi * rads * rads;
}
int main() {
	float r;
	cout << "\nEnter radius of a circle: ";
	cin >> r;
	cout << "Area of circle is: " << circarea(r) << endl;
	return 0;
}
