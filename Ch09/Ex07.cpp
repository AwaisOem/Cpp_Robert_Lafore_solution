#include <iostream>

using namespace std;

class Counter {
protected:
	unsigned int count;
public:
	Counter() : count() {}
	Counter(int c) : count(c) {}
	unsigned int get_count() const { return count; }
	Counter operator ++() { return (++count); }
	Counter operator ++(int) { return (count++); }
};

class CountDn : public Counter {
public:
	CountDn() : Counter() {}
	CountDn(int c) : Counter(c) {}
	CountDn operator --() { return CountDn(--count); }
	CountDn operator --(int) { return CountDn(count--); }
};



int main() {
	CountDn c1;
	CountDn c2(100);

	cout << "c1 = " << c1.get_count() << endl;
	cout << "c2 = " << c2.get_count() << endl;

	cout << "With prefix increment: " << endl;
	++c1; ++c1; ++c1;
	cout << "c1 = " << c1.get_count() << endl;

	cout << "\nWith posfix incremen: " << endl;
	c1++; c1++;
	cout << "c1 = " << c1.get_count() << endl;

	cout << "\nWith prefix decrement: " << endl;
	--c2; --c2;
	cout << "c2 = " << c2.get_count() << endl;

	cout << "\nWith posfix decrement: " << endl;
	c2--; c2--;
	cout << "c2 = " << c2.get_count() << endl;

	CountDn c3 = --c2;
	cout << "\nc3 = " << c3.get_count() << endl;


	return 0;
}
