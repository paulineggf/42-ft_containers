#include <iostream>
#include <vector>
#include "vector.hpp"

int main ()
{
  ft::vector<int> myvector;

  for (int i = 0; i < 10; i++)
    myvector.push_back(i);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

  return 0;
}
