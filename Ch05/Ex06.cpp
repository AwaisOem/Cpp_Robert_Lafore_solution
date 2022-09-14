#include <iostream>

using namespace std;

struct Time {
	int hour;
	int minute;
	int second;
	char ch;
};

double time_to_secs(Time t) { 
	 return double(t.hour * 3600 + t.minute * 60 + t.second);
}
Time secs_to_time(double d) {
	Time t;
	t.second = static_cast<int>(d) % 60;
	t.hour = d / 3600;
	d = d - t.hour*3600;
	t.minute = d / 60;
	
	return t;
}

int main() {
	
	Time t1, t2;
	cout << "Enter the time in format hh:mm:ss : ";
	cin >> t1.hour >> t1.ch >> t1.minute >> t1.ch >> t1.second;
	cout << "The seconds of this time is: " << time_to_secs(t1) << endl;
	double d;
	cout << "Enter seconds to convert them to time: ";
	cin >> d;
	t2 = secs_to_time(d);
	cout << "the time of this seconds: " << t2.hour << ":" << t2.minute << ":" << t2.second << endl;

	return 0;
}
