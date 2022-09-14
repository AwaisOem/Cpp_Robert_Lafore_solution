#include <iostream>
#include <process.h>

using namespace std;

struct Pair {
	int x, y;
	Pair() : x(0), y(0) {}
	Pair(int x, int y) { this->x = x; this->y = y; }
};

class Stack {
protected:
	enum {MAX = 10};
	int st[MAX];
	int top;
public:
	Stack() {
		top = -1;
		for (int i = 0; i < MAX; i++) {
			st[i] = 0;
		}
	}
	void push(int var) { st[++top] = var; }
	int pop() { return st[top--]; }
};

class Stack2 : public Stack {
public:
	void push(int var) {
		if (top >= MAX - 1) {
			cout << "Stack is full." << endl;
			exit(1);
		}
		Stack::push(var);
	}
	int pop() {
		if (top < 0) {
			cout << "Stack is empty." << endl;
			exit(1);
		}
		return Stack::pop();
	}
};

class pairStack : public Stack2 {
	Pair arr[5];
public:
	pairStack() {
		for (int i = 0; i < 5; i++) {
			arr[i].x = 0;
			arr[i].y = 0;
		}
	}
	void push(Pair p) {
		if (top > MAX - 2) {
			cout << "Pair Stack is full." << endl;
			exit(1);
		}
		Stack2::push(p.x);
		Stack2::push(p.y);
	}
	Pair pop() {
		if (top < 1) {
			cout << "Pair Stack is empty." << endl;
			exit(1);
		}
		int y = Stack2::pop();
		int x = Stack2::pop();
		return Pair(x, y);
	}
};


int main() {
	pairStack pS;
	Pair p1[5], p2[5];
	
	p1[2].x = 5; p1[2].y = 7;
	pS.push(p1[2]);

	p1[3].x = 9; p1[3].y = 11;
	pS.push(p1[3]);

	p1[4].x = 13; p1[4].y = 15;
	pS.push(p1[4]);

	p2[4] = pS.pop();
	cout << "First coordinate: ( " << p2[4].x << ", " << p2[4].y << " )" << endl;

	p2[3] = pS.pop();
	cout << "Second coordinate: ( " << p2[3].x << ", " << p2[3].y << " )" << endl;

	p2[2] = pS.pop();
	cout << "Third coordinate: ( " << p2[2].x << ", " << p2[2].y << " )" << endl;


	int i = 0;
	int xco, yco;
	cout << endl;
	do {
		
		cout << "Enter coordinate " << i+4 << " (x and y): "; cin >> xco>> yco;
		p1[i].x = xco;
		p1[i].y = yco;
		pS.push(p1[i]);
		i++;
	} while (i < 2);

	cout << endl;
	for (int j = 0; j < 2; j++) {
		p2[j] = pS.pop();
		cout << "( " << p2[j].x << ", " << p2[j].y << " )" << endl;
	}
	

	return 0;
}
