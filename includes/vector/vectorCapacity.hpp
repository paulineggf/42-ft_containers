#include "vector.hpp"

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::size_type        ft::vector<T, Alloc>::capacity()
{
    return _capacity;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::size_type        ft::vector<T, Alloc>::size() const
{
    return _size;
}

template<typename T, class Alloc>
long int                        ft::vector<T, Alloc>::max_size()
{
    return std::numeric_limits<std::size_t>::max() / sizeof(T);
}

template<typename T, class Alloc>
void                            ft::vector<T, Alloc>::resize(size_type resize)
{
    if (_size > resize)
    {
        T    *newArg = new T[resize];
        for (size_type i = 0; i < resize; ++i)
            newArg[i] = _arg[i];
        delete [] _arg;
        _arg = newArg;
        _size = resize;
    }
    else if (_size < resize)
    {
        for (size_type i = _size; i < resize; ++i)
            this->push_back(0);
    }
}

template<typename T, class Alloc>
void                            ft::vector<T, Alloc>::resize(size_type resize, T val)
{
    if (_size > resize)
    {
        T    *newArg = new T[resize];
        for (size_type i = 0; i < resize; ++i)
            newArg[i] = _arg[i];
        delete [] _arg;
        _arg = newArg;
        _size = resize;
    }
    else if (_size < resize)
    {
        for (size_type i = _size; i < resize; ++i)
            this->push_back(val);
    }
}

template<typename T, class Alloc>
bool                            ft::vector<T, Alloc>::empty()
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
        T    *newArg = new T[n];
        for (size_type i = 0; i < _size; ++i)
            newArg[i] = _arg[i];
        delete [] _arg;
        _arg = newArg;
        _capacity = n;
    }
}
