#include <iostream>
#include <string>

using namespace std;

class Array {
	int Size;
	int* ptr;
public:
	Array() {}
	Array(int n) {
		Size = n;
		ptr = new int[n];
	}
	~Array() {
		delete[] ptr;
	}
	int& operator [](int n) {
		return *(ptr + n);
	}
	Array& operator =(Array& a) {
		Size = a.Size;
		ptr = new int[Size];
		for (int i = 0; i < Size; i++)
			*(ptr + i) = *(a.ptr + i);
		return *this;
	}
	Array(Array& a) {
		Size = a.Size;
		ptr = new int[a.Size];
		for (int i = 0; i < Size; i++)
			*(ptr + i) = *(a.ptr + i);
	}
};

int main() {
	const int x = 10;
	Array arr(x);

	for (int i = 0; i < x; i++)
		arr[i] = i * 10;

	for (int i = 0; i < x; i++)
		cout << arr[i] << " ";
	cout << endl;

	Array ar1;
	ar1 = arr;
	for (int i = 0; i < x; i++)
		cout << ar1[i] << " ";
	cout << endl;

	Array ar2(ar1);
	for (int i = 0; i < x; i++)
		cout << ar1[i] << " ";
	cout << endl;

	return 0;
}
