#include <iostream>

using namespace std;

struct point_to_model {
	int x;
	int y;
};

int main() {
	point_to_model p1, p2, p3;

	cout << "Enter coordinates for p1: ";
	cin >> p1.x >> p1.y;
	cout << "Enter coordinates for p2: ";
	cin >> p2.x >> p2.y;
	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	cout << "Coordintes of p1+p2 are: " << p3.x << " " << p3.y << endl;

	system("pause>0");
}
