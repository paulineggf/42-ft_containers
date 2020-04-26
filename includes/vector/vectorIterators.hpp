#include "vector.hpp"

template<typename T>
ft::vector<T>::iterator::iterator() :
_arg(0),
_idx(0) {
}

template<typename T>
ft::vector<T>::iterator::iterator(ft::vector<T> *arg, int idx) :
_arg(arg),
_idx(idx) {
}

template<typename T>
ft::vector<T>::iterator::~iterator() {}

template<typename T>
typename ft::vector<T>::iterator    ft::vector<T>::iterator::operator+(int nb)
{
    ft::vector<T>::iterator it(_arg, nb);
    return it;
}

template<typename T>
typename ft::vector<T>::iterator    ft::vector<T>::iterator::operator-(int nb)
{
    ft::vector<T>::iterator it(_arg, _idx - nb);
    return it;
}

template<typename T>
void    ft::vector<T>::iterator::operator++(int)
{
    _idx += 1;
}

template<typename T>
void    ft::vector<T>::iterator::operator++()
{
    _idx += 1;
}

template<typename T>
void    ft::vector<T>::iterator::operator--(int)
{
    _idx -= 1;
}

template<typename T>
void    ft::vector<T>::iterator::operator--()
{
    _idx -= 1;
}

template<typename T>
T       &ft::vector<T>::iterator::operator*()
{
    return (*_arg)[_idx];
}

template<typename T>
bool    ft::vector<T>::iterator::operator!=(const ft::vector<T>::iterator &rhs)
{
    if ((&(_arg[_idx])) != (&(rhs._arg[rhs._idx])))
        return true;
    return false;
}

template<typename T>
size_t      ft::vector<T>::iterator::getIdx()
{
    return _idx;
}

template<typename T>
void    ft::vector<T>::iterator::operator=(ft::vector<T> *rhs)
{
    _idx = rhs->size();
}

template<typename T>
typename ft::vector<T>::iterator            ft::vector<T>::begin()
{
    ft::vector<T>::iterator it(this, 0);
    return it;
}

template<typename T>
typename ft::vector<T>::iterator            ft::vector<T>::end()
{
    ft::vector<T>::iterator it(this, this->size());
    return it;
}
