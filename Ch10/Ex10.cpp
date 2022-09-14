#include <iostream>
using namespace std;

int main() {
	const int MAXSIZE = 10;
	int* ap[MAXSIZE];

	for (int i = 0; i < MAXSIZE; i++)
		ap[i] = new int[MAXSIZE];
	
	int a = 0; 
	for(int i = 0; i<MAXSIZE; i++)
		for (int j = 0; j < MAXSIZE; j++) {
			ap[i][j] = a;
			a += 10;
		}

	for (int i = 0; i < MAXSIZE; i++) {
		for (int j = 0; j < MAXSIZE; j++) {
			cout << *(*(ap + i) + j) << " ";
		}
		cout << endl;
	}

	return 0;
}
