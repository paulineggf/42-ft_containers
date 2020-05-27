#include "map.hpp"

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_type &ft::map<Key, T, Compare, Alloc>::operator[](const key_type &k)
{
    iterator        it(_data.begin());
    value_compare   val_comp(_comp);
    value_type      p(k, 0);

    while (it != _data.end() && val_comp(*it, p))
        it++;
    if (it != _data.end() && it->first == k)
        return it->second;
    return _data.insert(it, p)->second;
}
