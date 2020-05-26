#include "map.hpp"

template<class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::iterator::iterator() :
_data(NULL) {}

template<class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::iterator::iterator(ft::map<Key, T, Compare, Alloc>::value_type *data) : 
_data(data) {}

template<class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::iterator::iterator(const ft::map<Key, T, Compare, Alloc>::value_type *data) : 
_data(data) {}

template<class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::iterator::iterator(const iterator &rhs) : 
_data(rhs._data) {}

template<class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::iterator::~iterator() {}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator    ft::map<Key, T, Compare, Alloc>::iterator::operator++(int)
{
    iterator it = *this;
    ++*this;
    return it;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator    &ft::map<Key, T, Compare, Alloc>::iterator::operator++()
{
    if (_data)
       _data = _data->_M_next;
    return *this;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator    ft::map<Key, T, Compare, Alloc>::iterator::operator--()
{
    ft::map<Key, T, Compare, Alloc>::iterator it(_data);

    if (_data)
       _data = _data->_M_prev;
    return it;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator    ft::map<Key, T, Compare, Alloc>::iterator::operator--(int)
{
    ft::map<Key, T, Compare, Alloc>::iterator it(_data);
    
    if (_data)
       _data = _data->_M_prev;
    return it;
}

template<class Key, class T, class Compare, class Alloc>
bool    ft::map<Key, T, Compare, Alloc>::iterator::operator!=(const iterator &rhs)
{
    if (_data != rhs._data)
        return true;
    return false;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reference  ft::map<Key, T, Compare, Alloc>::iterator::operator*()
{
    return _data->_data;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::pointer  ft::map<Key, T, Compare, Alloc>::iterator::operator->()
{
    return &(_data->_data);
}

template<class Key, class T, class Compare, class Alloc>
void        ft::map<Key, T, Compare, Alloc>::iterator::operator=(const iterator &rhs)
{
    _data = rhs._data;
}

template<typename T, class Alloc>
bool        ft::map<Key, T, Compare, Alloc>::iterator::operator==(const ft::map<Key, T, Compare, Alloc>::iterator &rhs)
{
    if ((&(_data->_data)) == (&(rhs._data->_data)))
        return true;
    return false;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator        ft::map<Key, T, Compare, Alloc>::begin()
{
    ft::map<Key, T, Compare, Alloc>::iterator it(_map);
    return it;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator        ft::map<Key, T, Compare, Alloc>::end()
{
    ft::map<Key, T, Compare, Alloc>::iterator it;
    return it;
}

template<typename T, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator            ft::map<Key, T, Compare, Alloc>::begin() const
{
    ft::map<Key, T, Compare, Alloc>::const_iterator it(_map);
    return it;
}

template<typename T, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator            ft::map<Key, T, Compare, Alloc>::end() const
{
    ft::map<Key, T, Compare, Alloc>::const_iterator it;
    return it;
}

template<typename T, class Alloc>
typename ft::reverse_iterator<typename ft::map<Key, T, Compare, Alloc>::iterator>            ft::map<Key, T, Compare, Alloc>::rbegin()
{
    ft::reverse_iterator<typename ft::map<Key, T, Compare, Alloc>::iterator> rit((iterator(lastmap(_map))));
    return rit;
}

template<typename T, class Alloc>
typename ft::reverse_iterator<typename ft::map<Key, T, Compare, Alloc>::iterator>            ft::map<Key, T, Compare, Alloc>::rend()
{
    ft::reverse_iterator<typename ft::map<Key, T, Compare, Alloc>::iterator> rit((iterator()));
    return rit;
}

template<typename T, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator            ft::map<Key, T, Compare, Alloc>::rbegin() const
{
    ft::map<Key, T, Compare, Alloc>::const_reverse_iterator crit((const_iterator(lastmap(_map))));
    return crit;
}

template<typename T, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator            ft::map<Key, T, Compare, Alloc>::rend() const
{
    ft::map<Key, T, Compare, Alloc>::const_reverse_iterator crit((const_iterator()));
    return crit;
}
