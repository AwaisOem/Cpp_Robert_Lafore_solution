#include <iostream>

using namespace std;

const int MAXSIZE = 10;
class a {
	int* ar[MAXSIZE] = { NULL };
public:
	a() {}
	int& operator [](int index) {
		if (ar[index / MAXSIZE] == NULL)
			ar[index / MAXSIZE] = new int[MAXSIZE];  
		return *(*(ar + index / MAXSIZE) + index % MAXSIZE);
	}
};

int main() {
	a arr;

	int a = 0; 
	for (int i = 0; i < MAXSIZE * MAXSIZE; i++) {
		arr[i] = a;
		a += 10;
	}

	for (int i = 0; i < MAXSIZE * MAXSIZE; i++) {
		cout << arr[i] << " ";
		if ((i+1) % 10 == 0)
			cout << endl;
	}


	return 0;
}
