#include "vector.hpp"

template<typename T, class Alloc>
ft::vector<T, Alloc>::const_iterator::const_iterator() :
ft::vector<T, Alloc>::iterator() {}

template<typename T, class Alloc>
ft::vector<T, Alloc>::const_iterator::const_iterator(const ft::vector<T, Alloc> *arg, int idx) :
ft::vector<T, Alloc>::iterator(arg, idx) {}

template<typename T, class Alloc>
ft::vector<T, Alloc>::const_iterator::const_iterator(ft::vector<T, Alloc> *arg, int idx) :
ft::vector<T, Alloc>::iterator(arg, idx) {}

template<typename T, class Alloc>
ft::vector<T, Alloc>::const_iterator::const_iterator(ft::vector<T, Alloc>::iterator it) :
ft::vector<T, Alloc>::iterator(it) {
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::const_iterator::~const_iterator() {}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator    ft::vector<T, Alloc>::const_iterator::operator+(int nb)
{
    ft::vector<T, Alloc>::const_iterator it(this->_arg, this->_idx + nb);
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator    ft::vector<T, Alloc>::const_iterator::operator-(int nb)
{
    ft::vector<T, Alloc>::const_iterator it(this->_arg, this->_idx - nb);
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator    ft::vector<T, Alloc>::const_iterator::operator++(int)
{
    ft::vector<T, Alloc>::const_iterator it(this->_arg, this->_idx);
    this->_idx += 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator    ft::vector<T, Alloc>::const_iterator::operator++()
{
    ft::vector<T, Alloc>::const_iterator it(this->_arg, this->_idx);
    this->_idx += 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator    ft::vector<T, Alloc>::const_iterator::operator--(int)
{
    ft::vector<T, Alloc>::const_iterator it(this->_arg, this->_idx);
    this->_idx -= 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator    ft::vector<T, Alloc>::const_iterator::operator--()
{
    ft::vector<T, Alloc>::const_iterator it(this->_arg, this->_idx);
    this->_idx -= 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference       ft::vector<T, Alloc>::const_iterator::operator*() 
{
    return (*this->_arg)[this->_idx];
}

template<typename T, class Alloc>
bool    ft::vector<T, Alloc>::const_iterator::operator!=(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    if ((&(this->_arg[this->_idx])) != (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
void    ft::vector<T, Alloc>::const_iterator::operator=(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    this->_arg = rhs._arg;
    this->_idx = rhs._idx;
}

// template<typename T, class Alloc>
// void    ft::vector<T, Alloc>::const_iterator::operator=(ft::vector<T, Alloc>::iterator &rhs)
// {
//     this->_arg = rhs._arg;
//     this->_idx = rhs._idx;
// }


template<typename T, class Alloc>
void    ft::vector<T, Alloc>::const_iterator::operator=(ft::vector<T, Alloc>::iterator &rhs)
{
    ft::vector<T, Alloc>::const_iterator cit(rhs);
    *this = cit;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_iterator::operator<(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    if ((&(this->_arg[this->_idx])) < (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_iterator::operator>(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    if ((&(this->_arg[this->_idx])) > (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_iterator::operator<=(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    if ((&(this->_arg[this->_idx])) <= (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_iterator::operator>=(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    if ((&(this->_arg[this->_idx])) >= (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
bool        ft::vector<T, Alloc>::const_iterator::operator==(const ft::vector<T, Alloc>::const_iterator &rhs)
{
    if ((&(this->_arg[this->_idx])) == (&(rhs._arg[this->_idx])))
        return true;
    return false;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator            ft::vector<T, Alloc>::begin() const
{
    ft::vector<T, Alloc>::iterator it(this, 0);
    ft::vector<T, Alloc>::const_iterator cit(it);
    return cit;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator            ft::vector<T, Alloc>::end() const
{
    ft::vector<T, Alloc>::iterator it(this, this->size());
    ft::vector<T, Alloc>::const_iterator cit(it);
    return cit;
}
