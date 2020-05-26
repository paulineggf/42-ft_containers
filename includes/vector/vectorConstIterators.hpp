#include "vector.hpp"

template<typename T, class Alloc>
ft::vector<T, Alloc>::const_iterator::const_iterator() :
_arg(0),
_idx(0) {
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::const_iterator::const_iterator(ft::vector<T, Alloc> *arg, size_type idx) :
_arg(arg),
_idx(idx) {
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::const_iterator::const_iterator(const ft::vector<T, Alloc>::iterator &rhs) :
_arg(rhs._arg),
_idx(rhs._idx) {
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::const_iterator::~const_iterator() {}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator
ft::vector<T, Alloc>::const_iterator::operator+(int nb)
{
    ft::vector<T, Alloc>::const_iterator it(_arg, _idx + nb);
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator    ft::vector<T, Alloc>::const_iterator::operator-(int nb)
{
    ft::vector<T, Alloc>::const_iterator it(_arg, _idx - nb);
    return it;
}

template<typename T, class Alloc>
void                                       ft::vector<T, Alloc>::const_iterator::operator+=(int nb)
{
    _idx = _idx + nb;
}

template<typename T, class Alloc>
void                                       ft::vector<T, Alloc>::const_iterator::operator-=(int nb)
{
    _idx = _idx - nb;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator    ft::vector<T, Alloc>::const_iterator::operator++(int)
{
    ft::vector<T, Alloc>::const_iterator it(_arg, _idx);
    _idx += 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator    ft::vector<T, Alloc>::const_iterator::operator++()
{
    ft::vector<T, Alloc>::const_iterator it(_arg, _idx);
    _idx += 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator    ft::vector<T, Alloc>::const_iterator::operator--(int)
{
    ft::vector<T, Alloc>::const_iterator it(_arg, _idx);
    _idx -= 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator    ft::vector<T, Alloc>::const_iterator::operator--()
{
    ft::vector<T, Alloc>::const_iterator it(_arg, _idx);
    _idx -= 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference       ft::vector<T, Alloc>::const_iterator::operator*()
{
    return (*_arg)[_idx];
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::value_type         ft::vector<T, Alloc>::const_iterator::operator->()
{
    return ((*_arg)[_idx]);
}


template<typename T, class Alloc>
bool    ft::vector<T, Alloc>::const_iterator::operator!=(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    if ((&(_arg[_idx])) != (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::const_iterator::operator=(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    _arg = rhs._arg;
    _idx = rhs._idx;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_iterator::operator<(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    if ((&(_arg[_idx])) < (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_iterator::operator>(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    if ((&(_arg[_idx])) > (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_iterator::operator<=(const ft::vector<T, Alloc>::const_iterator &rhs)
{
     if ((&(_arg[_idx])) <= (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_iterator::operator>=(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    if ((&(_arg[_idx])) >= (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_iterator::operator==(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    if ((&(_arg[_idx])) == (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference        ft::vector<T, Alloc>::const_iterator::operator[](int nb)
{
    return (*_arg)[nb];
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator       ft::vector<T, Alloc>::begin() const
{
    ft::vector<T, Alloc>::const_iterator it(this, 0);
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator       ft::vector<T, Alloc>::end() const
{
    ft::vector<T, Alloc>::const_iterator it(this, this->size());
    return it;
}