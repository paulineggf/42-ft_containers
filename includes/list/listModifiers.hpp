#include "list.hpp"

template<class T, class Alloc>
void        ft::list<T, Alloc>::push_back(const value_type &val)
{
    if (!_list)
        _list = new Node(val);
    else
    {
        Node *tmp = lastList(_list);
        tmp->_M_next = new Node(val, tmp);
    }
    _size++;
}

template<class T, class Alloc>
void        ft::list<T, Alloc>::push_front(const value_type &val)
{
    Node  *list;

    list = new Node(val, NULL, _list);
    _list = list;
    _size++;
}

template<class T, class Alloc>
void        ft::list<T, Alloc>::pop_back()
{
    if (!_list)
        return ;
    else
    {
        ft::list<T, Alloc>::iterator it = this->begin();
            
        while (it._M_node->_M_next && it._M_node->_M_next->_M_next)
            it++;
        delete lastList(_list);
        if (it._M_node->_M_next == NULL)
            it._M_node = NULL;
        else
            it._M_node->_M_next = NULL;
        _size--;
    }
}

template<class T, class Alloc>
void        ft::list<T, Alloc>::pop_front()
{
    if (!_list)
        return ;
    else
    {
        Node *tmp = _list;
        _list = _list->_M_next;
        delete tmp;
        tmp = NULL;
        _size--;
    }
}

template<class T, class Alloc>
template<class InputIterator>
void        ft::list<T, Alloc>::assign(InputIterator first, InputIterator last)
{
    this->clear();
    while (first != last)
    {
        this->push_back(*first);
        first++;
    }
}

template<typename T, class Alloc>
void        ft::list<T, Alloc>::assign(size_type n, const value_type &val)
{
    this->clear();
    for (size_type i = 0; i < n; i++)
        this->push_back(val);
}

template<typename T, class Alloc>
void        ft::list<T, Alloc>::assign(int n, int val)
{
    this->clear();
    for (int i = 0; i < n; i++)
        this->push_back(val);
}

template<typename T, class Alloc>
void        ft::list<T, Alloc>::clear()
{
    Node *tmp;

    if (!_list)
        return ;
    while (_list)
    {
        tmp = _list;
        delete _list;
        _list = tmp->_M_next;
    }
    _size = 0;
}

template<typename T, class Alloc>
typename ft::list<T, Alloc>::iterator     ft::list<T, Alloc>::insert(ft::list<T, Alloc>::iterator position,
                                            const T &val)
{
    Node  *list;

    list = new Node(val, position._M_node->_M_prev, position._M_node);
    position._M_node->_M_prev->_M_next = list;
    position._M_node->_M_prev = list;
    _size++;
    position--;
    return position;
}

template<typename T, class Alloc>
void        ft::list<T, Alloc>::insert(ft::list<T, Alloc>::iterator position,
            size_type n, const T& val)
{
    Node  *list;

    for (size_type i = 0; i < n; i++)
    {
        list = new Node(val, position._M_node->_M_prev, position._M_node);
        if (position._M_node->_M_prev)
            position._M_node->_M_prev->_M_next = list;
        else
            _list = list;
        position._M_node->_M_prev = list;
        position--;
        _size++;
    }
}

template<typename T, class Alloc>
void        ft::list<T, Alloc>::insert(ft::list<T, Alloc>::iterator position,
            int n, int val)
{
    Node  *list;

    for (int i = 0; i < n; i++)
    {
        list = new Node(val, position._M_node->_M_prev, position._M_node);
        if (position._M_node->_M_prev)
            position._M_node->_M_prev->_M_next = list;
        else
            _list = list;
        position._M_node->_M_prev = list;
        position--;
        _size++;
    }
}

template<typename T, class Alloc>
template <class InputIterator>
void            ft::list<T, Alloc>::insert(ft::list<T, Alloc>::iterator position, InputIterator first, InputIterator last)
{
    Node    *list;

    for (; first != last; first++)
    {
        list = new Node(*first, position._M_node->_M_prev, position._M_node);
        if (position._M_node->_M_prev)
            position._M_node->_M_prev->_M_next = list;
        else
            _list = list;
        position._M_node->_M_prev = list;
        position._M_node = list->_M_next;
        _size++;
    }
}

template<typename T, class Alloc>
void            ft::list<T, Alloc>::resize(size_type n, value_type val)
{
    while (n > _size)
        this->push_back(val);
    while (n < _size)
        this->erase(lastList(_list));
}

template<typename T, class Alloc>
typename ft::list<T, Alloc>::iterator       ft::list<T, Alloc>::erase(ft::list<T, Alloc>::iterator position)
{
    ft::list<T, Alloc>::iterator it(position._M_node->_M_next);

    if (position._M_node->_M_prev)
        position._M_node->_M_prev->_M_next = position._M_node->_M_next;
    else
        _list = it._M_node;
    if (position._M_node->_M_next)
    position._M_node->_M_next->_M_prev = position._M_node->_M_prev;
    delete position._M_node;
    _size--;
    return it;
}

template<typename T, class Alloc>
typename ft::list<T, Alloc>::iterator       ft::list<T, Alloc>::erase(ft::list<T, Alloc>::iterator first, ft::list<T, Alloc>::iterator last)
{
    ft::list<T, Alloc>::iterator it;

    while (first != last)
    {
        it._M_node = first._M_node->_M_next;
        if (first._M_node->_M_prev)
            first._M_node->_M_prev->_M_next = first._M_node->_M_next;
        else
            _list = it._M_node;
        if (first._M_node->_M_next)
            first._M_node->_M_next->_M_prev = first._M_node->_M_prev;
        delete first._M_node;
        first._M_node = it._M_node;
        _size--;
    }
    return it;
}

template<typename T, class Alloc>
void            ft::list<T, Alloc>::swap(ft::list<T, Alloc> &x)
{
    ft::list<T, Alloc> tmp;

    tmp.assign(this->begin(), this->end());
    this->assign(x.begin(), x.end());
    x.assign(tmp.begin(), tmp.end());
}
