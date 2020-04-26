#include "vector.hpp"

template<typename T>
T                   &ft::vector<T>::back()
{
    return _arg[_size - 1];
}

template<typename T>
T                   &ft::vector<T>::front()
{
    return _arg[0];
}

template<typename T>
T                   &ft::vector<T>::at(int i)
{
    return _arg[i];
}