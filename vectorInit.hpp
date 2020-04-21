#include "vector.hpp"

template<typename T>
ft::vector<T>::vector() :
_capacity(0),
_size(0),
_arg(nullptr) {}

template<typename T>
ft::vector<T>::vector(int capacity) :
_capacity(capacity),
_size(capacity),
_arg(new T[capacity])
{
    for (int i = 0; i < _capacity; i++)
        _arg[i] = 0;
}
    
template<typename T>
ft::vector<T>::vector(int capacity, T arg) :
_capacity(capacity),
_size(capacity),
_arg(new T[capacity])
{ 
    for (int i = 0; i < _capacity; i++)
        _arg[i] = arg;
}

template<typename T>
ft::vector<T>::vector(const ft::vector<T> &copy)
{
    *this = copy;
}
    
template<typename T>
ft::vector<T>::~vector()
{
    delete [] _arg;
}