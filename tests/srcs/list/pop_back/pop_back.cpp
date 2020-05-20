// list::pop_back
#include <iostream>
#include <list>
#include "list.hpp"

int main ()
{
  ft::list<int> mylist;
  int sum (0);
  mylist.push_back (100);
  mylist.push_back (200);
  mylist.push_back (300);

  while (!mylist.empty())
  {
    sum+=mylist.back();
    mylist.pop_back();
  }

  std::cout << "The elements of mylist summed " << sum << '\n';

    ft::list<int> mylist2;
  int sum2(0);
  mylist2.push_back (100);
  mylist2.push_back (200);

  while (!mylist2.empty())
  {
    sum2+=mylist2.back();
    mylist2.pop_back();
  }

  std::cout << "The elements of mylist2 summed " << sum2 << '\n';

  return 0;
}
