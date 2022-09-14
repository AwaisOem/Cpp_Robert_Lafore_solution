#include <iostream>
#include <cmath>
using namespace std;

class Int {
	int x;
public:
	Int(int X = 0) : x(X) {}
	void getter() {
		cout << "Enter number: "; cin >> x;
	}
	void display() { cout << x << endl; }
	Int operator +(Int other) {
		return Int(other.x + x);
	}
	Int operator -(Int other) {
		return Int(abs(other.x - x));
	}
	Int operator *(Int other) {
		return Int(other.x * x);
	}
	Int operator /(Int other) {
		return Int(other.x / x);
	}
	//operator int() { return Int(x); }
	Int check_if(long double answer) {
		if (answer > 2147483647.0L || answer < -2147483647.0L) { cout << "Overflow error"; exit(1); }
		return Int(int(answer));
	}
};

int main() {
	Int a, b, c;
	a = { 38 };
	b.getter();
	cout << "The value of a: "; a.display();
	cout << "The value of b: "; b.display();

	c = a + b;
	cout << "The sum of a and b: "; c.display();

	c = a - b;
	cout << "The a minus b is: "; c.display();

	c = a * b;
	cout << "The multiple of a and b: "; c.display();

	c = a / b;
	cout << "The a divide by b is: "; c.display();
			
	system("pause");
	return 0;
}
