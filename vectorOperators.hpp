#include "vector.hpp"

template<typename T>
ft::vector<T>   &ft::vector<T>::operator=(const ft::vector<T> &rhs)
{
    _arg = rhs._arg;
    return *this;
}

template<typename T>
T               &ft::vector<T>::operator[](int idx)
{
    return _arg[idx];
}
