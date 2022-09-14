#include <iostream>
#include <fstream>

class Distance {
	int feet;
	float inches;
public:
	Distance() : feet(0), inches(0.0) {}
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	void getdist()               //get length from user
	{
		std::cout << "\n    Enter feet: ";  std::cin >> feet;
		std::cout << "    Enter inches: ";  std::cin >> inches;
	}
	void showdist()              //display distance
	{
		std::cout << feet << "\'-" << inches << '\"';
	}
	void add_dist(Distance d2, Distance d3) {
		inches = d2.inches + d3.inches; //add the inches
		feet = 0;                       //(for possible carry)
		if (inches >= 12.0)              //if total exceeds 12.0,
		{                            //then decrease inches
			inches -= 12.0;              //by 12.0 and
			feet++;                      //increase feet
		}                            //by 1
		feet += d2.feet + d3.feet;      //add the feet
	}
};

int main() {
	int x = 0;
	char ch;
	Distance dist;
	std::fstream file;		// create input/output file

	file.open("Dist.DAT", std::ios::binary |
		std::ios::app | std::ios::out | std::ios::in);

	do {
		std::cout << "\nDistance: ";
		dist.getdist();

		file.write( (char*)&dist, sizeof(dist) );
		std::cout << "Enter another (y/n)? ";
		std::cin >> ch;
	} while (ch == 'y');

	file.seekg(0);		// reset to strat of file

	file.read( (char*)&dist, sizeof(dist) );
	while (!file.eof()) {
		std::cout << "\n." << ++x << " Distance: ";
		dist.showdist();

		file.read((char*)&dist, sizeof(dist));
	}


	std::cin.get();
}
