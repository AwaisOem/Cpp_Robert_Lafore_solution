#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int day = 7;
void bsort(char**, int);
void order(char**, char**);

int main() {
	char d1[] = "Sunday"; char d2[] = "Monday"; char d3[] = "Thuesday"; char d4[] = "Wednesday";
	char d5[] = "Thursday"; char d6[] = "Friday"; char d7[] = "Saturday";

	char* week[day] = { d1, d2, d3, d4, d5, d6, d7 };
	
	cout << "Unsorted: " << endl;
	for (int i = 0; i < day; i++)
		cout << *(week + i) << endl;
	
	bsort(week, day);
	cout << "\nsorted: " << endl;
	for (int i = 0; i < day; i++)
		cout << *(week + i) << endl;	

	return 0;
}

void bsort(char** p, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			order(p + i, p + j);
}

void order(char** p1, char** p2) {
	if (strcmp(*p1, *p2)>0) {
		char* temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
}
