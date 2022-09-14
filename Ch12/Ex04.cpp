#include <iostream>
#include <fstream>
#include <process.h>

class employee {
	enum {mx = 40};
	char name[mx];
	unsigned long long int number;
public:
	employee() : name(""), number(0) {}
	employee(char* n, unsigned long long num) {
		strcpy_s(name, n);
		number = num;
	}
	friend std::ostream& operator <<(std::ostream&, employee&);
	friend std::istream& operator >>(std::istream&, employee&);
};

int main() {
	employee emp;
	char ch;

	std::ofstream outfil;
	outfil.open("emp.dat", std::ios::binary);

	do {
		std::cout << "\nEnter info of employee: ";
		std::cin >> emp;
		
		outfil.write((char*)&emp, sizeof(emp));
		
		std::cout << "Enter another (y/n)? ";
		std::cin >> ch;
		std::cin.ignore(10, '\n');
	} while (ch == 'y');
	outfil.close();

	std::ifstream infile;
	infile.open("emp.dat", std::ios::binary);

	infile.read((char*)&emp, sizeof(emp));
	while (!infile.eof()) {
		std::cout << emp << std::endl;

		infile.read((char*)&emp, sizeof(emp));
	}
	

	return 0;
}

std::ostream& operator <<(std::ostream& s, employee& e) {
	s << "\n    Name: " << e.name;
	s << "    Number: " << e.number;
	return s;
}

std::istream& operator >>(std::istream& s, employee& e) {
	std::cout << "\n    Enter name: ";
	s >> e.name;
	std::cout << "    Enter Number: ";
	s >> e.number;
	return s;
}
