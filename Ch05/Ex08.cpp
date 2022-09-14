#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int x = 10;
	int y = 20;
	cout << "x and y without swapping x = " << x << ", y = " << y << endl;
	swap(x, y);
	cout << "x and y after swapping x = " << x << ", y = " << y << endl;

	return 0;
}
