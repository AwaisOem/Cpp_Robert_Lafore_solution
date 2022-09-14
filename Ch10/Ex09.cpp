#include <iostream>
using namespace std;

int main() {
	const int MAXSIZE = 10;
	int a0[MAXSIZE], a1[MAXSIZE], a2[MAXSIZE], a3[MAXSIZE], a4[MAXSIZE], a5[MAXSIZE], a6[MAXSIZE], a7[MAXSIZE], a8[MAXSIZE], a9[MAXSIZE];
	int* ap[MAXSIZE];
	ap[0] = a0, ap[1] = a1, ap[2] = a2, ap[3] = a3, ap[4] = a4, ap[5] = a5, ap[6] = a6;
	ap[7] = a7, ap[8] = a8, ap[9] = a9;

	int a = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		a0[i] = a;
		a += 10;
	}
	for (int i = 0; i < MAXSIZE; i++) {
		a1[i] = a;
		a += 10;
	}
	for (int i = 0; i < MAXSIZE; i++) {
		a2[i] = a;
		a += 10;
	}
	for (int i = 0; i < MAXSIZE; i++) {
		a3[i] = a;
		a += 10;
	}
	for (int i = 0; i < MAXSIZE; i++) {
		a4[i] = a;
		a += 10;
	}
	for (int i = 0; i < MAXSIZE; i++) {
		a5[i] = a;
		a += 10;
	}
	for (int i = 0; i < MAXSIZE; i++) {
		a6[i] = a;
		a += 10;
	}
	for (int i = 0; i < MAXSIZE; i++) {
		a7[i] = a;
		a += 10;
	}
	for (int i = 0; i < MAXSIZE; i++) {
		a8[i] = a;
		a += 10;
	}
	for (int i = 0; i < MAXSIZE; i++) {
		a9[i] = a;
		a += 10;
	}

	// displaying the array
	for (int i = 0; i < MAXSIZE; i++) {
		for (int j = 0; j < MAXSIZE; j++) {
			cout << ap[i][j] << " ";
		}
		cout << endl;
	}



	return 0;
}
