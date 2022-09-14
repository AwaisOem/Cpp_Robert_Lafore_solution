#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void reversit(char[]);
const int MAX = 80;

int main() {
	char str[MAX];
	cout << "Enter the text that you want to reverse: " << endl;
	cin.get(str, MAX);
	reversit(str);
	cout << "The strign after reversing: " << endl;
	cout << str << endl;
	return 0;
}

void reversit(char s[]) {
	int len = strlen(s);
	for (int j = 0; j < len / 2; j++) {
		char temp = s[j];
		s[j] = s[len - j - 1];
		s[len - j - 1] = temp;
	}
}

