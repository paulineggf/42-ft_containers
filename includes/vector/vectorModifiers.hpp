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
        if (newArg == 0)
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
    this->assign(1, *first),
    first++;
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
typename ft::vector<T>::iterator    ft::vector<T>::insert(ft::vector<T>::iterator position,
                                    const T &val)
{
    int     i;
    int     tmp;
    
    i = _size;
    tmp = _size - 1;
    if (_capacity < _size + 1)
        this->reserve(_size + 1);
    while (i > position.getIdx())
        *(position + i--) = *(position + tmp--);
    _size += 1;
    *(position + i) = val;
    return position;
}

template<typename T>
void        ft::vector<T>::insert(ft::vector<T>::iterator position,
            size_t n, const T& val)
{
    int     i;
    int     tmp;
    
    i = _size + n - 1;
    tmp = _size - 1;
    if (_capacity < _size + n)
        this->reserve(_size + n);
    while (i > position.getIdx() + n - 1)
        *(position + i--) = *(position + tmp--);
    _size += n;
    while (n > 0)
    {      
        *(position + i--) = val;
        n--;
    }
}

template<typename T>
void        ft::vector<T>::insert(ft::vector<T>::iterator position,
            int n, int val)
{
    int     i;
    int     tmp;
    
    i = _size + n - 1;
    tmp = _size - 1;
    if (_capacity < _size + n)
        this->reserve(_size + n);
    while (i > (int)position.getIdx() + n - 1)
        *(position + i--) = *(position + tmp--);
    _size += n;
    while (n > 0)
    {      
        *(position + i--) = val;
        n--;
    }
}

template<typename T>
template <class InputIterator>
void        ft::vector<T>::insert(ft::vector<T>::iterator position,
            InputIterator first, InputIterator last)
{
    ft::vector<T>   myvector;
    int             i;

    myvector.assign(position, position + _size);
    this->erase(position, position + _size);
    while (first != last)
    {
        this->push_back(*first);
        first++;
    }
    i= 0;
    while (i < myvector._size)
        this->push_back(myvector[i++]);
}

template<typename T>
void        ft::vector<T>::swap(ft::vector<T> &x)
{
    ft::vector<T> tmp;

    tmp.assign(this->begin(), this->end());
    this->assign(x.begin(), x.end());
    x.assign(tmp.begin(), tmp.end());
}