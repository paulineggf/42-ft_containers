// queue::push/pop
#include <iostream>       // std::cin, std::cout
#include <queue>          // ft::queue
#include "queue.hpp"

int main ()
{
  ft::queue<int> myqueue;

  std::cout << "Please enter some integers (enter 0 to end):\n";
  for (int i=1;i<=10;i++) myqueue.push(i);

  std::cout << "myqueue contains: ";
  while (!myqueue.empty())
  {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << '\n';

  return 0;
}
