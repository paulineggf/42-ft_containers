#include "queue.hpp"


template<class T, class Container>
ft::queue<T, Container>::queue(const container_type &ctnr) :
_container(ctnr) {}

template<class T, class Container>
typename ft::queue<T, Container>::size_type ft::queue<T, Container>::size() const
{
    return _container.size();
}

template<class T, class Container>
void        ft::queue<T, Container>::pop()
{
    _container.pop_front();
}

template<class T, class Container>
void        ft::queue<T, Container>::push(const value_type &val)
{
    _container.push_back(val);
}

template<class T, class Container>
typename ft::queue<T, Container>::value_type          &ft::queue<T, Container>::front()
{
    return _container.front();
}

template<class T, class Container>
const typename ft::queue<T, Container>::value_type    &ft::queue<T, Container>::front() const
{
    return _container.front();
}

template<class T, class Container>
typename ft::queue<T, Container>::value_type          &ft::queue<T, Container>::back()
{
    return _container.back();
}

template<class T, class Container>
const typename ft::queue<T, Container>::value_type    &ft::queue<T, Container>::back() const
{
    return _container.back();
}

template<class T, class Container>
bool        ft::queue<T, Container>::empty() const
{
    return _container.empty();
}
