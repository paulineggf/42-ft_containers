#include "vector.hpp"
#include <vector>
#include <iostream>

int     main(void)
{
  ft::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);

  typedef ft::vector<int>::iterator iter_type;

  iter_type from (myvector.begin());   

  // std::cout << "from.getIdx(): " << from.getIdx() << std::endl;

  iter_type until (myvector.end());

  ft::reverse_iterator<iter_type> rev_until (from);

  ft::reverse_iterator<iter_type> rev_from (until);                     

  std::cout << "myvector:" << std::endl;
  while (rev_from != rev_until)
  {
    std::cout << ' ' << *rev_from;
    rev_from++;
  }
  std::cout << '\n';

  ft::vector<int>::reverse_iterator rev_until2(myvector.begin());
  ft::vector<int>::reverse_iterator rev_from2(myvector.end());

  ft::vector<int>::reverse_iterator rev_until3(myvector.rend());
  // ft::vector<int>::reverse_iterator rev_until3 = myvector.rend();
  ft::vector<int>::reverse_iterator rev_from3 = myvector.rbegin();

  std::cout << "myvector2:" << std::endl;
  while (rev_from2 != rev_until2)
  {
    std::cout << ' ' << *rev_from2;
    rev_from2++;
  }
  std::cout << '\n';

    std::cout << "myvector3:" << std::endl;
  while (rev_from3 != rev_until3)
  {
    std::cout << ' ' << *rev_from3;
    rev_from3++;
  }
  std::cout << '\n';

      ft::vector<int> v;
      
      v.push_back(0);
      v.push_back(1);
      v.push_back(2);
      v.push_back(3);
      v.push_back(4);
      v.push_back(5);
 
  typedef ft::reverse_iterator<ft::vector<int>::iterator> RevIt;
  
    ft::vector<int>::iterator it = v.begin() + 3;
    RevIt r_it(it);
 
    std::cout << "*it == " << *it << ", *r_it.base() == " << *r_it.base()
    << '\n' << "*r_it == " << *r_it <<", *(r_it.base()-1) == " << *(r_it.base()-1) << "\n";
  
    RevIt r_end(v.begin());
    RevIt r_begin(v.end());
 
    for (it = r_end.base(); it != r_begin.base(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << "\n";
  return 0;
}
