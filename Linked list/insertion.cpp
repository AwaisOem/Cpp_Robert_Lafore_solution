#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void display(Node*);
void insertAtTheFront(Node** head, int val);
void insertAfter(Node* previous, int val);
void insertAtTheEnd(Node** head, int val);

int main() {
	Node* head = new Node;
	Node* second = new Node;
	Node* third = new Node;

	head->data = 10;
	head->next = second;
	second->data = 20;
	second->next = third;
	third->data = 30;
	third->next = NULL;

	display(head);


	insertAtTheFront(&head, 8);
	display(head);

	insertAfter(second, 27);
	display(head);

	insertAtTheEnd(&head, 33);
	display(head);

	system("pause>0");
}

void display(Node* n) {
	cout << "Linked list [ ";
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << " ]" << endl;
}
void insertAtTheFront(Node** head, int val) {
	Node* newNode = new Node;
	newNode->data = val;

	newNode->next = *head; // first
	*head = newNode;	  //  second
}
void insertAfter(Node* previous, int val) {
	if (previous == NULL) {
		cout << "Previous node can not be NULL" << endl;
		return;
	}

	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = previous->next;
	previous->next = newNode;
}
void insertAtTheEnd(Node** head, int val) {
	Node* newNode = new Node;
	Node* last = new Node;
	newNode->data = val;
	newNode->next = NULL;
	last = *head;

	if (*head == NULL) {
		*head = newNode;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = newNode;
}
