#include <iostream>

using namespace std;

int largest(int ar[], int Size) {
	int max = ar[0];
	for (int i = 1; i < Size; i++) {
		if (max < ar[i]) {
			max = ar[i];
		}
	}
	return max;
}

int main() {
	enum { MAX = 10 };
	int arr[MAX];
	cout << sizeof(arr);
	cout << "Enter the values of elements: " << endl;
	for (int i = 0; i < MAX; i++) {
		cout << "arr[" << i << "] => ";
		cin >> arr[i];
	}
	cout << "The largest element is: " << largest(arr, MAX) << endl;

	return 0;
}

