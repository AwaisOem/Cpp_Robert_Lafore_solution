#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class linkedList {
	Node* head;
	int length;
public:
	linkedList() {
		head = nullptr;
		length = 0;
	}
	~linkedList() {
		Node* curr = head;
		while (curr != nullptr) {
			Node* temp = curr;
			curr = curr->next;
			delete temp;
		}
	}
	void add_item(int val) {
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = head;
		head = newNode;
		length++;
	}
	void display() {
		Node* curr = head;
		while (curr != nullptr) {
			cout << curr->data << ' ';
			curr = curr->next;
		}
		cout << endl;
	}
	// copy constructor
	linkedList(linkedList& li) {
		Node* curr = li.head;
		while (curr != nullptr) {
			this->add_item(curr->data);
			curr = curr->next;
		}
	}

	// Assignment operator
	linkedList& operator =(linkedList& li) {
		Node* curr = li.head;
		while (curr != nullptr) {
			this->add_item(curr->data);
			curr = curr->next;
		}
		return *this;
	}
};

int main() {
	linkedList li;

	li.add_item(10);
	li.add_item(20);
	li.add_item(30);
	li.add_item(40);
	li.add_item(50);

	li.display();

	linkedList li2(li);

	li2.display();

	linkedList li3 = li;

	std::cout << "li3 = ";
	li3.display();


	return 0;
}

