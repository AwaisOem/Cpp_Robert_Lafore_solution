#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class publication {
	string title;
	float price;
public:
	void getdata() {
		cout << "Enter title: "; cin >> title;
		cout << "Enter price: "; cin >> price;
	}
	void putdata() {
		cout << "Title: " << title << endl;
		cout << "Price: " << price << endl;
	}
};

class book : public publication {
	int page_count;
public:
	void getdata() {
		publication::getdata();
		cout << "Enter page count: "; cin >> page_count;
	}
	void putdata() {
		publication::putdata();
		cout << "Page Count: " << page_count << endl;
	}
};

class audiocassette : public publication {
	float tape;
public:
	void getdata() {
		publication::getdata();
		cout << "Enter tape(number of minutes): "; cin >> tape;
	}
	void putdata() {
		publication::putdata();
		cout << "Tape: " << tape << endl;
	}
};


int main() {
	book b[10];
	audiocassette a[10];
	char ch;
	int i = 0, j = 0;
	do {
		cout << "Enter A to insert audiocassette, B to insert book: ";
		cin >> ch;
		if (ch == 'a' || ch == 'A') {
			a[i].getdata();
			i++;
		}
		else if (ch == 'b' || ch == 'B') {
			b[j].getdata();
			j++;
		}
		cout << "Continue? (Y/N): "; 
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	cout << "\nThe information of Books: " << endl;
	for (int i = 0; i < j; i++)
		b[i].putdata();

	cout << "\nThe information of audiocassette: " << endl;
	for (int j = 0; j < i; j++) {
		a[j].putdata();
	}


	return 0;
}
