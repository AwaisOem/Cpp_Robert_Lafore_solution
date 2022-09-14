#include <iostream>
#include <stack>
using namespace std;
enum employe { laborer, secretary, manager, accountant, executive, researcher };
class employee{
private:
	int number_of_employee;
	float compensation;
public:
	
	class date {
	private:
		int year, month, day;
	public:
		void getdate(int y, int m, int d) {
			year = y; month = m; day = d;
		}
		void showdate() {
			cout << day << "/" << month << "/" << year << endl;
		}
	};
	void add_data(int n, float c) {
		number_of_employee = n;
		compensation = c;
	}
	void display() {
		cout << "Number of employee: " << number_of_employee << endl;
		cout << "Compesation of employee: " << compensation << endl;
	}
};

int main() {
	employee emp[3];
	employee::date em[3];
	char ch[3];
	for (int i = 0; i < 3; i++) {
		int no, yy, mm, dd;
		float comp;
		char c;
		static int s = 0;
		cout << "\nEnter the " << ++s << ". Employee data: \n\n";
		cout << "Employee no: "; cin >> no;
		cout << "Employee compensation: "; cin >> comp;
		emp[i].add_data(no, comp);
		cout << "The date when employee was hired(in this format dd/mm/yyyy): ";
		cin >> dd >> c >> mm >> c >> yy;
		em[i].getdate(yy, mm, dd);

		cout << "Enter employee type(firrst letter only)"
			"\n(laborer, secretary, manger, accountant, executive, researcher): ";
		cin >> ch[i];
		switch (ch[i]) {
		case 'l':
			ch[i] = laborer;
			cout << "Employee type is laborer." << endl;
			break;
		case 's':
			ch[i] = secretary;
			cout << "Employee type is secretary." << endl;
			break;
		case 'm':
			ch[i] = manager;
			cout << "Employee type is manager." << endl;
			break;
		case 'a':
			ch[i] = accountant;
			cout << "Employee type is accountant." << endl;
			break;
		case 'e':
			ch[i] = executive;
			cout << "Employee type is executive." << endl;
			break;
		case 'r':
			ch[i] = researcher;
			cout << "Employee type is researcher." << endl;
			break;
		default:
			cout << "Invalid selection." << endl;
		}
	}

	cout << "\n\n------------------------- Employees Information: -----------------------\n\n ";
	for (int i = 0; i < 3; i++) {
		emp[i].display();
		cout << "The date when Employee has been hire: "; em[i].showdate();
		cout << "The major of employee: ";
		switch (ch[i]) {
		case 0:
			ch[i] = laborer;
			cout << "is laborer." << endl;
			break;
		case 1:
			ch[i] = secretary;
			cout << "is secretary." << endl;
			break;
		case 2:
			ch[i] = manager;
			cout << "is manager." << endl;
			break;
		case 3:
			ch[i] = accountant;
			cout << "is accountant." << endl;
			break;
		case 4:
			ch[i] = executive;
			cout << "is executive." << endl;
			break;
		case 5:
			ch[i] = researcher;
			cout << "is researcher." << endl;
			break;
		default:
			cout << "There is not major." << endl;
		}
		cout << endl;
		
	}


	system("pause");
	return 0;
}
