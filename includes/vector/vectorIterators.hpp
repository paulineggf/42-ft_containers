#include "vector.hpp"

template<typename T, class Alloc>
ft::vector<T, Alloc>::iterator::iterator() :
_arg(0),
_idx(0) {
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::iterator::iterator(pointer arg, size_type idx) :
_arg(arg),
_idx(idx) {
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::iterator::iterator(const ft::vector<T, Alloc>::iterator &rhs) :
_arg(rhs._arg),
_idx(rhs._idx) {
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::iterator::~iterator() {}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator
ft::vector<T, Alloc>::iterator::operator+(int nb)
{
    ft::vector<T, Alloc>::iterator it(_arg, _idx + nb);
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator    ft::vector<T, Alloc>::iterator::operator-(int nb)
{
    ft::vector<T, Alloc>::iterator it(_arg, _idx - nb);
    return it;
}

template<typename T, class Alloc>
void                                       ft::vector<T, Alloc>::iterator::operator+=(int nb)
{
    _idx = _idx + nb;
}

template<typename T, class Alloc>
void                                       ft::vector<T, Alloc>::iterator::operator-=(int nb)
{
    _idx = _idx - nb;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator    ft::vector<T, Alloc>::iterator::operator++(int)
{
    ft::vector<T, Alloc>::iterator it(_arg, _idx);
    _idx += 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator    ft::vector<T, Alloc>::iterator::operator++()
{
    ft::vector<T, Alloc>::iterator it(_arg, _idx);
    _idx += 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator    ft::vector<T, Alloc>::iterator::operator--(int)
{
    ft::vector<T, Alloc>::iterator it(_arg, _idx);
    _idx -= 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator    ft::vector<T, Alloc>::iterator::operator--()
{
    ft::vector<T, Alloc>::iterator it(_arg, _idx);
    _idx -= 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::reference       ft::vector<T, Alloc>::iterator::operator*()
{
    return _arg[_idx];
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::pointer         ft::vector<T, Alloc>::iterator::operator->()
{
    return &((_arg)[_idx]);
}


template<typename T, class Alloc>
bool    ft::vector<T, Alloc>::iterator::operator!=(const ft::vector<T, Alloc>::iterator &rhs)
{
    if ((&(_arg[_idx])) != (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::iterator::operator=(const ft::vector<T, Alloc>::iterator &rhs)
{
    _arg = rhs._arg;
    _idx = rhs._idx;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::iterator::operator<(const ft::vector<T, Alloc>::iterator &rhs)
{
    if ((&(_arg[_idx])) < (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::iterator::operator>(const ft::vector<T, Alloc>::iterator &rhs)
{
    if ((&(_arg[_idx])) > (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::iterator::operator<=(const ft::vector<T, Alloc>::iterator &rhs)
{
     if ((&(_arg[_idx])) <= (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::iterator::operator>=(const ft::vector<T, Alloc>::iterator &rhs)
{
    if ((&(_arg[_idx])) >= (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::iterator::operator==(const ft::vector<T, Alloc>::iterator &rhs)
{
    if ((&(_arg[_idx])) == (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::reference        ft::vector<T, Alloc>::iterator::operator[](int nb)
{
    return _arg[nb];
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator            ft::vector<T, Alloc>::begin()
{
    ft::vector<T, Alloc>::iterator it(this->_arg, 0);
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator            ft::vector<T, Alloc>::end()
{
    ft::vector<T, Alloc>::iterator it(this->_arg, this->size());
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator            ft::vector<T, Alloc>::begin() const
{
    ft::vector<T, Alloc>::const_iterator it(this->_arg, 0);
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator            ft::vector<T, Alloc>::end() const
{
    ft::vector<T, Alloc>::const_iterator it(this->_arg, this->size());
    return it;
}

template<typename T, class Alloc>
typename ft::reverse_iterator<typename ft::vector<T, Alloc>::iterator>          ft::vector<T, Alloc>::rbegin()
{
    ft::reverse_iterator<typename ft::vector<T, Alloc>::iterator> rit((iterator(this->_arg, this->size())));
    return rit;
}

template<typename T, class Alloc>
typename ft::reverse_iterator<typename ft::vector<T, Alloc>::iterator>          ft::vector<T, Alloc>::rend()
{
    ft::reverse_iterator<typename ft::vector<T, Alloc>::iterator> rit((iterator(this->_arg, 0)));
    return rit;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator          ft::vector<T, Alloc>::rbegin() const
{
    ft::vector<T, Alloc>::const_reverse_iterator crit((const_iterator(this->_arg, this->size())));
    return crit;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator          ft::vector<T, Alloc>::rend() const
{

    ft::vector<T, Alloc>::const_reverse_iterator crit((const_iterator(this->_arg, 0)));
    return crit;
}
