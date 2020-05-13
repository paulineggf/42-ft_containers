#include "vector.hpp"

// template<typename iter_type>
// template<typename T, class Alloc>
// ft::vector<T, Alloc>::const_reverse_iterator::const_reverse_iterator() :
// ft::reverse_iterator() {}
// // _it(0) {
// // }

// template<typename iter_type>
// template<typename T, class Alloc>
// ft::vector<T, Alloc>::const_reverse_iterator::const_reverse_iterator(ft::vector<T, Alloc>::const_iterator it) :
// ft::reverse_iterator<const_iterator>(it) {}
// // _it(it) {
//     // _it--;
// // }

// template<typename T, class Alloc>
// ft::vector<T, Alloc>::const_reverse_iterator::const_reverse_iterator(const ft::vector<T, Alloc>::const_reverse_iterator &crit) :
// _it(crit._it) {
// }

// template<typename iter_type>
// template<typename T, class Alloc>
// ft::vector<T, Alloc>::const_reverse_iterator::const_reverse_iterator(const ft::reverse_iterator<iter_type> &rit) :
// ft::reverse_iterator(rit) {}
// // _it(rit._it) {
// // }

// template<typename T, class Alloc>
// ft::vector<T, Alloc>::const_reverse_iterator::~const_reverse_iterator() {}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator        ft::vector<T, Alloc>::const_reverse_iterator::operator+(int nb)
{
    this->_it - nb;
    return *this;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator        ft::vector<T, Alloc>::const_reverse_iterator::operator-(int nb)
{
    this->_it + nb;
    return *this;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator          ft::vector<T, Alloc>::const_reverse_iterator::operator++()
{
    this->_it--;
    return *this;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator           ft::vector<T, Alloc>::const_reverse_iterator::operator++(int)
{
    this->_it--;
    return *this;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator                    ft::vector<T, Alloc>::const_reverse_iterator::operator--()
{
    this->_it++;
    return *this;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator                    ft::vector<T, Alloc>::const_reverse_iterator::operator--(int)
{
    this->_it++;
    return *this;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference   ft::vector<T, Alloc>::const_reverse_iterator::operator*()
{
    return  *(this->_it);
}

template<typename T, class Alloc>
bool                    ft::vector<T, Alloc>::const_reverse_iterator::operator!=(const const_reverse_iterator &rhs)
{
    return this->_it != rhs._it;
}

template<typename T, class Alloc>
void                    ft::vector<T, Alloc>::const_reverse_iterator::operator=(const ft::vector<T, Alloc>::const_reverse_iterator &rhs)
{
    this->_it = rhs._it;
}

template<typename T, class Alloc>
bool                    ft::vector<T, Alloc>::const_reverse_iterator::operator<(const ft::vector<T, Alloc>::const_reverse_iterator &rhs)
{
    return this->_it < rhs._it;
}

template<typename T, class Alloc>
bool                    ft::vector<T, Alloc>::const_reverse_iterator::operator>(const ft::vector<T, Alloc>::const_reverse_iterator &rhs)
{
    return this->_it > rhs._it;
}

template<typename T, class Alloc>
bool                    ft::vector<T, Alloc>::const_reverse_iterator::operator<=(const ft::vector<T, Alloc>::const_reverse_iterator &rhs)
{
    return this->_it <= rhs._it;
}

template<typename T, class Alloc>
bool                    ft::vector<T, Alloc>::const_reverse_iterator::operator>=(const ft::vector<T, Alloc>::const_reverse_iterator &rhs)
{
    return this->_it >= rhs._it;
}

template<typename T, class Alloc>
bool                    ft::vector<T, Alloc>::const_reverse_iterator::operator==(const ft::vector<T, Alloc>::const_reverse_iterator &rhs)
{
    return this->_it == rhs._it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator    ft::vector<T, Alloc>::rbegin() const
{
    const_reverse_iterator crit(const_iterator(this, this->size()));
    return crit;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator    ft::vector<T, Alloc>::rend() const
{
    const_reverse_iterator crit(const_iterator(this, 0));
    return crit;
}
