// list::merge
#include <iostream>
#include <list>
#include "list.hpp"

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int main ()
{
  ft::list<double> first, second;

  first.push_back (5.1);
  first.push_back (4.9);
  first.push_back (1.5);
  first.push_back (8.47);
  first.push_back (10.4);
  first.push_back (8.47);


  second.push_back (5.1);
  second.push_back (4.6);
  second.push_back (2.5);
  second.push_back (3.0);
  second.push_back (8.98);

  first.sort();
  second.sort();

  first.merge(second);

  // (second is now empty)

  second.push_back (2.1);

  first.merge(second,mycomparison);

  std::cout << "first contains:";
  for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
