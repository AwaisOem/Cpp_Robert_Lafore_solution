#include <iostream>
#include <process.h>
#include <cstring>
#include <string>

using namespace std;

class String {
	enum { SZ = 80 };
	char str[SZ];
public:
	String() { strcpy_s(str, ""); }
	String(char s[]) { strcpy_s(str, s); }
	void display() { cout << str << endl; }
	String operator += (String other) {
		String temp;
		if (strlen(str) + strlen(other.str) > SZ - 1) {
			cout << "String overflow." << endl;
			exit(1);
		}
		else {
			strcpy_s(temp.str, str);
			strcat_s(temp.str, other.str);
		}
		return temp;
	}
};

int main() {
	String s3;
	String s1 = "Hello It Is Me";
	String s2 = "I Was Wondering";
	s3 = s1 += s2;
	s1.display();
	s2.display();
	s3.display();


	return 0;
}
