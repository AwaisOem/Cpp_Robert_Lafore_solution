#include <iostream>

using namespace std;
int Count = 0;
void global_variable() {
	Count++;
}
int local_variable() {
	static int coun = 0;
	coun++;
	return coun;
}

int main() {
	int store=0;
	for (int i = 1; i <= 10; i++) {
		global_variable();
		store = local_variable();
	}
	cout << "I have been called " << Count << " times\t->(global variable)" << endl;
	cout << "I have been called " << store << " times\t->(local variable)" << endl;
	
	return 0;
}
