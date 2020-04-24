#include "vector.hpp"


    
template<typename T>
int                             ft::vector<T>::capacity()
{
    return _capacity;
}

template<typename T>
size_t                             ft::vector<T>::size() const
{
    return _size;
}

template<typename T>
long int                        ft::vector<T>::max_size()
{
    return std::numeric_limits<std::size_t>::max() / sizeof(T);
}

template<typename T>
void                            ft::vector<T>::resize(int resize)
{
    if (_size > resize)
    {
        T    *newArg = new T[resize];
        for (int i = 0; i < resize; ++i)
            newArg[i] = _arg[i];
        delete [] _arg;
        _arg = newArg;
        _size = resize;
    }
    else if (_size < resize)
    {
        for (int i = _size; i < resize; ++i)
            this->push_back(0);
    }
}

template<typename T>
void                            ft::vector<T>::resize(int resize, T val)
{
    if (_size > resize)
    {
        T    *newArg = new T[resize];
        for (int i = 0; i < resize; ++i)
            newArg[i] = _arg[i];
        delete [] _arg;
        _arg = newArg;
        _size = resize;
    }
    else if (_size < resize)
    {
        for (int i = _size; i < resize; ++i)
            this->push_back(val);
    }
}

template<typename T>
bool                            ft::vector<T>::empty()
{
    if (_size == 0)
        return true;
    return false;
}

template<typename T>
void                            ft::vector<T>::reserve(size_t n)
{
    if (n > _capacity)
    {
        T    *newArg = new T[n];
        for (int i = 0; i < _size; ++i)
            newArg[i] = _arg[i];
        delete [] _arg;
        _arg = newArg;
        _capacity = n;
    }
}
