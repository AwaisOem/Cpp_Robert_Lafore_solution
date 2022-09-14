#include <iostream>
using namespace std;

class Time {
private:
	int hours, minutes, seconds;
public:
	Time(): hours(0), minutes(0), seconds(0) {}
	Time(int h, int m, int s): hours(h), minutes(m), seconds(s) {}
	void display() {
		cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
	}

	void add(Time t1, Time t2) {
		hours = t1.hours + t2.hours;
		minutes = t1.minutes + t2.minutes;
		seconds = t1.seconds + t2.seconds;
	}
	Time operator +(const Time& other)const {
		Time temp;
		temp.hours = other.hours + hours;
		temp.minutes = other.minutes + minutes;
		temp.seconds = other.seconds + seconds;
		return temp;
	}
};

int main(){
	Time time1, time2, time3, time4;
	time1 = { 6, 34, 29 };
	time2 = { 6, 25, 30 };
	time3.add(time1, time2);
	time3.display();
	
	time4 = time1 + time2;
	time4.display();


	return 0;
}
