#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

enum Suit {clubs, diamonds, hearts, spades};
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class Card {
	int number;
	Suit suit;
public:
	Card() {};
	void set_card(int, Suit);
	void display();
};
void Card::set_card(int n, Suit s) { number = n; suit = s; }
void Card::display() {
	cout << setw(5);
	if (number >= 2 && number <= 10) {
		cout << number;
	}
	else {
		switch (number) {
		case jack: cout << "J"; break;
		case queen: cout << "Q"; break;
		case king: cout << "K"; break;
		case ace: cout << "A"; break;
		}
	}
	switch (suit) {
	case clubs: cout << " club"; break;
	case diamonds: cout << " diamond"; break;
	case hearts: cout << " heart"; break;
	case spades: cout << " spade"; break;
	}
}

int main() {
	Card deck[52];
	int i;
	for (int i = 0; i < 52; i++) {
		int num = (i % 13) + 2;
		Suit su = Suit(i / 13);
		deck[i].set_card(num, su);
	}
	srand(time(NULL));
	for (int i = 0; i < 52; i++) {
		int j = rand() % 52;
		Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
	const int players = 4;
	const int card_of_players = 13;
	Card bridge[players][card_of_players];
	for (int i = 0; i < players; i++) {
		for (int j = 0; j < card_of_players; j++) {
			bridge[i][j] = deck[i * card_of_players + j];
		}
	}
	for (int i = 0; i < players; i++) {
		cout << "Players NO " << i + 1 << " : ";
		for (int j = 0; j < card_of_players; j++) {
			bridge[i][j].display();
		}
		cout << endl;
	}

	return 0;
}

