#include <iostream>
using namespace std;

class serailnumberCount {
private:
	static int count;	
	unsigned int serialNumber; 
public:
	serailnumberCount() {	
		count++;
		serialNumber = count;
	}
	void dispserailNumber() const;	
};

int serailnumberCount::count = 0;	

void serailnumberCount::dispserailNumber() const {	
	cout << "Object number " << serialNumber;
}

int main() {
	serailnumberCount obj1, obj2, obj3;	
	obj1.dispserailNumber();	
	cout << endl;
	obj2.dispserailNumber();	
	cout << endl;
	obj3.dispserailNumber();	
	cout << endl;
	return 0;
}
