#include <iostream>

struct Node {
	int data;
	Node* next;
};

class linkedList {
	Node* head;
public:
	linkedList();
	~linkedList();
	bool isEmpty();
	bool isFull();
	int length_iterative();
	int helper(Node*p) {
		if (p != nullptr)
			return 1 + helper(p->next);
		else
			return 0;
	}
	int length_recursion() {
		int len = helper(head);
		return len;
	}
	void insertFirst(int x);
	void insertEnd(int x);
	void insertAt(int pos, int x);
	int deleteFirst();
	int deleteEnd();
	int deleteAt(int pos);
	int deleteAtKey(int key) {
		if (isEmpty()) {
			std::cout << "list is empty anyway" << std::endl;
			return -1;
		}
		if (head->data == key) {
			Node* p = head;
			head = head->next;
			delete p;
		}
		else {
			Node* p = head->next;
			Node* prev = head;
			while (p->data != key && p != nullptr) {
				prev = p;
				p = p->next;
			}

			prev->next = p->next;
			delete p;
		}

		return key;
	}
	void modify(int x) {
		Node* p = head;
		while (p) {
			p->data += x;
			p = p->next;
		}
	}
	void sortList() {
		int* arr = new int[length_iterative()];
		Node* p = head;
		int i = 0;
		arr[i++] = p->data;
		while (p) {
			p = p->next;
			if (p != nullptr)
				arr[i++] = p->data;
		}
		for (int j = 0; j < i; j++)
			std::cout << arr[j] << ' ';
	}
	void reverse() {
		Node* p = head;
		Node* q = nullptr;
		Node* temp = nullptr;

		while (p) {
			temp = p->next;
			p->next = q;
			q = p;
			p = temp;
		}
		head = q;
	}
	
	void display();
};

int main() {

	linkedList lk;

	lk.insertFirst(11);
	lk.insertFirst(22);
	lk.insertFirst(33);
	lk.insertFirst(44);

	lk.display();

	lk.insertEnd(5);
	lk.display();

	lk.insertAt(2, 39);
	lk.display();

	//std::cout << lk.deleteFirst() << " has been deleted" << std::endl;
	//lk.display();

	//std::cout << lk.deleteEnd() << " has been deleted" << std::endl;
	//lk.display();

	//std::cout << lk.deleteAt(2) << " has been deleted" << std::endl;
	//lk.display();

	//std::cout << lk.deleteAtKey(22) << " has been deleted" << std::endl;
	//lk.display();

	//std::cout << "the length of list: " << lk.length_recursion() << std::endl;
	//std::cout << "the length of list: " << lk.length_iterative() << std::endl;

	//lk.modify(3);
	//lk.display();
	
	lk.reverse();
	lk.display();


	

	return 0;

}


linkedList::linkedList() {
	head = new Node;
	head = nullptr;
}

linkedList::~linkedList() {
	Node* curr = head;
	while (curr) {
		Node* temp = curr->next;
		delete curr;
		curr = temp;
	}

	head = nullptr;
}

bool linkedList::isEmpty() {
	return head == nullptr;
}

bool linkedList::isFull() {
	Node* t = new Node;
	return t == nullptr;
}

int linkedList::length_iterative() {
	int count = 0;
	Node* p = head;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}

void linkedList::insertFirst(int x) {
	Node* t = new Node;
	t->data = x;
	t->next = head;
	head = t;
}

void linkedList::insertEnd(int x) {
	Node* t = new Node;
	t->data = x;
	t->next = nullptr;

	if (head == nullptr)
		head = t;
	else {
		Node* last = head;
		while (last->next) {
			last = last->next;
		}

		last->next = t;
		last = t;
	}
}

void linkedList::insertAt(int pos, int x) {
	if (pos<0 || pos>length_iterative()) {
		std::cout << "position is out of range" << std::endl;
		return;
	}

	Node* t = new Node;
	t->data = x;

	if (pos == 0) {
		insertFirst(x);
	}
	else {
		Node* p = head;
		for (int i = 1; i < pos - 1; i++)
			p = p->next;

		t->next = p->next;
		p->next = t;
	}
}

int linkedList::deleteFirst() {
	if (isEmpty()) {
		std::cout << "list is empty anyway" << std::endl;
		return -1;
	}

	Node* p = head;
	head = head->next;
	int x = p->data;
	delete p;

	return x;
}

int linkedList::deleteEnd() {
	if (isEmpty()) {
		std::cout << "list is empty anyway" << std::endl;
		return -1;
	}
	int x;
	
	if (head->next == nullptr) {
		x = head->data;
		delete head;
	}
	else {
		Node* p = head;
		while (p->next->next != nullptr)
			p = p->next;
		x = p->next->data;
		delete p->next;
		p->next = nullptr;
	}

	return x;
}

int linkedList::deleteAt(int pos) {
	if (pos<1 || pos>length_iterative()) {
		std::cout << "position is out of range" << std::endl;
		return -1;
	}

	Node* p = head;
	int x;
	if (pos == 1) {
		head = head->next;
		x = p->data;
		delete p;
	}
	else {
		Node* q = p;
		for (int i = 0; i < pos - 1; i++) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
	}

	return x;
}

void linkedList::display() {
	Node* p = head;
	while (p!=nullptr) {
		std::cout << p->data << ' ';
		p = p->next;
	}
	std::cout << std::endl;
}
