// constructing lists
#include <iostream>
#include <list>
#include "list.hpp"

int main ()
{
  // constructors used in the same order as described above:
  ft::list<int> first;                                // empty list of ints
  ft::list<int> second (4, 100);                       // four ints with value 100
  ft::list<int> third (second.begin(),second.end());  // iterating through second
  ft::list<int> fourth (third);                       // a copy of third
  ft::list<std::string> sixth (4, "hello");             // four object with value hello


  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  ft::list<int> fistdh (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of first are: ";
  for (ft::list<int>::iterator it = first.begin(); it != first.end(); it++)
    std::cout << *it << ' ';
  std::cout << '\n';

  std::cout << "The contents of second are: ";
  for (ft::list<int>::iterator it = second.begin(); it != second.end(); it++)
    std::cout << *it << ' ';
  std::cout << '\n';

    std::cout << "The contents of third are: ";
  for (ft::list<int>::iterator it = third.begin(); it != third.end(); it++)
    std::cout << *it << ' ';
  std::cout << '\n';

      std::cout << "The contents of fourth are: ";
  for (ft::list<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
    std::cout << *it << ' ';
  std::cout << '\n';
  
  std::cout << "The contents of fistdh are: ";
  for (ft::list<int>::iterator it = fistdh.begin(); it != fistdh.end(); it++)
    std::cout << *it << ' ';
  std::cout << '\n';

    std::cout << "The contents of sixth are: ";
  for (ft::list<std::string>::iterator it = sixth.begin(); it != sixth.end(); it++)
    std::cout << *it << ' ';
  std::cout << '\n';


  return 0;
}
