#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class Game
{
private:


public:

	void StartGame(Game game);
	void EndGame(Player player);
	void SetPlayers();
	int numPlayers;
	int maxAvailableChips;
	vector<Player> playerList;
	string winnerName;
	int center;

	bool isWinner;
};