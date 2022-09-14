#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class publication {
	enum { SZ = 20 };
	char title[SZ];
	float price;
public:
	publication() : title(""), price(0.0) {}
	publication(char s[], float pr) { strcpy_s(title, s); price = pr; }
	void getdata();
	void putdata()const;
};

class date {
	int year, month, day;
public:
	date() : year(0), month(0), day(0) {}
	date(int y, int m, int d) : year(y), month(m), day(d) {}
	void getdata();
	void putdata()const;
};

class publication2 : public date, public publication {
public:
	publication2() : publication::publication(), date::date() {}
	publication2(char s[], float pr, int y, int m, int d) : publication::publication(s, pr), date::date(y, m, d) {}
	void getdata();
	void putdata()const;
	
};

class book : public publication2 {
	int page_count;
public:
	book() : publication2(), page_count(0) {}
	book(char s[], float pr, int y, int m, int d, int p_c) : publication2(s, pr, y, m, d), page_count(p_c) {}
	void getdata();
	void putdata()const;
};

class audiocassette : public publication2 {
	float tape;
public:
	audiocassette() : publication2(), tape(0.0) {}
	audiocassette(char s[], float pr, int y, int m, int d, float tp) : publication2(s, pr, y, m, d), tape(tp) {}
	void getdata();
	void putdata()const;
};


int main() {
	char tit1[] = "Iheritance";
	char tit2[] = "Overloading";
	book b = { tit1, 176.49F, 2015, 11, 24, 492 };
	audiocassette a = { tit2, 216.99F, 2020, 12, 18, 45.52 };
	
	cout << "The data of first book: " << endl;
	b.putdata();

	cout << "\nThe data of first audiocassette: " << endl;
	a.putdata();


	book books[10];
	audiocassette audiocassettes[10];
	char ch;
	int i = 0, j = 0;
	cout << endl;
	do {
		cout << "Enter A to insert audiocassette, B to insert book: ";
		cin >> ch;
		if (ch == 'a' || ch == 'A') {
			audiocassettes[i].getdata();
			i++;
		}
		else if (ch == 'b' || ch == 'B') {
			books[j].getdata();
			j++;
		}
		cout << "Continue? (Y/N): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	cout << "\nThe information of Books: " << endl;
	for (int i = 0; i < j; i++)
		books[i].putdata();

	cout << "\nThe information of audiocassette: " << endl;
	for (int j = 0; j < i; j++) {
		audiocassettes[j].putdata();
	}


	return 0;
}
void publication::getdata() {
	cout << "Enter title: "; cin >> title;
	cout << "Enter price: "; cin >> price;
}
void publication::putdata()const {
	cout << "Title: " << title << endl;
	cout << "Price: " << price << "$" << endl;
}
void date::getdata() {
	char ch;
	cout << "Enter date (in this format YY.MM.DD): ";
	cin >> year >> month >> day;
}
void date::putdata()const {
	cout << "Date: " << year << "." << month << "." << day << endl;
}
void publication2::getdata() {
	publication::getdata();
	date::getdata();
}
void publication2::putdata()const {
	publication::putdata();
	date::putdata();
}
void book::getdata() {
	publication2::getdata();
	cout << "Enter page count: "; cin >> page_count;
}
void book::putdata()const {
	publication2::putdata();
	cout << "Page Count: " << page_count << endl;
}
void audiocassette::getdata() {
	publication2::getdata();
	cout << "Enter tape(number of minutes): "; cin >> tape;
}
void audiocassette::putdata()const {
	publication2::putdata();
	cout << "Tape: " << tape << "S" << endl;
}
