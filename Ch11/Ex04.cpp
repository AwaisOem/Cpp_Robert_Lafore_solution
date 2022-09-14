#include <iostream>
#include <string>

using namespace std;

class publication {
protected:
	string title;
	float price;
public:
	virtual void getdata();
	virtual void putdata()const;
	virtual bool isOversize() = 0;
};

class book : public publication {
	int page_count;
public:
	void getdata();
	void putdata() const;
	bool isOversize();
};

class audiocassette : public publication {
	float tape;
public:
	void getdata();
	void putdata() const;
	bool isOversize();
};


int main() {
	publication* pubarr[100];
	int n = 0;
	char choice;

	do {
		cout << "Enter Book or Audiocassette (b/a)? ";
		cin >> choice;
		if (choice == 'b')
			pubarr[n] = new book;
		else
			pubarr[n] = new audiocassette;

		pubarr[n]->getdata();
		pubarr[n++]->isOversize();
		cout << "Enter another (y/n)? ";
		cin >> choice;
	} while (choice == 'y');

	for (int i = 0; i < n; i++) {
		pubarr[i]->putdata();
	}


	return 0;
}

void publication::putdata() const {
	cout << "Title: " << title << endl;
	cout << "Price: " << price << endl;
}
void publication::getdata() {
	cout << "Enter title: ";	cin >> title;
	cout << "Enter price: ";	cin >> price;
}
void book::getdata() {
	publication::getdata();
	cout << "Enter page count: ";	cin >> page_count;
}
void book::putdata() const {
	cout << "The data of book: " << endl;
	publication::putdata();
	cout << "Pages: " << page_count << endl;
	cout << endl;
}
void audiocassette::getdata() {
	publication::getdata();
	cout << "Enter duration of tape: ";		cin >> tape;
}
void audiocassette::putdata() const {
	cout << "The data of audiocassette: " << endl;
	publication::putdata();
	cout << "Tape: " << tape << endl;
	cout << endl;
}
bool book::isOversize() {
	if (page_count > 800) {
		int n = page_count / 800;
		cout << "Page count is oversize." << endl;
		cout << "so this book parted to " << n << " copiess" << endl;
		return true;
	}
	return false;
}
bool audiocassette::isOversize() {
	if (tape > 90) {
		int n = int(tape) / 90;
		cout << "Tape is oversize." << endl;
		cout << "so this audiocassette parted to " << n << " parts" << endl;
		return true;
	}
	return false;
}
