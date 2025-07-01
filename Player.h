#pragma once
#include <string>

class Player
{

private:
	std::string m_name;
	int numChips;

public:
	Player()
	{
	}

	void SetName(const std::string& name)
	{
		m_name = name;
	}

	const std::string& GetName() const
	{
		return m_name;
	}

	// setters and getters for number of chips
	void SetNumChips(int numberChips)
	{
		numChips = numberChips;
	}

	int GetNumChips()
	{
		return numChips;
	}
	// for adding a chip or subtracting a chip from a player
	void AddNumChip(Player& player)
	{
		player.SetNumChips(player.GetNumChips() + 1);
	}
	void SubtractNumChip(Player& player)
	{
		player.SetNumChips(player.GetNumChips() - 1);
	}
};