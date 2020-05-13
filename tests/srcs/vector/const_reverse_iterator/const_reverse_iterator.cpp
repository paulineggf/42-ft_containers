#include <iostream>
#include <vector>
#include "vector.hpp"

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

    ft::vector<int>::const_iterator a(myvector.begin());
    ft::vector<int>::const_iterator e(myvector.end());

    ft::vector<int>::const_reverse_iterator until2(myvector.rend());
    ft::vector<int>::const_reverse_iterator from2(myvector.rbegin());
    
    ft::vector<int>::const_reverse_iterator until3(until2);
    ft::vector<int>::const_reverse_iterator from3(from2);
    

    ft::reverse_iterator<ft::vector<int>::const_iterator> from4(e);
    ft::reverse_iterator<ft::vector<int>::const_iterator> until4(a);

    ft::reverse_iterator<ft::vector<int>::const_reverse_iterator> from5(until3);
    ft::reverse_iterator<ft::vector<int>::const_reverse_iterator> until5(from3);

    while (from3 != until3)
    {
        std::cout << *from3 << ' ';
        from3++;
    }
    std::cout << std::endl;

    while (from4 != until4)
    {
        std::cout << *from4 << ' ';
        from4++;
    }
    std::cout << std::endl;

    while (from5 != until5)
    {
        std::cout << *from5 << ' ';
        from5++;
    }
    std::cout << std::endl;

    return 0;
}
