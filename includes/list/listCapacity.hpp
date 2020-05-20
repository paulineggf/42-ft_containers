#include "list.hpp"

template<class T, class Alloc>
typename ft::list<T, Alloc>::size_type  ft::list<T, Alloc>::size() const
{
    return _size;
}

template<class T, class Alloc>
bool        ft::list<T, Alloc>::empty() const
{
    if (_size == 0)
        return true;
    return false;
}

template<typename T, class Alloc>
typename ft::list<T, Alloc>::size_type        ft::list<T, Alloc>::max_size() const
{
    return std::numeric_limits<std::size_t>::max() / sizeof(ft::list<T, Alloc>);
}
