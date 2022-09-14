#include <iostream>
#include <process.h>

using namespace std;
const int MAX = 100;
class Queue {
	int front;
	int arr[MAX];
public:
	Queue(): front(-1) {}
	bool isEmpty() {
		return (front >= 0) ? false : true;
	}
	void push(int element) {
		if (front < 100) {
			arr[++front] = element;
			cout << element << " Pushed into Queue" << endl;
		}
		else {
			cout << "Queue is overflow" << endl;
		}
	}
	void pop() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return;
		}
		else {
			for (int i = 0; i <= front; i++) {
				arr[i] = arr[i + 1];
			}
			front--;
		}
	}
	void display() {
		cout << "The elments of the Queue: [ ";
		for (int i = 0; i <= front; i++) {
			cout << arr[i] << " ";
		}
		cout << "]." << endl;
	}
	int peek() {
		if (front < 0) {
			cout << "Queue is empty" << endl;
			return 0;
		}
		else {
			int x = arr[0];
			return x;
		}
	}
};

int main() {
	Queue q;
	q.push(3);
	q.push(9);
	q.push(27);
	q.push(81);
	q.display();
	q.pop();
	q.display();
	cout << q.peek() << endl;
	

	return 0;
}

