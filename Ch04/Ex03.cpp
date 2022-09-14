#include <iostream>

using namespace std;

struct Distance {
	int feet;
	float inches;
};

struct volume {
	Distance width;
	Distance height;
	Distance length;
};

int main() {
	float l, w, h, vol;
	volume room = { {3, 6.6}, {5, 3.1}, {3, 7.9} };
	cout << "Length of the room is : \'" << room.length.feet << "\' feet-\'" << room.length.inches << "\' inches" << endl;
	cout << "Width of the room is : \'" << room.width.feet << "\' feet-\'" << room.width.inches << "\' inches" << endl;
	cout << "Length of the room is : \'" << room.length.feet << "\' feet-\'" << room.length.inches << "\' inches" << endl;

	l = room.length.feet + room.length.inches/12.0;
	w = room.width.feet + room.width.inches/12.0;
	h = room.height.feet + room.height.inches/12.0;

	vol = l + w + h;
	cout << "volume of the room is : " << vol << endl;


	system("pause>0");
}
