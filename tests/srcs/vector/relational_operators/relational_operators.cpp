#include <iostream>
#include "vector.hpp"
#include <vector>

int main ()
{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (2,100);   // two ints with a value of 200
  
  foo.push_back(1);
  foo.push_back(2);
  foo.push_back(3);
  bar.push_back(4);
  bar.push_back(5);


  if (foo == bar) std::cout << "foo and bar are equal\n";
  if (foo != bar) std::cout << "foo and bar are not equal\n";
  if (foo<bar) std::cout << "foo is less than bar\n";
  if (foo>bar) std::cout << "foo is greater than bar\n";
  if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
  if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

  ft::vector<std::string> foo2 ;  
  ft::vector<std::string> bar2 ; 

  foo2.push_back("AB");
  foo2.push_back("BA");
  foo2.push_back("AB");
  bar2.push_back("BA");
  bar2.push_back("BA");


  if (foo2 == bar2) std::cout << "foo and bar are equal\n";
  if (foo2 != bar2) std::cout << "foo and bar are not equal\n";
  if (foo2<bar2) std::cout << "foo is less than bar\n";
  if (foo2>bar2) std::cout << "foo is greater than bar\n";
  if (foo2 <= bar2) std::cout << "foo is less than or equal to bar\n";
  if (foo2 >= bar2) std::cout << "foo is greater than or equal to bar\n";

  

  return 0;
}
