#include <iostream>

using namespace std;

double hms_to_secs(int h, int m, int s) {
	double sum = h * 3600 + m * 60 + s;
	return sum;
}

int main() {
	char ch;
	int hour, minute, second;
	cout << "Enter the time in this format (hh:mm:ss): ";
	cin >> hour >> ch >> minute >> ch >> second;
	cout << "The equivalent time in second is: " << hms_to_secs(hour, minute, second) << endl;

	return 0;
}
