#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <cctype>

using namespace std;

class String {
	char* str;
public:
	String(char* s) {
		int len = strlen(s);
		str = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
			str[i] = s[i];
	}
	~String() {
		cout << "Deleting str" << endl;
		delete[] str;
	}
	void display() {
		cout << str << endl;
	}
	void upit() {
		int n = strlen(str);
		for (int i = 0; i < n; i++)
			putchar(toupper(str[i]));
		cout << endl;
	}
};

int main() {
	char ch1[] = "Who know nothing doubts nothing.";
	String s1(ch1);

	s1.display();
	s1.upit();

	return 0;
}
