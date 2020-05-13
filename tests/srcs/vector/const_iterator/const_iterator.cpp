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
    ft::vector<int>::const_iterator b(a);
    ft::vector<int>::const_iterator c;
    ft::vector<int>::const_iterator d = myvector2.begin();
    (void)d;

    

    c = a;

    if (a == b)  std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
    if (a != b)  std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;

    std::cout << "1: " << *a << std::endl;
    // *a = 2;
    // std::cout << "2: " << *a << std::endl;
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
    std::cout << "14: " << *a << std::endl;
    a++;
    std::cout << "15: " << a - c << std::endl;

    if (a < b)  std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
    if (a > b)  std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;

    if (a <= b)  std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
    if (a >= b)  std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;

    a += 1;
    std::cout << "16: " << *a << std::endl;
    a -= 2;
    std::cout << "17: " << *a << std::endl;
    std::cout << "18: " << a[0] << std::endl;
    std::cout << "19: " << a - d << std::endl;


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
