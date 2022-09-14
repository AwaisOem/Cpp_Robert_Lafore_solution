#include <iostream>

using namespace std;

const int LEN = 80;
class student {
	char school[LEN];
	char degree[LEN];
public:
	void getedu();
	void putedu()const;
};

class employee {
	char name[LEN];
	unsigned long number;
public:
	void getdata();
	void putdata()const;
};

class manager : private employee, private student {
	char title[LEN];
	double dues;
public:
	void getdata();
	void putdata()const;
};

class executive : private manager {
	float yearly_of_bonus;
	int n_of_shares;
public:
	executive() : manager(), yearly_of_bonus(0.0), n_of_shares(0) {}
	void getdata();
	void putdata()const;
};

class scientist : private employee, private student {
	int pubs;
public:
	void getdata();
	void putdata()const;
};

class laborer : public employee {

};

int main() {
	executive e1;
	scientist s1;
	laborer l1;

	cout << "Enter data for Manager: " << endl;
	e1.getdata();

	cout << "\nEnter data for Scientist: " << endl;
	s1.getdata();

	cout << "\nEnter data for Laborer: " << endl;
	l1.getdata();

	cout << "\nThe data of Manager: " << endl;
	e1.putdata();

	cout << "\nThe data of Scientist: " << endl;
	s1.putdata();

	cout << "\nThe data of Laborer: " << endl;
	l1.putdata();


	return 0;
}

void student::getedu() {
	cout << "Enter name of school: "; cin >> school;
	cout << "Enter highest degree: "; cin >> degree;
}
void student::putedu()const {
	cout << "School: " << school << endl;
	cout << "Highest degree: " << degree << endl;
}
void employee::getdata() {
	cout << "Enter name: "; cin >> name;
	cout << "Enter number: "; cin >> number;
}
void employee::putdata()const {
	cout << "Name: " << name << endl;
	cout << "Number: " << number << endl;
}
void manager::getdata() {
	employee::getdata();
	cout << "Enter title: "; cin >> title;
	cout << "Enter golf club dues: "; cin >> dues;
	student::getedu();
}
void manager::putdata()const {
	employee::putdata();
	cout << "Title: " << title << endl;
	cout << "Golf Club Dues: " << dues << endl;
	student::putedu();
}
void executive::getdata() {
	manager::getdata();
	cout << "Enter size of employees yearly bonus: "; cin >> yearly_of_bonus;
	cout << "Enter number of shares company: ";		  cin >> n_of_shares;
}
void executive::putdata()const {
	manager::putdata();
	cout << "Yearly bonus: " << yearly_of_bonus;
	cout << "Shares company: " << n_of_shares;
}
void scientist::getdata() {
	employee::getdata();
	cout << "Enter number of pubs: "; cin >> pubs;
	student::getedu();
}
void scientist::putdata()const {
	employee::putdata();
	cout << "Number Of Publications: " << pubs << endl;
	student::putedu();
}
