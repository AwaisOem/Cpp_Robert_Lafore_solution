#include <iostream>

using namespace std;

struct Time {
	int hour;
	int minute;
	int second;
	char ch;
};
void swap(Time&, Time&);
void display(Time t) {
	cout << t.hour << ":" << t.minute << ":" << t.second << endl;
}
int main() {
	Time t1, t2;
	cout << "Enter the first time like this format hh:mm:ss : "; 
	cin >> t1.hour >> t1.ch >> t1.minute >> t1.ch >> t1.second;
	cout << "Enter the second time like this fromat hh:mm:ss : ";
	cin >> t2.hour >> t2.ch >> t2.minute >> t2.ch >> t2.second;
	swap(t1, t2);
	cout << "After swapping : " << endl;
	cout << "The first time is : "; display(t1);
	cout << "The second time is : "; display(t2);
	
	return 0;
}

void swap(Time& t1, Time& t2) {
	int temp = t1.hour;
	t1.hour = t2.hour;
	t2.hour = temp;

	temp = t1.minute;
	t1.minute = t2.minute;
	t2.minute = temp;

	temp = t1.second;
	t1.second = t2.second;
	t2.second = temp;
}
