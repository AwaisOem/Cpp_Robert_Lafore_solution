#include <iostream>
#include <string>

using namespace std;

const int LEN = 80;
class employee {
	char name[LEN];
	unsigned long number;
public:
	void getdata();
	void putdata()const;
};

enum period { hourly = 0, weekly, monthly };
class employee2 : public employee {
	double compensation;
	period per;
public:
	void getdata();
	void putdata()const;
};

class manager : public employee2 {
	char title[LEN];
	double club_dues;
public:
	void getdata();
	void putdata()const;
};

class scientist : public employee2 {
	int publications;
public:
	void getdata();
	void putdata()const;
};

class laborer : public employee2 {
public:
	void getdata();
	void putdata()const;
};



int main() {
	manager mng;
	scientist sci;
	laborer lab;
	
	cout << "Enter data for Manager 1: " << endl;
	mng.getdata();

	cout << "\nEnter data for Scientist 1: " << endl;
	sci.getdata();

	cout << "\nEnter data for Laborer 1: " << endl;
	lab.getdata();

	cout << "\nThe information of Manager 1: " << endl;
	mng.putdata();

	cout << "\nThe information of Scientist 1: " << endl;
	mng.putdata();

	cout << "\nThe information of Laborer 1: " << endl;
	lab.putdata();

	return 0;
}

void employee::getdata() {
	cout << "Enter last name: "; cin >> name;
	cout << "Enter number: ";    cin >> number;
}
void employee::putdata()const {
	cout << "Name: " << name << endl;
	cout << "Number: " << number << endl;
}
void manager::getdata() {
	employee2::getdata();
	cout << "Enter title: ";	 cin >> title;
	cout << "Enter club dues: "; cin >> club_dues;
}
void manager::putdata()const {
	employee2::putdata();
	cout << "Title: " << title << endl;
	cout << "Club dues: " << club_dues << endl;
}
void scientist::getdata() {
	employee2::getdata();
	cout << "Enter number of publications: "; cin >> publications;
}
void scientist::putdata()const {
	employee2::putdata();
	cout << "Publications: " << publications << endl;
}
void laborer::getdata() {
	employee2::getdata();
}
void laborer::putdata()const {
	employee2::putdata();
}
void employee2::getdata() {
	employee::getdata();
	cout << "Enter amount of compensation: "; cin >> compensation;
	char ch;
	cout << "Choise paying period: " << endl;
	cout << "h for hourly, w for weekly, or m for monthly: "; cin >> ch;
	switch (ch) {
	case 'h':
		per = hourly;
		break;
	case 'w':
		per = weekly;
		break;
	case 'm':
		per = monthly;
	}
}
void employee2::putdata()const {
	employee::putdata();
	cout << "Compensation: " << compensation;
	cout << "Paying period: ";
	switch (per) {
	case 0:
		cout << "Hourly" << endl;
		break;
	case 1:
		cout << "Weekly" << endl;
		break;
	case 2:
		cout << "Monthly" << endl;
		break;
	}
}
