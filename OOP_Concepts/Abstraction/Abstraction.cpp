#include <iostream>

class Smartphone {
public:
	virtual void TakeSelfie() = 0;
	virtual void MakeCall() = 0;
};

class Android : public Smartphone {
public:
	void TakeSelfie() {
		std::cout << "Android selfie" << std::endl;
	}

	void MakeCall() {
		std::cout << "Android calling..." << std::endl;
	}
};

class Iphone : public Smartphone {
public:
	void TakeSelfie() {
		std::cout << "IPhone Selfie" << std::endl;
	}

	void MakeCall() {
		std::cout << "Iphone calling..." << std::endl;
	}
};

int main() {

	Smartphone* s1 = new Android();
	s1->TakeSelfie();

	Smartphone* s2 = new Iphone();
	s2->TakeSelfie();
	s2->MakeCall();


	system("pause>0");
}
