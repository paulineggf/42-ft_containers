#include "vector.hpp"

template<typename T, class Alloc>
ft::vector<T, Alloc>   &ft::vector<T, Alloc>::operator=(const ft::vector<T, Alloc> &rhs)
{
    ft::vector<T, Alloc>::const_iterator it = rhs.begin();
    // this->assign(rhs.begin(), rhs.end());
    // for (size_type i = 0; i < rhs._size; i++)
        // this->push_back(rhs.at(i));
    _size = rhs._size;
    _capacity = rhs._capacity;
    return *this;
}

template<typename T, class Alloc>
T               &ft::vector<T, Alloc>::operator[](int idx)
{
    return _arg[idx];
}
