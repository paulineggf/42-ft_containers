#include "vector.hpp"

template<typename T>
ft::vector<T>::reverse_iterator::reverse_iterator() :
_arg(0),
_idx(0) {
}

template<typename T>
ft::vector<T>::reverse_iterator::reverse_iterator(ft::vector<T> *arg, int idx) :
_arg(arg),
_idx(idx) {
}

template<typename T>
ft::vector<T>::reverse_iterator::~reverse_iterator() {}

template<typename T>
typename ft::vector<T>::reverse_iterator    ft::vector<T>::reverse_iterator::operator+(int nb)
{
    ft::vector<T>::reverse_iterator it(_arg, _idx + nb);
    return it;
}

template<typename T>
typename ft::vector<T>::reverse_iterator    ft::vector<T>::reverse_iterator::operator-(int nb)
{
    ft::vector<T>::reverse_iterator it(_arg, _idx - nb);
    return it;
}

template<typename T>
void    ft::vector<T>::reverse_iterator::operator++(int)
{
    _idx -= 1;
}

template<typename T>
void    ft::vector<T>::reverse_iterator::operator++()
{
    _idx -= 1;
}

template<typename T>
void    ft::vector<T>::reverse_iterator::operator--(int)
{
    _idx += 1;
}

template<typename T>
void    ft::vector<T>::reverse_iterator::operator--()
{
    _idx += 1;
}

template<typename T>
T       &ft::vector<T>::reverse_iterator::operator*()
{
    return (*_arg)[_idx];
}

template<typename T>
bool    ft::vector<T>::reverse_iterator::operator!=(const ft::vector<T>::reverse_iterator &rhs)
{
    if (this->_idx != rhs._idx)
        return true;
    return false;
}

template<typename T>
typename ft::vector<T>::reverse_iterator    ft::vector<T>::rbegin()
{
    ft::vector<T>::reverse_iterator it(this, this->size() - 1);
    return it;
}

template<typename T>
typename ft::vector<T>::reverse_iterator    ft::vector<T>::rend()
{
    ft::vector<T>::reverse_iterator it(this, -1);
    return it;
}


template<typename T>
size_t      ft::vector<T>::reverse_iterator::getIdx()
{
    return _idx;
}
