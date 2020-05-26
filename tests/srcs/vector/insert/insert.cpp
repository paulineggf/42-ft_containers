#include <iostream>
#include "vector.hpp"
#include <vector>

int main ()
{
  ft::vector<int> myvector;
  ft::vector<int>::iterator it;

  myvector.push_back(10);
  myvector.push_back(20);
  myvector.push_back(30);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << std::endl;
  
  it = myvector.begin();
  it = myvector.insert ( it , 40 );

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << std::endl;

  myvector.insert (it,2,50);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << std::endl;

  // // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector;
  anothervector.push_back(60);
  anothervector.push_back(70);
  myvector.insert(it+2,anothervector.begin(),anothervector.end());

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << std::endl;
  
  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << std::endl;

  return 0;
}
