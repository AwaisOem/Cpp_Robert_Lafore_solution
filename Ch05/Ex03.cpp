#include<iostream>
using namespace std;

void smaller(int& a, int& b) {
	if (a > b) {
		b = 0;
	}
	else
		a = 0;
}
int main() {
	int x, y;
	cout << "Enter two numbers: "; cin >> x >> y;
	smaller(x, y);
	cout << "The first number is: " << x << endl;
	cout << "The second number is: " << y << endl;
	return 0;
}
