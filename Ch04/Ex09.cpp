#include<iostream>
using namespace std;
struct time {
	int hours;
	int minutes;
	int seconds;
	char ch;
};
int main() {
	time t1;
	cout << "Enter the time value (i.e hours, minutes, seconds): ";
	cin >> t1.hours >> t1.ch >> t1.minutes >> t1.ch >> t1.seconds;

	long totalsecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;

	cout << "Total number of seconds are: " << totalsecs << endl;

	return 0;
}
