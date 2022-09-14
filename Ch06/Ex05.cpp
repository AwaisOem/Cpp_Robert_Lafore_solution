#include <iostream>
using namespace std;

class date {
private:
	int year, month, day;
public:
	void getdate();
	void showdate();
};

void date::getdate() {
	char ch;
	cout << "Enter date in this format(dd/mm/yyyy): ";
	cin >> day >> ch >> month >> ch >> year;
}
void date :: showdate() {
	cout << "the date is: " << day << "/" << month << "/" << year << endl;
}

int main() {
	date d1;
	d1.getdate();
	d1.showdate();

	return 0;
}
