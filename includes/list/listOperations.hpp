#include "list.hpp"

template<class T, class Alloc>
void            ft::list<T, Alloc>::splice(iterator position, list &x)
{
    this->insert(position, x.begin(), x.end());
    x.erase(x.begin(), x.end());
}

template<class T, class Alloc>
void            ft::list<T, Alloc>::splice(iterator position, list &x, iterator i)
{
    this->insert(position, 1, i._M_node->_data);
    x.erase(i);
}

template<class T, class Alloc>
void            ft::list<T, Alloc>::splice(iterator position, list &x, iterator first, iterator last)
{
    this->insert(position, first, last);
    x.erase(first, last);
}

template<class T, class Alloc>
void            ft::list<T, Alloc>::remove(const value_type &val)
{
    ft::list<T, Alloc>::iterator it(_list);

    for (; it != this->end(); it++)
    {
        if (*it == val)
        {
            _alloc.destroy(&(it._M_node->_data));
            this->erase(it);
        }
    }
}


template<typename T, class Alloc>
template<class Predicate>
void            ft::list<T, Alloc>::remove_if(Predicate pred)
{
    ft::list<T, Alloc>::iterator it(_list);

    for (; it != this->end(); it++)
    {
        if (pred(*it) == true)
        {
            _alloc.destroy(&(it._M_node->_data));
            this->erase(it);
        }
    }
}

template<typename T, class Alloc>
void            ft::list<T, Alloc>::sort()
{
    Node *tmp1 = NULL;
    Node *tmp2 = NULL;
    int j;

    for (size_type i = 1; i < _size; i++)
    {
        tmp2 = listAt(_list, i);
        j = i;
        while (j > 0 && (listAt(_list, j - 1))->_data > tmp2->_data)
        {
            tmp1 = listAt(_list, j - 1);
            if (tmp1->_M_prev)
                tmp1->_M_prev->_M_next = tmp2;
            if (tmp2->_M_next)
                tmp2->_M_next->_M_prev = tmp1;
            tmp1->_M_next = tmp2->_M_next;
            tmp2->_M_prev = tmp1->_M_prev;
            tmp1->_M_prev = tmp2;
            tmp2->_M_next = tmp1;
            if (tmp1->_M_prev == NULL)
                _list = tmp1;
            else if (tmp2->_M_prev == NULL)
                _list = tmp2;
            j--;
        }
    }
}

template<typename T, class Alloc>
template<class Compare>
void            ft::list<T, Alloc>::sort(Compare comp)
{
    Node *tmp1 = NULL;
    Node *tmp2 = NULL;
    int j;

    for (size_type i = 1; i < _size; i++)
    {
        tmp2 = listAt(_list, i);
        j = i;
        while (j > 0 && comp(tmp2->_data, (listAt(_list, j - 1))->_data))
        {
            tmp1 = listAt(_list, j - 1);
            if (tmp1->_M_prev)
                tmp1->_M_prev->_M_next = tmp2;
            if (tmp2->_M_next)
                tmp2->_M_next->_M_prev = tmp1;
            tmp1->_M_next = tmp2->_M_next;
            tmp2->_M_prev = tmp1->_M_prev;
            tmp1->_M_prev = tmp2;
            tmp2->_M_next = tmp1;
            if (tmp1->_M_prev == NULL)
                _list = tmp1;
            else if (tmp2->_M_prev == NULL)
                _list = tmp2;
            j--;
        }
    }
}


template<typename T, class Alloc>
void            ft::list<T, Alloc>::unique()
{
    Node *tmp2 = NULL;
    int j;

    for (size_type i = 1; i < _size; i++)
    {
        tmp2 = listAt(_list, i);
        j = i;
        while (j > 0 && (listAt(_list, j - 1))->_data == tmp2->_data)
        {
            this->erase(iterator(listAt(_list, j - 1)));
            j--;
        }
    }
}


template<typename T, class Alloc>
template<class BinaryPredicate>
void            ft::list<T, Alloc>::unique(BinaryPredicate binary_pred)
{
    Node *tmp2 = NULL;
    int j;

    for (size_type i = 1; i <= _size; i++)
    {
        tmp2 = listAt(_list, i);
        j = i;
        while (j > 0 && binary_pred((listAt(_list, j - 1))->_data, tmp2->_data))
        {
            this->erase(iterator(tmp2));
            j--;
        }
    }
}

template<typename T, class Alloc>
void            ft::list<T, Alloc>::merge(ft::list<T, Alloc> &x)
{
    ft::list<T, Alloc>::iterator it(this->begin());
    ft::list<T, Alloc>::iterator itX(x.begin());
    Node *tmp;

    while (it != this->end() && tmp)
    {
        if (*it >= *itX)
        {
            tmp = itX._M_node->_M_next;
            if (it._M_node->_M_prev)
                it._M_node->_M_prev->_M_next = itX._M_node;
            else
                _list = itX._M_node;
            it._M_node->_M_prev = itX._M_node;
            itX._M_node->_M_next = it._M_node;
            _size++;            
            itX._M_node = tmp;
        }
        else
            it++;
    }
    x._list = NULL;
}

template<class T, class Alloc>
template<class Compare>
void            ft::list<T, Alloc>::merge(ft::list<T, Alloc> &x, Compare comp)
{
    ft::list<T, Alloc>::iterator it(this->begin());
    ft::list<T, Alloc>::iterator itX(x.begin());
    Node *tmp;

    while (it != this->end() && tmp)
    {
        if (comp(*itX, *it))
        {
            tmp = itX._M_node->_M_next;
            if (it._M_node->_M_prev)
                it._M_node->_M_prev->_M_next = itX._M_node;
            else
                _list = itX._M_node;
            it._M_node->_M_prev = itX._M_node;
            itX._M_node->_M_next = it._M_node;
            _size++;            
            itX._M_node = tmp;
        }
        else
            it++;
    }
}

template<class T, class Alloc>
void        ft::list<T, Alloc>::reverse()
{
    ft::list<T, Alloc>::iterator it(lastList(_list));
    Node *begin_list = lastList(_list);
    Node *tmp = begin_list;
    Node *tmp2;

    it--;
    _list = begin_list;
    begin_list->_M_prev = NULL;
    while (it._M_node)
    {
        tmp2 = it._M_node->_M_prev;
        tmp->_M_next = it._M_node;
        it._M_node->_M_prev = tmp;
        tmp = tmp->_M_next;
        it._M_node->_M_next = NULL;
        it._M_node = tmp2;
    }
}
