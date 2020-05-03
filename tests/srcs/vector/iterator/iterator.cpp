#include "vector.hpp"
#include <vector>
#include <iostream>

int     main(void)
{
    ft::vector<int> myvector;
    ft::vector<int> myvector2;

    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);
    myvector.push_back(40);
    myvector.push_back(50);
    

    myvector2.push_back(10);
    myvector2.push_back(20);

    ft::vector<int>::iterator a = myvector.begin();
    ft::vector<int>::iterator b(a);
    ft::vector<int>::iterator c;
    ft::vector<int>::iterator d = myvector2.begin();

    c = a;

    if (a == b)  std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
    if (a != b)  std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;

    std::cout << "1: " << *a << std::endl;
    *a = 2;
    std::cout << "2: " << *a << std::endl;
    ++a;
    std::cout << "3: " << *a << std::endl;
    a++;
    std::cout << "4: " << *a << std::endl;
    std::cout << "5: " << *a++ << std::endl;
    std::cout << "6: " << *a-- << std::endl;
    --a;
    std::cout << "7: " << *a << std::endl;
    a--;
    std::cout << "8: " << *a << std::endl;
    a = a + 4;
    std::cout << "9: " << *a << std::endl;
    a = a - 4;
    std::cout << "10: " << *a << std::endl;    
    a = a + 2;
    std::cout << "11: " << *a << std::endl;
    a = a - 2;
    std::cout << "12: " << *a << std::endl;

    a = 4 + a;
    std::cout << "13: " << *a << std::endl;
    a = a - 4;
    std::cout << "14: " << a - c << std::endl;


    (void)d;

    return 0;
}