// list::max_size
#include <iostream>
#include <list>
#include "list.hpp"

int main ()
{
  unsigned int i;
  ft::list<int> mylist;

  i = 10;

  std::cout << mylist.max_size() << std::endl;
  return 0;
}
