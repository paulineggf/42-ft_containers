#include "map.hpp"

template<class Key, class T, class Compare, class Alloc>
bool        ft::map<Key, T, Compare, Alloc>::empty() const
{
    return _data.empty();
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::size() const
{
    return _data.size();
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::max_size() const
{
    return _data.max_size();
}
