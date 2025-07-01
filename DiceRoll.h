#pragma once
#include "Player.h"
#include "LCR_Game_Loop.h"

class Dice
{

private:
	Player *leftPlayer, *rightPlayer;

public:
	void RunGame(Player *player, Game game);
	void Roll();
	void RollDice(Player *player, Game game);

	int center = 0;
	int index;

};