#include "list.hpp"

template<typename T, class Alloc>
bool        operator==(const ft::list<T, Alloc> &lhs, const ft::list<T, Alloc> &rhs)
{
    typename ft::list<T, Alloc>::size_type size;
    typename ft::list<T, Alloc>::iterator it(lhs.begin());
    typename ft::list<T, Alloc>::iterator it2(rhs.begin());

    size = lhs.size();
    if (size != rhs.size())
        return false;
    for (; it != lhs.end(); it++)
    {
        if (*it != *it2)
            return false;
        it2++;
    }
    return true;
}

template<typename T, class Alloc>
bool        operator!=(const ft::list<T, Alloc> &lhs, const ft::list<T, Alloc> &rhs)
{
    return !(lhs==rhs);
}

template<typename T, class Alloc>
bool         operator<(const ft::list<T, Alloc> &lhs, const ft::list<T, Alloc> &rhs)
{
    typename ft::list<T, Alloc>::iterator it(lhs.begin());
    typename ft::list<T, Alloc>::iterator it2(rhs.begin());
    
    for (; it != lhs.end(); it++)
    {
        if (*it < *it2)
            return true;
        it2++;
    }
    return false;
}

template<typename T, class Alloc>
bool   operator>(const ft::list<T, Alloc> &lhs, const ft::list<T, Alloc> &rhs)
{
    return (rhs < lhs);
}

template<typename T, class Alloc>
bool   operator<=(const ft::list<T, Alloc> &lhs, const ft::list<T, Alloc> &rhs)
{
    typename ft::list<T, Alloc>::iterator it(lhs.begin());
    typename ft::list<T, Alloc>::iterator it2(rhs.begin());
    
    for (; it != lhs.end(); it++)
    {
        if (*it <= *it2)
            return true;
        it2++;
    }
    return false;
}

template<typename T, class Alloc>
bool   operator>=(const ft::list<T, Alloc> &lhs, const ft::list<T, Alloc> &rhs)
{
    return (rhs <= lhs);
}
