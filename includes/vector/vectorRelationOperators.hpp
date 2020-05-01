#include "vector.hpp"

template<typename T, class Alloc>
bool        operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    typename ft::vector<T, Alloc>::size_type size;
    
    size = lhs.size();
    if (size != rhs.size())
        return false;
    for (typename ft::vector<T, Alloc>::size_type i = 0; i < size; i++)
        if (lhs.at(i) != rhs.at(i))
            return false;
    return true;
}

template<typename T, class Alloc>
bool        operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    return !(lhs==rhs);
}

bool         operator<(const ft::vector<std::string> &lhs, const ft::vector<std::string> &rhs)
{
    ft::vector<std::string>::size_type lhsSize;
    ft::vector<std::string>::size_type rhsSize;
    ft::vector<std::string>::size_type i;

    lhsSize = lhs.size();
    rhsSize = rhs.size();
    for (i = 0; i < lhsSize && i < rhsSize; i++)
        if (lhs.at(i).compare(rhs.at(i)) < 0)
            return true;
    if (lhsSize == rhsSize)
        return true;
    return false;
}

template<typename T, class Alloc>
bool         operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    typename ft::vector<T, Alloc>::size_type lhsSize;
    typename ft::vector<T, Alloc>::size_type rhsSize;
    typename ft::vector<T, Alloc>::size_type lhsRes;
    typename ft::vector<T, Alloc>::size_type rhsRes;
    typename ft::vector<T, Alloc>::size_type i;
    
    lhsRes = 0;
    rhsRes = 0;
    lhsSize = lhs.size();
    rhsSize = rhs.size();
    for (i = 0; i < lhsSize; i++)
        lhsRes += lhs.at(i);
    for (i = 0; i < rhsSize; i++)
        rhsRes += rhs.at(i);
    if (lhsRes < rhsRes)
        return true;
    return false;
}

template<typename T, class Alloc>
bool   operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    return (rhs < lhs);
}

template<typename T, class Alloc>
bool   operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    typename ft::vector<T, Alloc>::size_type lhsSize;
    typename ft::vector<T, Alloc>::size_type rhsSize;
    typename ft::vector<T, Alloc>::size_type lhsRes;
    typename ft::vector<T, Alloc>::size_type rhsRes;

    lhsRes = 0;
    rhsRes = 0;
    lhsSize = lhs.size();
    rhsSize = rhs.size();
    for (typename ft::vector<T, Alloc>::size_type i = 0; i < lhsSize; i++)
        lhsRes += lhs.at(i);
    for (typename ft::vector<T, Alloc>::size_type i = 0; i < rhsSize; i++)
        rhsRes += rhs.at(i);
    if (lhsRes <= rhsRes)
        return true;
    return false;
}

bool         operator<=(const ft::vector<std::string> &lhs, const ft::vector<std::string> &rhs)
{
    ft::vector<std::string>::size_type lhsSize;
    ft::vector<std::string>::size_type rhsSize;
    ft::vector<std::string>::size_type i;

    lhsSize = lhs.size();
    rhsSize = rhs.size();
    for (i = 0; i < lhsSize && i < rhsSize; i++)
        if (lhs.at(i).compare(rhs.at(i)) < 0)
            return true;
    if (lhsSize == rhsSize)
        return true;
    return false;
}

template<typename T, class Alloc>
bool   operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    return (rhs <= lhs);
}
