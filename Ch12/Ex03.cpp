#include <iostream>
#include <fstream>
#include <process.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "\nFormat: filename\n";
		exit(-1);
	}

	std::ifstream infile;		// create file for input
	infile.open(argv[1]);
	if (!infile) {				// check for errors
		std::cerr << "\nCan't open" << argv[1];
		exit(-1);
	}

	infile.seekg(0, std::ios::end);	// go to end of file

	std::cout << "Size of " << argv[1] << " is " << infile.tellg();
	std::cout << std::endl;

	std::cin.get();
}
