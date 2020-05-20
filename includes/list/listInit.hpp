#include "list.hpp"

template<class T, class Alloc>
ft::list<T, Alloc>::list(const allocator_type& alloc) :
_alloc(alloc),
_list(0),
_size(0) {}

template<class T, class Alloc>
ft::list<T, Alloc>::list(size_type n, const value_type &val, const allocator_type &alloc) :
_alloc(alloc),
_list(0),
_size(n)
{
    for (size_type i = 0; i < n; i++)
        this->push_back(val);
}

template<class T, class Alloc>
template <class InputIterator>
ft::list<T, Alloc>::list(InputIterator first, InputIterator last,
            const allocator_type& alloc) :
_alloc(alloc),
_list(0),
_size(0)
{
    this->assign(first, last);
}

template<class T, class Alloc>
ft::list<T, Alloc>::list(const list &copy)
{
    _alloc = copy._alloc;
    _size = 0;
    _list = 0;
    this->assign(copy.begin(), copy.end());
}

template<class T, class Alloc>
ft::list<T, Alloc>::~list() {
    this->clear();
}

template<class T, class Alloc>
typename ft::list<T, Alloc>  &ft::list<T, Alloc>::operator=(const ft::list<T, Alloc> &x)
{
    _alloc = x._alloc;
    this->assign(x.begin(), x.end());
    return *this;
}
