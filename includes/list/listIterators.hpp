#include "list.hpp"

template<class T, class Alloc>
ft::list<T, Alloc>::iterator::iterator() :
_M_node(NULL) {}

template<class T, class Alloc>
ft::list<T, Alloc>::iterator::iterator(ft::list<T, Alloc>::Node *list) : 
_M_node(list) {}

template<class T, class Alloc>
ft::list<T, Alloc>::iterator::iterator(const ft::list<T, Alloc>::Node *list) : 
_M_node(list) {}

template<class T, class Alloc>
ft::list<T, Alloc>::iterator::iterator(const iterator &rhs) : 
_M_node(rhs._M_node) {}

template<class T, class Alloc>
ft::list<T, Alloc>::iterator::~iterator() {}

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator    ft::list<T, Alloc>::iterator::operator++(int)
{
    iterator it = *this;
    ++*this;
    return it;
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator    &ft::list<T, Alloc>::iterator::operator++()
{
    if (_M_node)
       _M_node = _M_node->_M_next;
    return *this;
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator    &ft::list<T, Alloc>::iterator::operator--()
{
    if (_M_node)
       _M_node = _M_node->_M_prev;
    return *this;
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator    &ft::list<T, Alloc>::iterator::operator--(int)
{
    if (_M_node)
       _M_node = _M_node->_M_prev;
    return *this;
}

template<class T, class Alloc>
bool    ft::list<T, Alloc>::iterator::operator!=(const iterator &rhs)
{
    if (_M_node != rhs._M_node)
        return true;
    return false;
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::reference  ft::list<T, Alloc>::iterator::operator*()
{
    return _M_node->_data;
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::pointer  ft::list<T, Alloc>::iterator::operator->()
{
    return &(_M_node->_data);
}

template<class T, class Alloc>
void        ft::list<T, Alloc>::iterator::operator=(const iterator &rhs)
{
    _M_node = rhs._M_node;
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator        ft::list<T, Alloc>::begin()
{
    ft::list<T, Alloc>::iterator it(_list);
    return it;
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::iterator        ft::list<T, Alloc>::end()
{
    ft::list<T, Alloc>::iterator it;
    return it;
}

template<typename T, class Alloc>
typename ft::list<T, Alloc>::const_iterator            ft::list<T, Alloc>::begin() const
{
    ft::list<T, Alloc>::const_iterator it(_list);
    return it;
}

template<typename T, class Alloc>
typename ft::list<T, Alloc>::const_iterator            ft::list<T, Alloc>::end() const
{
    ft::list<T, Alloc>::const_iterator it;
    return it;
}

template<typename T, class Alloc>
typename ft::reverse_iterator<typename ft::list<T, Alloc>::iterator>            ft::list<T, Alloc>::rbegin()
{
    ft::reverse_iterator<typename ft::list<T, Alloc>::iterator> rit((iterator(lastList(_list))));
    return rit;
}

template<typename T, class Alloc>
typename ft::reverse_iterator<typename ft::list<T, Alloc>::iterator>            ft::list<T, Alloc>::rend()
{
    ft::reverse_iterator<typename ft::list<T, Alloc>::iterator> rit((iterator()));
    return rit;
}

template<typename T, class Alloc>
typename ft::list<T, Alloc>::const_reverse_iterator            ft::list<T, Alloc>::rbegin() const
{
    ft::list<T, Alloc>::const_reverse_iterator crit((const_iterator(lastList(_list))));
    return crit;
}

template<typename T, class Alloc>
typename ft::list<T, Alloc>::const_reverse_iterator            ft::list<T, Alloc>::rend() const
{
    ft::list<T, Alloc>::const_reverse_iterator crit((const_iterator()));
    return crit;
}
