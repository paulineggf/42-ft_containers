#include "vector.hpp"

template <typename T, class Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc) :
_alloc(alloc),
_arg(0),
_capacity(0),
_size(0) { 
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type& alloc) :
_alloc(alloc),
_arg(0),
_capacity(n),
_size(n)
{
    _arg = _alloc.allocate(_size);
    for (size_type i = 0; i < _size; i++)
        _arg[i] = val;
}

template<typename T, class Alloc>
template<typename InputIterator>
ft::vector<T, Alloc>::vector(InputIterator first, InputIterator last,
                      const allocator_type& alloc) :
_alloc(alloc),
_arg(0),
_capacity(0),
_size(0)
{
    this->assign(first, last);
}

template<typename T, class Alloc>
ft::vector<T, Alloc>::vector(const ft::vector<T, Alloc> &copy)
{
    this->_size = 0;
    this->_capacity = 0;
    this->_alloc = _alloc;
    for (size_type i = 0; i < copy._size; i++)
        this->push_back(copy.at(i));
}
    
template<typename T, class Alloc>
ft::vector<T, Alloc>::~vector()
{
    for (size_type i = 0; i < _size; i++)
        _alloc.destroy(_arg + i);
    _alloc.deallocate(_arg, _capacity);
}