#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class linkedList {
	Node* head, * last;
	int size;
public:
	linkedList() : head(NULL), last(NULL), size(0) {}
	~linkedList() { clearList(); };
	bool isEmpty();
	int sizeLinkedList();
	int headLinkedList();
	int lastLinkedList();
	void insertFront(int val);
	void insertAt(int pos, int val);
	void insertEnd(int val);
	void deleteFront();
	void deleteAt(int pos);
	void clearList();
	void deleteEnd();
	void display();
};

int main() {
	linkedList lk;
	
	lk.insertFront(10);
	lk.insertFront(20);

	lk.display();

	lk.insertAt(2, 30);
	lk.display();

	lk.insertEnd(40);
	lk.display();

	lk.insertFront(5);
	lk.display();

	lk.deleteFront();
	lk.display();

	lk.deleteFront();
	lk.display();

	//lk.deleteAt(0);
	//lk.display();

	cout << "The head of lined list: " << lk.headLinkedList() << endl;
	cout << "The last of linked list: " << lk.lastLinkedList() << endl;

	lk.deleteEnd();
	lk.display();
	
	

	return 0;
}

bool linkedList::isEmpty() {
	return size == 0;
}
int linkedList::sizeLinkedList() {
	return size;
}
int linkedList::headLinkedList() {
	return head->data;
}
int linkedList::lastLinkedList() {
	return last->data;
}
void linkedList::insertFront(int val) {
	Node* newNode = new Node;
	newNode->data = val;

	if (head == NULL) {
		head = last = newNode;
		newNode->next = NULL;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	size++;
}
void linkedList::insertAt(int pos, int val) {
	if (pos<0 || pos >size)
		cout << "Error: out of range." << endl;
	else if (pos == size)
		insertEnd(val);

	else {
		Node* current = head;
		for (int i = 0; i < pos; i++)
			current = current->next;
		Node* newNode = new Node;
		newNode->data = val;

		newNode->next = current->next;
		current->next = newNode;
		size++;
	}
}
void linkedList::insertEnd(int val) {
	Node* newNode = new Node;
	newNode->data = val;

	if (head == NULL) {
		head = last = newNode;
		newNode->next = NULL;
	}
	else {
		last->next = newNode;
		newNode->next = NULL;
		last = newNode;
	}
	size++;
}
void linkedList::deleteFront() {
	if (isEmpty()) {
		cout << "Erroor: linked list is empty" << endl;
	}
	else {
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
}
void linkedList::deleteAt(int pos) {
	if (pos<0 || pos>=size)
		cout << "Error: out of range" << endl;
	else {
		Node* current, * temp;

		if (pos == 0) {
			current = head;
			head = head->next;
			delete current;
			size--;
			if (size == 0)
				last = NULL;
		}
		else {
			current = head->next;
			temp = head;

			for (int i = 1; i < pos; i++) {
				temp = current;
				current = current->next;
			}
			temp->next = current->next;
			if (last == current) {
				last = temp;
			}
			delete current;
			size--;
		}
	}
}
void linkedList::clearList() {
	Node* current = new Node;
	
	while (head != NULL) {
		current = head;
		head = head->next;
		delete current;
	}
	last = NULL;
	size = 0;
}
void linkedList::deleteEnd() {
	if (isEmpty())
		cout << "Error: linked list is empty." << endl;
	else if (size == 1) {
		delete head;
		head = last = NULL;
		size--;
	}
	else {
		Node* current = head->next;
		Node* temp = head;
		while (current != last) {
			temp = current;
			current = current->next;
		}
		temp->next = NULL;
		last = temp;
		delete current;
		size--;
	}
}
void linkedList::display() {
	Node* current = head;
	cout << "Linked List: [ ";
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << "]" << endl;
}
