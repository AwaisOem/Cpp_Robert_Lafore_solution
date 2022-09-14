#include <iostream>

using namespace std;

class angle {
private:
	int degree;
	float minutes;
	char direction;
public:
	angle(): degree(0), minutes(0.0), direction(0) {}
	angle(int, float, char);
	void set_angle(int, float, char);
	void display();
};
angle :: angle(int d, float m, char di) : degree(d), minutes(m), direction(di) {}
void angle::set_angle(int d, float m, char di) {
	degree = d; minutes = m; direction = di;
}
void angle::display() {
	cout << "\n\nThe location is: " << degree << "\xF8" << minutes << "\'" << direction;
}

int main() {
	angle ang = { 197, 59.9F, 'E' };
	ang.display();
 	angle an[3];
	for (int i = 0; i < 3; i++) {
		int dd;
		float mm;
		char dir;
		cout << "\nEnter location (in this format 149\xF8 59.9\' E): ";
		cin >> dd >> mm >> dir;
		an[i] = { dd, mm, dir };
	}
	for (int i = 0; i < 3; i++) {
		an[i].display();
	}
	return 0;
}
