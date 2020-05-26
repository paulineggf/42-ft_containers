#include "map.hpp"

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator        ft::map<Key, T, Compare, Alloc>::find(const key_type &k)
{
    ft::map<Key, T, Compare, Alloc>::iterator it = _data.begin();

    for (; it != _data.end(); it++)
    {
        if (it->first == k)
            return it;
    }
    return it;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator        ft::map<Key, T, Compare, Alloc>::find(const key_type &k) const
{
    ft::map<Key, T, Compare, Alloc>::const_iterator it = _data.begin();

    for (; it != _data.end(); it++)
    {
        if (it->first == k)
            return it;
    }
    return it;
}

