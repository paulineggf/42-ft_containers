#include "vector.hpp"

template<typename T, class Alloc>
ft::vector<T, Alloc>::const_reverse_iterator::const_reverse_iterator() :
_arg(0),
_idx(0) {
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::const_reverse_iterator::const_reverse_iterator(ft::vector<T, Alloc> *arg, int idx) :
_arg(arg),
_idx(idx) {
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::const_reverse_iterator::~const_reverse_iterator() {}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator    ft::vector<T, Alloc>::const_reverse_iterator::operator+(int nb)
{
    ft::vector<T, Alloc>::const_reverse_iterator it(_arg, _idx + nb);
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator    ft::vector<T, Alloc>::const_reverse_iterator::operator-(int nb)
{
    ft::vector<T, Alloc>::const_reverse_iterator it(_arg, _idx - nb);
    return it;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::const_reverse_iterator::operator++(int)
{
    _idx -= 1;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::const_reverse_iterator::operator++()
{
    _idx -= 1;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::const_reverse_iterator::operator--(int)
{
    _idx += 1;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::const_reverse_iterator::operator--()
{
    _idx += 1;
}

template<typename T, class Alloc>
T       &ft::vector<T, Alloc>::const_reverse_iterator::operator*()
{
    return (*_arg)[_idx];
}

template<typename T, class Alloc>
bool    ft::vector<T, Alloc>::const_reverse_iterator::operator!=(const ft::vector<T, Alloc>::const_reverse_iterator &rhs)
{
    if (this->_idx != rhs._idx)
        return true;
    return false;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::const_reverse_iterator::operator=(ft::vector<T, Alloc> *rhs)
{
    _idx = rhs->size();
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_reverse_iterator::operator<(const ft::vector<T, Alloc>::const_reverse_iterator &rhs)
{
    if (_idx < rhs._idx)
        return false;
    return true;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_reverse_iterator::operator>(const ft::vector<T, Alloc>::const_reverse_iterator &rhs)
{
    if (_idx > rhs._idx)
        return false;
    return true;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_reverse_iterator::operator<=(const ft::vector<T, Alloc>::const_reverse_iterator &rhs)
{
    if (_idx <= rhs._idx)
        return false;
    return true;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_reverse_iterator::operator>=(const ft::vector<T, Alloc>::const_reverse_iterator &rhs)
{
    if (_idx >= rhs._idx)
        return false;
    return true;
}

// template<typename T, class Alloc>
// bool        ft::vector<T, Alloc>::const_reverse_iterator::operator==(const ft::vector<T, Alloc>::iterator &rhs)
// {
//     if (_arg == rhs._arg)
//         return true;
//     return false;
// }

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::size_type      ft::vector<T, Alloc>::const_reverse_iterator::getIdx()
{
    return _idx;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator    ft::vector<T, Alloc>::rbegin() const
{
    ft::vector<T, Alloc>::const_reverse_iterator it(this, this->size() - 1);
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator    ft::vector<T, Alloc>::rend() const
{
    ft::vector<T, Alloc>::const_reverse_iterator it(this, -1);
    return it;
}


