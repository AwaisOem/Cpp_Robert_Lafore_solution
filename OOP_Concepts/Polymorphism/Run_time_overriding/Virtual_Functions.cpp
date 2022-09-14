#include <iostream>
#include <list>

class Instrument {
public:
	virtual void makeSound() {
		std::cout << "The instrument is playing..." << std::endl;
	}
};

class Accordion : public Instrument {
public:
	void makeSound() {
		std::cout << "The accordion is playing..." << std::endl;
	}
};



int main() {

	Instrument* i1 = new Accordion();

	i1->makeSound();


	system("pause");
}
