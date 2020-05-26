#include "map.hpp"

template<class Key, class T, class Compare, class Alloc>
void            ft::map<Key, T, Compare, Alloc>::erase(iterator position)
{
    _data.erase(position);
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type            ft::map<Key, T, Compare, Alloc>::erase(const key_type &k)
{
    ft::map<Key, T, Compare, Alloc>::size_type size;

    size = 0;
    for (ft::map<Key, T, Compare, Alloc>::iterator it = _data.begin();
    it != _data.end(); it++)
    {
        if (it->first == k)
        {
            _data.erase(it);
            size++;
        }
    }
    return size;
}

template<class Key, class T, class Compare, class Alloc>
void            ft::map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
{
    _data.erase(first, last);
}

template<class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>     ft::map<Key, T, Compare, Alloc>::insert(const value_type &val)
{
    iterator        it(_data.begin());
    value_compare   val_comp(_comp);

    while (it != _data.end() && val_comp(*it, val))
        it++;
    if (it != _data.end() && it->first == val.first)
            return ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>(it, false);
    _data.insert(it, val);
    return ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>(it, true);
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator   ft::map<Key, T, Compare, Alloc>::insert(iterator position, const value_type &val)
{
    value_compare   val_comp(_comp);

    while (position != _data.end() && val_comp(*position, val))
        position++;
    if (position != _data.end() && position->first == val.first)
            return position;
    _data.insert(position, val);
    return position;
}

template<class Key, class T, class Compare, class Alloc>
template<class InputIterator>
void   ft::map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
    iterator        it(_data.begin());
    value_compare   val_comp(_comp);


    while (it != _data.end() && val_comp(*it, *first))
        it++;
    _data.insert(it, first, last);
}

template<class Key, class T, class Compare, class Alloc>
void    ft::map<Key, T, Compare, Alloc>::swap(map &x)
{
    _data.swap(x._data);
}

template<class Key, class T, class Compare, class Alloc>
void    ft::map<Key, T, Compare, Alloc>::clear()
{
    _data.clear();
}
