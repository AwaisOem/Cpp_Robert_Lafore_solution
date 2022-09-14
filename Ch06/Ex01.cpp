#include <iostream>

using namespace std;

class Int {
private:
	int i;
public:
	Int() : i(0) {}
	Int(int val): i(val) {}
	void display() {
		cout << "The value of data: " << i << endl;
	}
	void add(Int n1, Int n2) {
		i = n1.i + n2.i;
	}
};

int main(){
	Int I1(2), I2(7), I3;
	I3.add(I1, I2);
	I1.display();
	I2.display();
	I3.display();

	return 0;
}
