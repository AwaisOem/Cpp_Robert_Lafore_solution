#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int n = 5;
void addarrays(float* ar1, float* ar2, float* ar3, int Size) {
	for (int i = 0; i < Size; i++) {
		float temp = ar1[i] + ar2[i];
		ar3[i] = temp;
	}
}

int main() {
	float arr1[n] = { 10, 20, 30, 40, 50 };
	float arr2[n] = { 11, 22, 33, 44, 55 };
	float arr3[n];

	addarrays(arr1, arr2, arr3, sizeof(arr3)/sizeof(arr3[0]));
	for (int i = 0; i < n; i++)
		cout << arr3[i] << " ";
	

	return 0;
}
