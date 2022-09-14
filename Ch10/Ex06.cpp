#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int compstr(char* s1, char* s2) {
	int len = 0;
	len = (len <= strlen(s2)) ? len : strlen(s2);
	for (int i = 0; i < len; i++) {
		if (tolower(*(s1 + i)) > tolower(*(s2 + i)))
			return 1;
		else if (tolower(*(s1 + i)) < tolower(*(s2 + i)))
			return -1;
	}
	if (strlen(s1) < strlen(s2))
		return -1;
	else if (strlen(s1) > strlen(s2))
		return 1;
	else
		return 0;
}

int main() {
	char s1[] = "Apple";
	char s2[] = "Banana";
	char s3[] = "Watermelon";
	char s4[] = "Cherries";
	char s5[] = "apple";

	cout << "Compare(s1, s2): " << compstr(s1, s2) << endl;
	cout << "Compare(s2, s3): " << compstr(s2, s3) << endl;
	cout << "Compare(s3, s4): " << compstr(s3, s4) << endl;
	cout << "Compare(s1, s5): " << compstr(s1, s5) << endl;


	return 0;
}
