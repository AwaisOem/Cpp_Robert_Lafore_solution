#include <iostream>

using namespace std;

struct phone {
	int area_code;
	int exchange;
	int the_number;
};

int main() {
	phone phone1, phone2;

	phone1.area_code = 510;
	phone1.exchange = 853;
	phone1.the_number = 7840;

	cout << "Input your area code, exchange and the number : ";
	cin >> phone2.area_code >> phone2.exchange >> phone2.the_number;

	cout << "The first number is : (" << phone1.area_code << ")" << phone1.exchange << "-" << phone1.the_number << endl;
	cout << "The second number is : (" << phone2.area_code << ")" << phone2.exchange << "-" << phone2.the_number << endl;


	system("pause>0");
}
