#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>
#include "list.hpp"
struct Player
{
	int id;
	std::string name;
 
	Player(int playerId, std::string playerName) :
			id(playerId), name(playerName)
	{
	}
};
 
int main()
{
	// ft::list<Player> listofPlayers =
	// { Player(22, "Sid"), Player(3, "Laura"), Player(43, "Riti"), Player(30,
	// 		"Angel"), Player(2, "Laura") };
	ft::list<Player> listofPlayers;

    listofPlayers.push_back(Player(22, "Sid"));
    listofPlayers.push_back(Player(3, "Laura"));
    listofPlayers.push_back(Player(43, "Riti"));
 
	std::cout << "*******Iterate list using Iterators*******" << std::endl;
 
//Create an iterator of ft::list
	ft::list<Player>::iterator it;
 
// Make iterate point to begining and incerement it one by one till it reaches the end of list.
	for (it = listofPlayers.begin(); it != listofPlayers.end(); it++)
	{
		// Access the object through iterator
		int id = it->id;
		std::string name = it->name;
 
		//Print the contents
		std::cout << id << " :: " << name << std::endl;
		std::cout << (*it).name << " :: " << std::endl;
		std::cout << it->name << " :: " << std::endl;
	}
    return 0;
}

