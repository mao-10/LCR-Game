
#include <iostream>
#include <string>
#include "DiceRoll.h"
#include "conio.h"
#include <random>

using namespace std;



// a function to illustrate the act of rolling dice
void Dice::Roll()
{
	cout << "Press a key to roll the dice" << endl;
	// detects user input, if they press a key the game can continue
	_getch();
	cout << "... rolling dice..." << endl;
}

// function to roll rice, and do an action depending on roll result
void Dice::RollDice(Player *player, Game game)
{
	int currNumChips;
	// define the range of dice rolls
	int min = 1;
	int max = 6;

	// iniialize a randome num generator
	random_device randDev;
	// seed an mt19937 objet witch randDev
	mt19937 gen(randDev());
	// create a distribution object, passing the min and max values I defined
	uniform_int_distribution<> distrib(min, max);

	// get random number within range by calling the distribution object
	int diceNum = distrib(gen);

	// switch case for diceNum
	switch (diceNum)
	{
	case 1:
		// if dice roll is 1, its 'L'
		cout << "L" << endl;
		// get the players index in vector
		for (int v = 0; v < game.numPlayers; v++)
		{
			// if the player at the index is the same as the player who's turn it is
			if (game.playerList[v].GetName() == player->GetName())
			{
				// save the index
				index = v;
			}
		}
		// if the player is at the front of the vector
		if (player->GetName() == game.playerList.front().GetName())
		{
			// the left player is at the back of the vector
			leftPlayer = &game.playerList.back();
		}
		else
		{
			// otherwise, use the index - 1 to get player to the left
			leftPlayer = &game.playerList.at(index - 1);
		}

		// if the player has at least 1 chip
		if (player->GetNumChips() > 0)
		{
			// subtract a chip from them
			player->SubtractNumChip(*player);
			// and give to the left player
			leftPlayer->AddNumChip(*leftPlayer);
			// print results to the users
			cout << player->GetName() << " has " << player->GetNumChips() << " now" << endl;
			cout << leftPlayer->GetName() << " has " << leftPlayer->GetNumChips() << " now\n" << endl;
		}
		break;

	case 2:
		// if player rolls a 2, they rolled an 'R'
		cout << "R" << endl;
		// get index
		for (int v = 0; v < game.numPlayers; v++)
		{
			if (game.playerList[v].GetName() == player->GetName())
			{
				index = v;
			}
		}

		// if player is at the back of the vector
		if (player->GetName() == game.playerList.back().GetName())
		{
			// the right player is at the front of the vector
			rightPlayer = &game.playerList.front();
		}
		else
		{
			// else get right player by adding one to the index
			rightPlayer = &game.playerList.at(index + 1);
		}

		// if the player has at least 1 chip
		if (player->GetNumChips() > 0)
		{
			// subtract a chip from the player
			player->SubtractNumChip(*player);
			// and give to the right player
			rightPlayer->AddNumChip(*rightPlayer);
			// print results to the users
			cout << player->GetName() << " has " << player->GetNumChips() << " now" << endl;
			cout << rightPlayer->GetName() << " has " << rightPlayer->GetNumChips() << " now\n" << endl;
		}
		break;

	case 3:
		// if player rolls a 3, they roll 'C'
		cout << "C" << endl;
		// add 1 to the center
		game.center += 1;
		// subtract from the player
		player->SubtractNumChip(*player);
		cout << player->GetName() << " has " << player->GetNumChips() << " now\n" << endl;
		break;

	// for rolls 4, 5, or 6... no changes to the players chips. 
	case 4:
		cout << "4" << endl;
		cout << "No change in coins \n" << endl;
		break;

	case 5:
		cout << "5" << endl;
		cout << "No change in coins \n" << endl;
		break;

	case 6:
		cout << "6" << endl;
		cout << "No change in coins \n" << endl;
		break;

	default:
		break;

	}

}
// function to run roll and rolldice functions depending on number of chips player had
void Dice::RunGame(Player *player, Game game)
{
	// tell player how many chips they have
	cout << "Player " << player->GetName() << " has " << player->GetNumChips() << " chips" << endl;
	Roll();
	// for each chip a player has
	for (int j = 0; j < player->GetNumChips(); j++)
	{
		// run the rollDice function
		RollDice(player, game);
	}
}