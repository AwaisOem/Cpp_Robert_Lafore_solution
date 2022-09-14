#include <iostream>
#include <stack>
using namespace std;

class employee {
private:
	int number_of_employee;
	float compensation;
public:
	void add_data(int n, float c) {
		number_of_employee = n;
		compensation = c;
	}
	void display() {
		cout << "Number of employee: " << number_of_employee << endl;
		cout << "Compesation of employee: " << compensation << "\n\n";
	}
};

int main(){
	employee emp[3];
	for (int i = 0; i < 3; i++) {
		int n;
		float f;
		cout << "Enter the number of empolyee: "; cin >> n;
		cout << "Enter the compensation of employee: "; cin >> f;
		emp[i].add_data(n, f);
	}
	cout << "\n\n-----------------The data of employees: \n\n";
	for (int i = 0; i < 3; i++)
		emp[i].display();

	system("pause");
	return 0;
}
