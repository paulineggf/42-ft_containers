#include "vector.hpp"

template<typename T, class Alloc>
T                   &ft::vector<T, Alloc>::back()
{
    return _arg[_size - 1];
}

template<typename T, class Alloc>
T                   &ft::vector<T, Alloc>::front()
{
    return _arg[0];
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::reference            ft::vector<T, Alloc>::at(size_type n)
{
    return _arg[n];
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference     ft::vector<T, Alloc>::at(size_type n) const
{
    return _arg[n];
}