#include "map.hpp"

template<class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) :
_comp(comp),
_alloc(alloc),
_data() {}

template<class Key, class T, class Compare, class Alloc>
template <class InputIterator>
ft::map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last,
            const key_compare& comp, const allocator_type& alloc) :
_comp(comp),
_alloc(alloc),
_data(first, last) {
}

template<class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const map &x) :
_data(x.begin(), x.end())
{
    _comp = x._comp;
    _alloc = x._alloc;
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>    &ft::map<Key, T, Compare, Alloc>::operator=(const map &x)
{
    _comp = x._comp;
    _alloc = x._alloc;
    _data.assign(x.begin(), x.end());
    return *this;
}
