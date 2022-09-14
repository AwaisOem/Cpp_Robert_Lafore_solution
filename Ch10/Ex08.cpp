#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct link {
	int data;
	link* next;
};

class linklist {
	link* first;
public:
	linklist();
	void display();
	void additem(int);
};

int main() {
	linklist li;

	li.additem(25);
	li.additem(36);
	li.additem(49);
	li.additem(64);

	li.display();


	return 0;
}

linklist::linklist() {
	first = NULL;
}
void linklist::additem(int val) {
	link* newLink = new link();
	link* last = first;

	newLink->data = val;
	newLink->next = NULL;

	if (first == NULL) {
		first = newLink;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = newLink;
}
void linklist::display() {
	while (first != NULL) {
		cout << first->data << endl;
		first = first->next;
	}
}
