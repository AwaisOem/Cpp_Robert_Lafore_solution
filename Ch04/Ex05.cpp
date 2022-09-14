#include <iostream>
using namespace std;

struct date {
	int year;
	int month;
	int day;
};

int main() {
	date d1;
	cout << "Enter the date in day/month/year: ";
	cin >> d1.day >> d1.month >> d1.year;

	cout << "The date is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	return 0;
}
