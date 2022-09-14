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
	void add_item(int);
	void display();
	~linklist();
};

int main() {
	linklist li;

	li.add_item(10);
	li.add_item(20);
	li.add_item(30);
	li.add_item(40);
	li.add_item(50);

	li.display();
	

	return 0;
}

linklist::linklist() {
	first = NULL;
}
void linklist::add_item(int d) {
	link* newLink = new link;
	newLink->data = d;
	newLink->next = first;
	first = newLink;
}
void linklist::display() {
	link* current = first;
	while (current != NULL) {
		cout << current->data << endl;
		current = current->next;
	}
}
linklist::~linklist() {
	link* current = first;
	while (current != NULL) {
		link* temp = current;
		cout << "item " << current->data << " has been destroyed." << endl;
		current = current->next;
		delete temp;
	}
}
