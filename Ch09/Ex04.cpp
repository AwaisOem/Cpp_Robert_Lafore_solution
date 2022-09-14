#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class publication {
	enum { SZ = 30 };
	char title[SZ];
	float price;
public:
	publication() : title(""), price(0.0) {}
	publication(char s[], float pr) { strcpy_s(title, s); price = pr; }
	void getdata() {
		cout << "Enter title: "; cin >> title;
		cout << "Enter price: "; cin >> price;
	}
	void putdata() {
		cout << "Title: " << title << endl;
		cout << "Price: " << price << endl;
	}
};

class Sales {
	float sales[3];
public:
	Sales() {
		sales[0] = 0.0;
		sales[1] = 0.0;
		sales[2] = 0.0;
	}
	Sales(float arr[]) {
		for (int i = 0; i < 3; i++)
			sales[i] = arr[i];
	}
	void getdata() {
		for (int i = 0; i < 3; i++) {
			cout << "Enter sales amount of month " << i + 1 << ": ";
			cin >> sales[i];
		}
	}
	void putdata()const {
		for (int i = 0; i < 3; i++) {
			cout << "Month " << i + 1 << ": amount sales: " << sales[i] << endl;
		}
	}
};

class book : public publication, public Sales {
	int page_count;
public:
	book() : publication(), page_count(0), Sales() {}
	book(char s[], float price, int p_c, float arr[]) : publication(s, price), page_count(p_c), Sales(arr) {}
	void getdata() {
		publication::getdata();
		cout << "Enter page count: "; cin >> page_count;
		Sales::getdata();
	}
	void putdata() {
		publication::putdata();
		cout << "Page Count: " << page_count << endl;
		Sales::putdata();
	}
};

class audiocassette : public publication, public Sales {
	float tape;
public:
	audiocassette() : publication(), tape(0.0), Sales() {}
	audiocassette(char s[], float price, float tp, float arr[]) : publication(s, price), tape(tp), Sales(arr) {}
	void getdata() {
		publication::getdata();
		cout << "Enter tape(number of minutes): "; cin >> tape;
		Sales::getdata();
	}
	void putdata() {
		publication::putdata();
		cout << "Tape: " << tape << endl;
		Sales::putdata();
	}
};

enum Disk{CD, DVD};
class disk : public publication, public Sales {
	Disk d;
public:
	disk() : publication(), d(Disk(0)), Sales() {}
	disk(char s[], float price, Disk di, float arr[]) : publication(s, price), d(di), Sales(arr) {}
	void getdata() {
		publication::getdata();
		char ch;
		cout << "Choise the type of disk: " << endl;
		cout << "Enter c for CD or d for DVD: "; cin >> ch;
		switch (ch) {
		case 'c':
			d = Disk(0);
			break;
		case 'd':
			d = Disk(1);
			break;
		}
		Sales::getdata();
	}
	void putdata() {
		publication::putdata();

		cout << "Disk type: ";
		switch (d) {
		case 0:
			cout << "CD" << endl;
			break;
		case 1:
			cout << "DVD" << endl;
			break;
		}
		Sales::putdata();
	}
	
};


int main() {
	book b[10];
	audiocassette a[10];
	disk d[10];

	char ch;
	float arr1[] = { 66.84F, 56.54F, 76.71F };
	float arr2[] = { 50.45F, 50.45F, 69.82F };
	char str1[] = "Programming";
	char str2[] = "Something We Want";
	char str3[] = "Inception";
	book b1(str1, 56.54F, 490, arr1);
	audiocassette a1(str2, 68.99F, 59.4F, arr2);
	disk d1(str3, 92.15F, Disk(0), arr2);

	cout << "The information of a1: " << endl;
	a1.putdata();

	cout << "\nThe information of b1: " << endl;
	b1.putdata();

	cout << "\nThe information of d1: " << endl;
	d1.putdata();

	int i = 0, j = 0, k = 0;
	do {
		cout << "\nEnter A to insert audiocassette, B to insert book, D to insert disk: ";
		cin >> ch;
		if (ch == 'a' || ch == 'A') {
			a[i].getdata();
			i++;
		}
		else if (ch == 'b' || ch == 'B') {
			b[j].getdata();
			j++;
		}
		else if (ch == 'd' || ch == 'D') {
			d[k].getdata();
			k++;
		}
		cout << "Continue? (Y/N): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	if(j>0)
		cout << "\nThe information of Books: " << endl;
	for (int i = 0; i < j; i++)
		b[i].putdata();

	if(i>0)
		cout << "\nThe information of audiocassette: " << endl;
	for (int j = 0; j < i; j++) {
		a[j].putdata();
	}

	if(k>0)
		cout << "\nThe information of disk: " << endl;
	for (int i = 0; i < k; i++) {
		d[i].putdata();
	}


	return 0;
}
