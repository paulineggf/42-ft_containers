#include "vector.hpp"

template<typename T>
ft::vector<T>::vector() :
_arg(0),
_capacity(0),
_size(0)
{}

template<typename T>
ft::vector<T>::vector(int capacity) :
_arg(new T[capacity]),
_capacity(capacity),
_size(capacity)
{
    for (int i = 0; i < _capacity; i++)
        _arg[i] = 0;
}
    
template<typename T>
ft::vector<T>::vector(int capacity, T arg) :
_arg(new T[capacity]),
_capacity(capacity),
_size(capacity)
{ 
    for (int i = 0; i < _capacity; i++)
        _arg[i] = arg;
}

template<typename T>
template<typename InputIterator>
ft::vector<T>::vector(InputIterator first,
                      InputIterator last) :
_arg(0),
_capacity(0),
_size(0)
{
    this->assign(first, last);
}

template<typename T>
ft::vector<T>::vector(const ft::vector<T> &copy)
{
    this->_arg = copy._arg;
    this->_size = copy._size;
    this->_capacity = copy._capacity;
}
    
template<typename T>
ft::vector<T>::~vector()
{
    delete [] _arg;
}