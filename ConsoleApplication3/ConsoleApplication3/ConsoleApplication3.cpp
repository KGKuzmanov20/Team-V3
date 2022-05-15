game.cpp
#include "game.h"

game::game() {
	generateBaseCards();
	std::cout << "generated";
}

void game::generateBaseCards() {
	for (int i = 0; i < GAMESIZE; i++) {
		slots[i] = ".";
	}

	for (int i = BASECARDSINDEX; i < BASECARDSINDEX + BASECARDS; i++) {
		int num = rand() % 2;
		if (num == 0) {
			slots[i] = "01";
		}
		else {
			slots[i] = "10";
		}
	}

	int nextLine = 0, increment = 2, step = 1;
	for (int i = 0; i < GAMESIZE; i++) {

		std::cout << slots[i] << " ";
		if (i > BASECARDSINDEX && step == 1) {
			nextLine = BASECARDSINDEX + BASECARDS - 1;
			step = -1;
			increment += step - 1;
		}

		if (i == nextLine) {
			std::cout << std::endl;
			nextLine += (increment);
			increment += step;
		}

	}


}

game.h
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#define BASECARDS 6
#define BASECARDSINDEX 15
#define GAMESIZE 36
struct Card {
	std::string type;
	int value;
};

/*
			[0]
		   [1] [2]
		 [3] [4] [5]
	   [6] [7] [8] [9]
   [10] [11] [12] [13] [14]
[15] [16] [17] [18] [19] [20] - 6 x 0/1 cards
   [21] [22] [23] [24] [25]
	 [26] [27] [28] [29]
		[30] [31] [32]
		  [33] [34]
			[35]
*/

class game
{
public:
	game();
	void playCard(Card* card, int index); //играча поставя карта на слот
	Card* getPlayer1Cards(); //този метод връща ръката на играч 1
	Card* getPlayer2Cards(); //този метод връша ръката на играч 2
	int getTurn(); //този метод казва кой играч е на ход (1 или 2)
	std::string* getSlots(); //този метод връща масив от позиции и картите на тях



private:
	int turn = 1;
	std::string slots[36]; //save the game state
	void generateBaseCards();

};



cards.cpp
#include <SFML/Graphics.hpp>
#include "game.h"