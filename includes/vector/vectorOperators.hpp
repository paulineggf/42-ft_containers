#include "vector.hpp"

template<typename T, class Alloc>
ft::vector<T, Alloc>   &ft::vector<T, Alloc>::operator=(const ft::vector<T, Alloc> &rhs)
{
    if (!(rhs._arg))
    {
        for (size_type i = 0; i < _size; i++)
            _alloc.destroy(_arg + i);
        _alloc.deallocate(_arg, _capacity);
    }
    else
        this->assign(rhs.begin(), rhs.end());
    _size = rhs._size;
    _capacity = rhs._capacity;
    return *this;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::reference            ft::vector<T, Alloc>::operator[](size_type idx)
{
    return _arg[idx];
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference      ft::vector<T, Alloc>::operator[](size_type idx) const
{
    return _arg[idx];
}
