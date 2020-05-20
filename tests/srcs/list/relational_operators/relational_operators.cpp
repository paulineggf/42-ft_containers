// list comparisons
#include <iostream>
#include <list>
#include "list.hpp"

int main ()
{
  ft::list<int> a ;

  a.push_back(10);
  a.push_back(20);
  a.push_back(30);

  ft::list<int> b ;

  b.push_back(10);
  b.push_back(20);
  b.push_back(30);

  ft::list<int> c;

  c.push_back(30);
  c.push_back(20);
  c.push_back(10);

  if (a==b) std::cout << "a and b are equal\n";
  if (b!=c) std::cout << "b and c are not equal\n";
  if (b<c) std::cout << "b is less than c\n";
  if (c>b) std::cout << "c is greater than b\n";
  if (a<=b) std::cout << "a is less than or equal to b\n";
  if (a>=b) std::cout << "a is greater than or equal to b\n";


  ft::list<std::string> d ;

  d.push_back("10");
  d.push_back("20");
  d.push_back("30");

  ft::list<std::string> e ;

  e.push_back("10");
  e.push_back("20");
  e.push_back("30");

  ft::list<std::string> f;

  f.push_back("30");
  f.push_back("20");
  f.push_back("10");

  if (d==e) std::cout << "a and b are equal\n";
  if (e!=f) std::cout << "b and c are not equal\n";
  if (e<f) std::cout << "b is less than c\n";
  if (f>e) std::cout << "c is greater than b\n";
  if (d<=e) std::cout << "a is less than or equal to b\n";
  if (d>=e) std::cout << "a is greater than or equal to b\n";

  return 0;
}
