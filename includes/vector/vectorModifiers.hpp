#include "vector.hpp"


template<typename T, class Alloc>
void            ft::vector<T, Alloc>::push_back(const typename ft::vector<T, Alloc>::value_type &arg)
{
    if (_size < _capacity)
        _alloc.construct(_arg + _size, arg);
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
    for (size_type i = 0; i < _size; i++)
        _alloc.destroy(_arg + i);
    _size = 0;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator     ft::vector<T, Alloc>::erase(typename ft::vector<T, Alloc>::iterator pos)
{
    int i;

    i = 0;
    ft::vector<T, Alloc>::iterator it = pos + 1;
    for (; pos != this->end(); pos++)
        *pos = *(pos + 1);
    _alloc.destroy(_arg +_size);
    _size -= 1;
    return it;
}

template<typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator     ft::vector<T, Alloc>::erase(ft::vector<T, Alloc>::iterator first,
                                            ft::vector<T, Alloc>::iterator last)
{
    size_type     end;
    ft::vector<T, Alloc>::iterator itend;
    ft::vector<T, Alloc>::iterator ret = first;
    
    if (first != this->end())
    {
        itend = this->end();
        end = _size - 1;
        _size = 0;
        for (ft::vector<T, Alloc>::iterator begin = this->begin();
        begin != first; begin++)
            _size++;
        for (; last != itend; first++)
        {
            *first = *last;
            last++;
            _size++;
        }
        while (end > _size)
        {
            _alloc.destroy(_arg + end);
            end--;
        }
    }
    return ret;
}

template<typename T, class Alloc>
template<class InputIterator>
void        ft::vector<T, Alloc>::assign(InputIterator first, InputIterator last)
{
    this->clear();
    while (first != last)
    {
        this->push_back(*first);
        first++;
    }
}

template<typename T, class Alloc>
void        ft::vector<T, Alloc>::assign(size_type n, const value_type &val)
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
typename ft::vector<T, Alloc>::iterator     ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position,
                                            const T &val)
{
    int     i;
    ft::vector<T, Alloc> tmp(_alloc);
    ft::vector<T, Alloc>::iterator it;
    
    i = 0;
    tmp.assign(position, this->end());
    for (ft::vector<T, Alloc>::iterator it2 = tmp.begin(); it2 != tmp.end(); it2++)
        std::cout << "*it: " << it2->first << std::endl;
    this->erase(position, this->end());
    if (_capacity < _size + 1)
        this->reserve(_size + 1);
    this->push_back(val);
    it = this->end();
    it--;
    while (i < (int)tmp.size())
        this->push_back(tmp[i++]);
    return it;
}

template<typename T, class Alloc>
void        ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position,
            size_t n, const T& val)
{
    int     i;
    ft::vector<T, Alloc> tmp;
    
    i = 0;
    tmp.assign(position, this->end());
    this->erase(position, this->end());
    if (_capacity < _size + n)
        this->reserve(_size + n);
    while (i < n)
    {
        this->push_back(val);
        i++;
    }
    i= 0;
    while (i < (int)tmp.size())
        this->push_back(tmp[i++]);
}

template<typename T, class Alloc>
void        ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position,
            int n, int val)
{
    int     i;
    ft::vector<T, Alloc> tmp;
    
    i = 0;
    tmp.assign(position, this->end());
    this->erase(position, this->end());
    if (_capacity < _size + n)
        this->reserve(_size + n);
    while (i < n)
    {
        this->push_back(val);
        i++;
    }
    i= 0;
    while (i < (int)tmp.size())
        this->push_back(tmp[i++]);
}

template<typename T, class Alloc>
template <class InputIterator>
void        ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position,
            InputIterator first, InputIterator last)
{
    ft::vector<T, Alloc>    tmp;
    size_type               i;

    tmp.assign(position, this->end());
    this->erase(position, this->end());
    while (first != last)
    {
        this->push_back(*first);
        first++;
    }
    i= 0;
    while (i < tmp._size)
        this->push_back(tmp[i++]);
}

template<typename T, class Alloc>
void        ft::vector<T, Alloc>::swap(ft::vector<T, Alloc> &x)
{
    ft::vector<T, Alloc> tmp;

    tmp.assign(this->begin(), this->end());
    this->assign(x.begin(), x.end());
    x.assign(tmp.begin(), tmp.end());
}
