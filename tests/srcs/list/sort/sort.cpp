// list::sort
#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include "list.hpp"

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

int main ()
{
  ft::list<std::string> mylist;
  ft::list<std::string>::iterator it;
  mylist.push_back ("one");
  mylist.push_back ("two");
  mylist.push_back ("Three");
  mylist.push_back ("Four");
  mylist.push_back ("five");
  mylist.push_back ("six");
  mylist.push_back ("Seven");

  mylist.sort();

    ft::list<int> myints;
    ft::list<int>::iterator it2;
    myints.push_back(1);
    myints.push_back(5);
    myints.push_back(0);
    myints.push_back(2);
    myints.push_back(4);
    myints.push_back(3);

    myints.sort();



  std::cout << "myints contains:";
  for (it2=myints.begin(); it2!=myints.end(); ++it2)
    std::cout << ' ' << *it2;
  std::cout << '\n';

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mylist.sort(compare_nocase);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
