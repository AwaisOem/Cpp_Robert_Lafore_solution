#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
	int data;
	Node* next;
};
Node* head = NULL;
void display();
void insertNode(int);
void deleteNode(int);
void insertFromFront(int);
void deleteFromFront();
void deleteEnd();

int main() {
	insertNode(5);
	insertNode(10);
	insertNode(15);
	insertNode(20);
	insertNode(25);
	
	display();

	deleteEnd();
	display();


	system("pause>0");
}

void insertNode(int val) {
	Node* newNode = new Node;
	Node* last = new Node;
	newNode->data = val;
	
	if (head == NULL) {
		head = newNode;
		newNode->next = NULL;
	}
	else {
		last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = newNode;
		newNode->next = NULL;
	}
}

void deleteNode(int val) {
	Node* currentNode;
	Node* previousNode = new Node;

	currentNode = head;
	
	if (currentNode->data == val) {
		head = currentNode->next;
		delete currentNode;
		return;
	}

	while (currentNode->data != val) {
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	previousNode->next = currentNode->next;
	delete currentNode;


	
}

void display() {
	Node* current;
	if (head == NULL) {
		cout << "Linked list is empty" << endl;
	}
	else {
		current = head;
		while (current != NULL) {
			cout << current->data << "\t";
			current = current->next;
		}
	}
	cout << endl;
}

void insertFromFront(int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = head;
	head = newNode;
}

void deleteFromFront() {
	if (head == NULL) {
		cout << "Linked list is empty" << endl;
	}
	else {
		Node* FirstNode = new Node;
		FirstNode = head;
		head = FirstNode->next;
		delete FirstNode;
	}
}

void deleteEnd() {
	if (head == NULL)
		cout << "Linked list empty" << endl;
	else if (head->next == NULL) {
		delete head;
		head = NULL;
	}
	else {
		Node* ptr = new Node;
		ptr = head;
		while (ptr->next->next != NULL) {
			ptr = ptr->next;
		}
		delete ptr->next;
		ptr->next = NULL;
	}
}

// ios::out => mode to write
// ios::app => append mode to put data without deleting the previous data
// ios::in  => read mode 
/*
fstream myFile;
	myFile.open("Saldine.txt",ios::in);
	if (myFile.is_open()) {
		string line;
		while (getline(myFile, line)) {
			cout << line << endl;
		}
		myFile.close();
	}
*/
