#include "vector.hpp"

template<typename T, class Alloc>
ft::vector<T, Alloc>::iterator::iterator() :
_arg(0),
_idx(0) {
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::iterator::iterator(ft::vector<T, Alloc> *arg, int idx) :
_arg(arg),
_idx(idx) {
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::iterator::~iterator() {}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator    ft::vector<T, Alloc>::iterator::operator+(int nb)
{
    ft::vector<T, Alloc>::iterator it(_arg, nb);
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator    ft::vector<T, Alloc>::iterator::operator-(int nb)
{
    ft::vector<T, Alloc>::iterator it(_arg, _idx - nb);
    return it;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::iterator::operator++(int)
{
    _idx += 1;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::iterator::operator++()
{
    _idx += 1;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::iterator::operator--(int)
{
    _idx -= 1;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::iterator::operator--()
{
    _idx -= 1;
}

template<typename T, class Alloc>
T       &ft::vector<T, Alloc>::iterator::operator*()
{
    return (*_arg)[_idx];
}

template<typename T, class Alloc>
bool    ft::vector<T, Alloc>::iterator::operator!=(const ft::vector<T, Alloc>::iterator &rhs)
{
    if ((&(_arg[_idx])) != (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::iterator::operator=(ft::vector<T, Alloc> *rhs)
{
    _idx = rhs->size();
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::iterator::operator<(const ft::vector<T, Alloc>::iterator &rhs)
{
    if (_idx < rhs._idx)
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::iterator::operator>(const ft::vector<T, Alloc>::iterator &rhs)
{
    if (_idx > rhs._idx)
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::iterator::operator<=(const ft::vector<T, Alloc>::iterator &rhs)
{
    if (_idx <= rhs._idx)
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::iterator::operator>=(const ft::vector<T, Alloc>::iterator &rhs)
{
    if (_idx >= rhs._idx)
        return true;
    return false;
}

// template<typename T, class Alloc>
// bool        ft::vector<T, Alloc>::reverse_iterator::operator==(const ft::vector<T, Alloc>::iterator &rhs)
// {
//     if (_arg == rhs._arg)
//         return true;
//     return false;
// }

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::size_type        ft::vector<T, Alloc>::iterator::getIdx()
{
    return _idx;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator            ft::vector<T, Alloc>::begin()
{
    ft::vector<T, Alloc>::iterator it(this, 0);
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator            ft::vector<T, Alloc>::begin() const
{
    std::cout << "const_iterator" << std::endl;
    ft::vector<T, Alloc>::const_iterator it(this, 0);
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator            ft::vector<T, Alloc>::end()
{
    ft::vector<T, Alloc>::iterator it(this, this->size());
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator            ft::vector<T, Alloc>::end() const
{
    ft::vector<T, Alloc>::const_iterator it(this, this->size());
    return it;
}

