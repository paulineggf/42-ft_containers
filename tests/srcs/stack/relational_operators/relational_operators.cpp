// list comparisons
#include <iostream>
#include <list>
#include <stack>
#include "stack.hpp"

int main ()
{
  std::list<int> a2 ;

  a2.push_back(10);
  a2.push_back(20);
  a2.push_back(30);

  std::list<int> b2 ;

  b2.push_back(10);
  b2.push_back(20);
  b2.push_back(30);

  std::list<int> c2;

  c2.push_back(30);
  c2.push_back(20);
  c2.push_back(10);

    ft::stack<int, std::list<int> > a(a2);
    ft::stack<int, std::list<int> > b(b2);
    ft::stack<int, std::list<int> > c(c2);

  if (a==b) std::cout << "a and b are equal\n";
  if (b!=c) std::cout << "b and c are not equal\n";
  if (b<c) std::cout << "b is less than c\n";
  if (c>b) std::cout << "c is greater than b\n";
  if (a<=b) std::cout << "a is less than or equal to b\n";
  if (a>=b) std::cout << "a is greater than or equal to b\n";


  return 0;
}
