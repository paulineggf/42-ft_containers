#include "map.hpp"

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator        ft::map<Key, T, Compare, Alloc>::find(const key_type &k)
{
    ft::map<Key, T, Compare, Alloc>::iterator it = _data.begin();

    while (it != _data.end() && _comp(it->first, k))
        it++;
    return it;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator        ft::map<Key, T, Compare, Alloc>::find(const key_type &k) const
{
    ft::map<Key, T, Compare, Alloc>::const_iterator it = _data.begin();

    while (it != _data.end() && _comp(it->first, k))
        it++;
    return it;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type         ft::map<Key, T, Compare, Alloc>::count(const key_type &k) const
{
    ft::map<Key, T, Compare, Alloc>::iterator it = _data.begin();

    while (it != _data.end() && _comp(it->first, k))
        it++;
    if (it != _data.end() && it->first == k)
            return 1;
    return 0;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator         ft::map<Key, T, Compare, Alloc>::lower_bound(const key_type &k)
{
    ft::map<Key, T, Compare, Alloc>::iterator it = _data.begin();

    while (it != _data.end() && _comp(it->first, k))
        it++;
    return it;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator        ft::map<Key, T, Compare, Alloc>::lower_bound(const key_type &k) const
{
    ft::map<Key, T, Compare, Alloc>::const_iterator it = _data.begin();

    while (it != _data.end() && _comp(it->first, k))
        it++;
    return it;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator         ft::map<Key, T, Compare, Alloc>::upper_bound(const key_type &k)
{
    ft::map<Key, T, Compare, Alloc>::iterator it = _data.begin();

    while (it != _data.end() && _comp(it->first, k))
        it++;
    if (it != _data.end() && it->first == k)
    {
        it++;
        return it;
    }
    return it;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator        ft::map<Key, T, Compare, Alloc>::upper_bound(const key_type &k) const
{
    ft::map<Key, T, Compare, Alloc>::const_iterator it = _data.begin();

    while (it != _data.end() && _comp(it->first, k))
        it++;
    if (it != _data.end() && it->first == k)
    {
        it++;
        return it;
    }
    return it;
}

template<class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::const_iterator, typename ft::map<Key, T, Compare, Alloc>::const_iterator>
            ft::map<Key, T, Compare, Alloc>::equal_range(const key_type &k) const
{
    ft::map<Key, T, Compare, Alloc>::const_iterator it = _data.begin();
    ft::map<Key, T, Compare, Alloc>::const_iterator it2;

    while (it != _data.end() && _comp(it->first, k))
        it++;
    it2 = it;
    if (it != _data.end())
        it++;
    return ft::pair<typename ft::map<Key, T, Compare, Alloc>::const_iterator, typename ft::map<Key, T, Compare, Alloc>::const_iterator>(it2, it);
}

template<class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, typename ft::map<Key, T, Compare, Alloc>::iterator>
            ft::map<Key, T, Compare, Alloc>::equal_range(const key_type &k)
{
    ft::map<Key, T, Compare, Alloc>::iterator it = _data.begin();
    ft::map<Key, T, Compare, Alloc>::iterator it2;

    while (it != _data.end() && _comp(it->first, k))
        it++;
    it2 = it;
    if (it != _data.end())
        it++;
    return ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, typename ft::map<Key, T, Compare, Alloc>::iterator>(it2, it);
}
