#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class String {
protected:
	enum { SZ = 80 };
	char str[SZ];
public:
	String() { str[0] = '\0'; }
	String(char s[]) { strcpy_s(str, s);}
	void display()const { cout << str << endl; }
	operator char* () { return str; }
};

class Pstring : public String {
public:
	Pstring(char s[]) {
		if (strlen(s) > SZ - 1) {
			for (int i = 0; i < SZ - 1; i++)
				str[i] = s[i];
			str[SZ - 1] = '\0';
		}
		else {
			strcpy_s(str, s);
		}
	}
};

int main() {
	char c1[] = "This string wil surely exceed the width of the screen, whiech is what the SZ constant represents";
	Pstring s1 = c1;
	cout << "s1 = "; s1.display();

	char c2[] = "Hello its me I was wondering";
	Pstring s2 = c2;
	cout << "s2 = "; s2.display();


	return 0;
}
