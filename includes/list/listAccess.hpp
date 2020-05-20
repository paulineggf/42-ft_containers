#include "list.hpp"

template<typename T, class Alloc>
typename ft::list<T, Alloc>::reference              ft::list<T, Alloc>::back()
{
    ft::list<T, Alloc>::iterator it = this->begin();

    while (it._M_node->_M_next)
        it++;
    return (*it);
}

template<typename T, class Alloc>
typename ft::list<T, Alloc>::const_reference        ft::list<T, Alloc>::back() const
{
    ft::list<T, Alloc>::iterator it = this->begin();
    
    while (it._M_node->_M_next)
        it++;
    return (*it);
}

template<typename T, class Alloc>
typename ft::list<T, Alloc>::reference              ft::list<T, Alloc>::front()
{
    ft::list<T, Alloc>::iterator it = this->begin();
    return (*it);
}

template<typename T, class Alloc>
typename ft::list<T, Alloc>::const_reference        ft::list<T, Alloc>::front() const
{
    ft::list<T, Alloc>::iterator it = this->begin();
    return (*it);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::Node      *ft::list<T, Alloc>::lastList(Node *list)
{
    if (!list)
        return (NULL);
    while (list->_M_next)
        list = list->_M_next;
    return (list);
}

template<class T, class Alloc>
typename ft::list<T, Alloc>::Node     *ft::list<T, Alloc>::listAt(Node *list, int nb)
{
    for (int i = 0; i < nb; i++)
        list = list->_M_next;
    return list;
}
