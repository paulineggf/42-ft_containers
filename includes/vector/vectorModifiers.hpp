#include "vector.hpp"


template<typename T, class Alloc>
void            ft::vector<T, Alloc>::push_back(typename ft::vector<T, Alloc>::value_type arg)
{
    if (_size < _capacity)
        _arg[_size] = arg;
    else
    {
        T *newArg;
        if (_capacity == 0)
            newArg = _alloc.allocate(1);
        else
            newArg = _alloc.allocate(_capacity * 2);
        
        for (size_type i = 0; i < _size; i++)
            _alloc.construct(newArg + i, _arg[i]);
        _alloc.construct(newArg + _size, arg);
        if (_size > 0)
            _alloc.deallocate(_arg, _capacity);
        _arg = newArg;
        if (_capacity == 0)
            _capacity += 1;
        else
            _capacity *= 2;
    }
    _size++;
}

template<typename T, class Alloc>
void                        ft::vector<T, Alloc>::pop_back()
{
    _size -= 1;
}

template<typename T, class Alloc>
void                        ft::vector<T, Alloc>::clear()
{
    _size = 0;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator     ft::vector<T, Alloc>::erase(typename ft::vector<T, Alloc>::iterator pos)
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

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator    ft::vector<T, Alloc>::erase(ft::vector<T, Alloc>::iterator first,
                                    ft::vector<T, Alloc>::iterator last)
{
    size_type     end;

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

template<typename T, class Alloc>
template<class InputIterator>
void        ft::vector<T, Alloc>::assign(InputIterator first, InputIterator last)
{
    size_type sz = 1;

    this->assign(sz, *first);
    first++;
    while (first != last)
    {
        this->push_back(*first);
        first++;
    }
}

template<typename T, class Alloc>
void        ft::vector<T, Alloc>::assign(typename ft::vector<T, Alloc>::size_type n, const T &val)
{
    if (n > _capacity)
        this->reserve(n);
    for (size_type i = 0; i < n; i++)
        _arg[i] = val;
    _size = n;
}

template<typename T, class Alloc>
void        ft::vector<T, Alloc>::assign(int n, int val)
{
    if (n > (int)_capacity)
        this->reserve(n);
    for (int i = 0; i < n; i++)
        _arg[i] = val;
    _size = n;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator    ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position,
                                    const T &val)
{
    size_type     i;
    int           tmp;
    
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

template<typename T, class Alloc>
void        ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position,
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

template<typename T, class Alloc>
void        ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position,
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

template<typename T, class Alloc>
template <class InputIterator>
void        ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position,
            InputIterator first, InputIterator last)
{
    ft::vector<T, Alloc>   myvector;
    size_type       i;

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

template<typename T, class Alloc>
void        ft::vector<T, Alloc>::swap(ft::vector<T, Alloc> &x)
{
    ft::vector<T, Alloc> tmp;

    tmp.assign(this->begin(), this->end());
    this->assign(x.begin(), x.end());
    x.assign(tmp.begin(), tmp.end());
}