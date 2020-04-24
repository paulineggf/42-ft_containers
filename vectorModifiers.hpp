#include "vector.hpp"


template<typename T>
void                            ft::vector<T>::push_back(T arg)
{
    if (_size < _capacity)
    {
        _arg[_size] = arg;
        _size++;
    }
    else
    {
        T *newArg;
        if (_capacity == 0)
            newArg = new T[1];
        else
            newArg = new T[_capacity * 2];
        if (newArg == nullptr)
            throw std::exception();
        for (int i = 0; i < _size; i++)
            newArg[i] = _arg[i];
        newArg[_size] = arg;
        delete [] _arg;
        _arg = newArg;
        if (_capacity == 0)
            _capacity += 1;
        else
            _capacity *= 2;
        _size++;
    }
}

template<typename T>
void                        ft::vector<T>::pop_back()
{
    _size -= 1;
}

template<typename T>
void                        ft::vector<T>::clear()
{
    _size = 0;
}

template<typename T>
typename ft::vector<T>::iterator     ft::vector<T>::erase(ft::vector<T>::iterator pos)
{
    int i;

    i = 0;
    while (pos.getIdx() < _size)
    {
        pos++;
        _arg[pos.getIdx() - 1] = *pos;
        i++;
    }
    _size -= 1;
    pos = this;
    return pos;
}

template<typename T>
typename ft::vector<T>::iterator    ft::vector<T>::erase(ft::vector<T>::iterator first,
                                    ft::vector<T>::iterator last)
{
    int     end;

    end = _size;
    _size -= last.getIdx() - first.getIdx();
    while (last.getIdx() < end)
    {
        _arg[first.getIdx()] = *last;
        last++;
        first++;
    }
    first = this;
    return first;
}

template<typename T>
template<class InputIterator>
void        ft::vector<T>::assign(InputIterator first, InputIterator last)
{
    while (first != last)
    {
        this->push_back(*first);
        first++;
    }
}

template<typename T>
void        ft::vector<T>::assign(size_t n, const T &val)
{
    if (n > _capacity)
        this->reserve(n);
    for (int i = 0; i < n; i++)
        _arg[i] = val;
    _size = n;
}

template<typename T>
void        ft::vector<T>::assign(int n, int val)
{
    if (n > _capacity)
        this->reserve(n);
    for (int i = 0; i < n; i++)
        _arg[i] = val;
    _size = n;
}

template<typename T>
ft::vector<T>::iterator     ft::vector<T>::insert(ft::vector<T>::iterator position,
                            const T& val)
{
    
}

template<typename T>
void                        ft::vector<T>::insert(ft::vector<T>::iterator position,
                            size_t n, const T& val)
{
    
}

template<typename T>
template <class InputIterator>
void                        ft::vector<T>::insert(ft::vector<T>::iterator position,
                            InputIterator first, InputIterator last)
{

}