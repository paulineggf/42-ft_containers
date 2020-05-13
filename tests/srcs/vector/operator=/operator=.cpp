#include <iostream>
#include <vector>
#include "vector.hpp"

int main ()
{
  ft::vector<int> foo (3,10);
  ft::vector<int> bar (5,20);

  bar = foo;
  foo = ft::vector<int>();
  

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';

    for (ft::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    for (ft::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
  return 0;
}
