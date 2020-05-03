#include "vector.hpp"

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::size_type        ft::vector<T, Alloc>::capacity() const
{
    return _capacity;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::size_type        ft::vector<T, Alloc>::size() const
{
    return _size;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::size_type        ft::vector<T, Alloc>::max_size()
{
    return std::numeric_limits<std::size_t>::max() / sizeof(T);
}

template<typename T, class Alloc>
void                            ft::vector<T, Alloc>::resize(size_type resize, T val)
{
    if (_size > resize)
    {
        for (; _size > resize; _size--)
            _alloc.destroy(_arg + _size);
    }
    else if (_size < resize)
    {
        for (size_type i = _size; i < resize; ++i)
            this->push_back(val);
    }
}

template<typename T, class Alloc>
bool                            ft::vector<T, Alloc>::empty() const
{
    if (_size == 0)
        return true;
    return false;
}

template<typename T, class Alloc>
void                            ft::vector<T, Alloc>::reserve(size_type n)
{
    if (n > _capacity)
    {
        T    *newArg;
        newArg = _alloc.allocate(n);
        for (size_type i = 0; i < _size; ++i)
            newArg[i] = _arg[i];
        _alloc.deallocate(_arg, _capacity);
        _arg = newArg;
        _capacity = n;
    }
}
