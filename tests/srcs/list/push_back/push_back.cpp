// list::push_back
#include <iostream>
#include <list>
#include "list.hpp"

int main ()
{
  ft::list<int> mylist;

  for (int i = 0; i < 10; i++)
    mylist.push_back(i);

  std::cout << "mylist stores " << mylist.size() << " numbers.\n";

  ft::list<int>::iterator it = mylist.begin();
  for (; it != mylist.end(); it++)
    std::cout << *it << ' ';
  std::cout << std::endl;

  return 0;
}
