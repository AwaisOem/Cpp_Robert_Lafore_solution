#include <iostream>

using namespace std;

class toolBoth {
private:
	unsigned int total_cars;
	double total_amount;
public:
	toolBoth(): total_cars(0), total_amount(0.0) {}
	void payingCar() { total_amount += 0.5; total_cars++; }
	void nopayCar() { total_cars++; }
	void display() const {
		cout << "Total Number of cars passed on the toll both: " << total_cars << endl;
		cout << "Total Money collected at toll both: " << total_amount << endl;
	}
};

int main(){
	toolBoth button;
	char count;
	cout << "Press 'c' to count paying car and 'm' to count non paying car.";
	cout << "\nPress ESC to exit from program.";
	do {
		cout << "Press key: ";
		cin >> count;
		if (count == 'C' || count == 'c') {
			button.payingCar();
		}
		else if (count == 'm' || count == 'M')
			button.nopayCar();
		else {
			cout << "Invalid pressed key" << endl;
			break;
		}
	} while (count != 'e');
	button.display();
	return 0;
}
