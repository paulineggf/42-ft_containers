// constructing maps
#include <iostream>
#include <map>
#include "map.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  ft::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  ft::map<char,int> second (first.begin(),first.end());

  ft::map<char,int> third (second);

  ft::map<char,int,classcomp> fourth;                 // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

    for (ft::map<char, int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << it->second << std::endl;
    for (ft::map<char, int>::iterator it2 = second.begin(); it2 != second.end(); it2++)
        std::cout << it2->second << std::endl;    

  return 0;
}
