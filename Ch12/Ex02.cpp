#include <iostream>
#include <fstream>
#include <process.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "\nFormat: copy srcfile destfile";
		exit(-1);
	}
	char ch;

	std::ifstream infile;
	infile.open(argv[1]);		// open file
	if (!infile) {
		std::cerr << "\nCan't open " << argv[1];
		exit(-1);
	}

	std::ofstream outfile;
	outfile.open(argv[2]);
	if (!outfile) {
		std::cerr << "\nCan't open " << argv[2];
		exit(-1);
	}

	while (infile) {
		infile.get(ch);			// read a character
		outfile.put(ch);		// write the character
	}

	std::cin.get();
}
