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
	String(char s[]) { strcpy_s(str, s); }
	void display()const { cout << str << endl; }
	operator char* () { return str; }
};

class Pstring : public String {
public:
	Pstring() { String(); }
	Pstring(char s[]);
	void left(char s1[], int n);
	void mid(char s1[], int s, int n);
	void right(char s1[], int n);
};

int main() {
	char c1[] = "This string wil surely exceed the width of the screen, whiech is what the SZ constant represents";
	Pstring s1 = c1;
	cout << "s1 = "; s1.display();

	char c2[] = "Hello its me I was wondering";
	Pstring s2 = c2;
	cout << "s2 = "; s2.display();

	cout << "\n\n------------------------------------------\n" << endl;
	Pstring L;
	L.left(s2, 7);
	cout << "L = ";  L.display();

	Pstring M;
	M.mid(s2, 6, 12);
	cout << "M = ";  M.display();

	Pstring R;
	R.right(s2, 9);
	cout << "R = ";  R.display();
	


	return 0;
}

Pstring::Pstring(char s[]) {
	if (strlen(s) > SZ - 1) {
		for (int i = 0; i < SZ - 1; i++)
			str[i] = s[i];
		str[SZ - 1] = '\0';
	}
	else {
		strcpy_s(str, s);
	}
}
void Pstring::left(char s1[], int n) {
	for (int i = 0; i < n; i++) {
		str[i] = s1[i];
	}
	str[n] = '\0';
}
void Pstring::mid(char s1[], int s, int n) {// from s ....... n number of characters
	int nn = 0;
	for (int i = s; i < n; i++) {
		str[nn++] = s1[i];
	}
	str[n - s] = '\0';

}
void Pstring::right(char s1[], int n) {
	int nn = 0;
	for (int i = strlen(s1) - n; i < strlen(s1); i++) {
		str[nn++] = s1[i];
	}
	str[nn] = '\0';
}
