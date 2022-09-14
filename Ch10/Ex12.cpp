#include <iostream>

using namespace std;

const int MAX = 10;
float fmemory[MAX] = { 0.0 };
float fmem_top = 0;
int pmemory[MAX] = { 0 };
int pmem_top = 0;

class Float {
	int addr;
public:
	Float(float val) {
		addr = fmem_top++;
		fmemory[addr] = val;
	}
	int operator &() {
		return addr;
	}
};

class ptrFloat {
	int addr;
public:
	ptrFloat(int index) {
		addr = pmem_top++;
		pmemory[addr] = index;
	}
	float& operator *() {
		return fmemory[pmemory[addr]];
	}
};

int main() {
	Float val1 = 1.234;
	Float val2 = 5.678;

	ptrFloat ptr1 = &val1;
	ptrFloat ptr2 = &val2;

	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;

	*ptr1 = 7.123;
	*ptr2 = 8.456;

	cout << endl;
	cout << "*ptr1 = " << *ptr1 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;



	return 0;
}
