#include <iostream>

using namespace std;



int main() {
	int n;
	int sum = 0;
	cout << "Enter the number of elements: "; cin >> n;
	
	int* arr = new int[n];

	cout << "Enter values of elements: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "arr[" << i << "] = "; cin >> *(arr + i);
		sum += *(arr + i);
	}

	float result = float(sum / n);
	cout << "\nThe average of array: " << result << endl;




	return 0;
}
