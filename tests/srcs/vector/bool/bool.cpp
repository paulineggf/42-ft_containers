#include "vector.hpp"
#include <iostream>
#include <vector>

int main ()
{
  ft::vector<bool> foo;
  ft::vector<bool> bar;

  foo.assign(2, true);


  foo.push_back(false);
  foo.push_back(true);
  foo.push_back(false);

  bar.push_back(true);
  bar.push_back(false);


  foo.swap (foo[0], foo[1]);
  bar.swap (bar.front(), bar.back());

  foo.swap(bar);

  foo.flip();

  std::cout << std::boolalpha;
  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++) std::cout << ' ' << foo[i];
  std::cout << "\nbar contains:";
  for (unsigned i=0; i<bar.size(); i++) std::cout << ' ' << bar[i];
  std::cout << '\n';

  return 0;
}
