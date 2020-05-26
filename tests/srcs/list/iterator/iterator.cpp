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


  ft::list<int> mylist;
    ft::list<int> mylist2;

    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);
    mylist.push_back(40);
    mylist.push_back(50);
    

    mylist2.push_back(10);
    mylist2.push_back(20);

    ft::list<int>::iterator a = mylist.begin();
    ft::list<int>::iterator b(a);
    ft::list<int>::iterator c;
    ft::list<int>::iterator d = mylist2.begin();
    (void)d;

    c = a;



    if (a == b)  std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
    if (a != b)  std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;

    std::cout << "1: " << *a << std::endl;
    *a = 2;
    std::cout << "2: " << *a << std::endl;
    ++a;
    std::cout << "3: " << *a << std::endl;
    a++;
    std::cout << "4: " << *a << std::endl;
    std::cout << "5: " << *a++ << std::endl;
    std::cout << "6: " << *a-- << std::endl;
    --a;
    std::cout << "7: " << *a << std::endl;
    a--;
    std::cout << "8: " << *a << std::endl;



    ft::list<int>::reverse_iterator until2(mylist.rend());
    ft::list<int>::reverse_iterator from2(mylist.rbegin());

    while (from2 != until2)
    {
        std::cout << *from2 << ' ';
        from2++;
    }
    std::cout << std::endl;

    return 0;
}

