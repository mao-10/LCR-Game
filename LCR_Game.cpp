// Mao Christie
// IT-312
// Final Project
// For this project, I created a player class, dice class, and game class. My biggest struggle was implementing the different classes and making sure 
// things were being saved properly. After some research, degugging, and thinking, I realized the player during the game was being copied and reset
// after each turn. I had to utilize pointers to make sure the players chips were actually being recorded. 


// LCR_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LCR_Game_Loop.h"
#include "DiceRoll.h"
#include <string>
#include <fstream>

using namespace std;

// declare classes
Game game;
Dice dice;
Player* player;

// function to start game
void Game::StartGame(Game game)
{
	// open file using fstream
	string line;
	ifstream gameFile("LCRrules.txt");

	// continue if file is open
	if (gameFile.is_open())
	{
		// greet the user
		cout << "Welcome to the LCR game!!!" << endl;
		cout << "Here are the rules: " << endl;
		cout << "\n" << endl;
		// while the file is open and good
		while (!gameFile.eof())
		{
			// get lines from the file and print them to the user
			getline(gameFile, line);
			cout << line << endl;

		}
		// close the file if file is not good or after the while statement
		gameFile.close();
	}
	else
	{
		// let user know there was an issue opening the file
		cout << "Unable to open file" << endl;
	}
	// get player number
	cout << "How many players will be playing?" << endl;
	cin >> numPlayers;
	// while num players is less than 3 or cin fails
	while (numPlayers < 3 || cin.fail())
	{
		// if cin did not fail
		if (cin.good())
		{
			// tell player they need at least 3 players
			cout << "The minimun number of players is 3... Please add more players: " << endl;
		}
		// else cin failed
		else 
		{
			// ask player to input a valid number
			cout << "Please input a whole number: " << endl;
			// clear cin and ignore spaces
			cin.clear();
			cin.ignore(256, '\n');
		}
		// get num players again
		cin >> numPlayers;
	}
	// calculate the max available chips in the game
	maxAvailableChips = numPlayers * 3;

}
// function to end game
void Game::EndGame(Player player)
{
	// if there is a winner
	// get the winners name
	if (isWinner)
	{
		winnerName = player.GetName();
		cout << "The winner is " << winnerName << "!!!" << endl;
	}
}

// function to create and set players (name, chips) to the players vector
void Game::SetPlayers()
{
	// for each player the user said would play
	for (int n = 1; n <= game.numPlayers; n++)
	{
		// initialize name and a player object
		string name;
		Player player;
		cout << "Please enter the Player name" << endl;
		// get name and set name and chips for the player object
		cin >> name;
		player.SetName(name);
		player.SetNumChips(3);
		// add to player to vector
		game.playerList.push_back(player);
	}
}


int main()
{
	// call start game and call SetPlayers
	game.StartGame(game);

	game.SetPlayers();
	// initialize variable numPlayers to keep track of the number of and update the players in the game
	int playerNum = game.numPlayers;

	// while there is no winner
	do
	{
		// for each player
		for (int a = 0; a < game.numPlayers; a++)
		{
			// find the player at the index
			player = &game.playerList.at(a);
			// if the player has 0 chips
			if (player->GetNumChips() == 0)
			{
				// subtract 1 from playerNum
				playerNum -= 1;
				// let player know they have no chips
				cout << "Player " << player->GetName() << " has no chips to roll dice..." << endl;
			}
			// else if playerNum is less than 2, there is only one player left
			else if (playerNum < 2)
			{
				// set isWinner to true
				// endGame with the player as the winner (last one left)
				game.isWinner = true;
				game.EndGame(*player);
				return 0;
			}
			else
				// run the game
				// if the player has at least one chip and isn't the only one left, run the game
			{
				cout << "**************************\n" << endl;
				dice.RunGame(player, game);
				cout << "**************************\n" << endl;
			}
		}
		
		
	} while (game.isWinner == false);

}
