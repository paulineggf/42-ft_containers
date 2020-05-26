#include "stack.hpp"

template<class T, class Container>
ft::stack<T, Container>::stack(const container_type &ctnr) :
_container(ctnr) {}

template<class T, class Container>
typename ft::stack<T, Container>::size_type ft::stack<T, Container>::size() const
{
    return _container.size();
}

template<class T, class Container>
void        ft::stack<T, Container>::pop()
{
    _container.pop_back();
}

template<class T, class Container>
void        ft::stack<T, Container>::push(const value_type &val)
{
    _container.push_back(val);
}

template<class T, class Container>
typename ft::stack<T, Container>::value_type          &ft::stack<T, Container>::top()
{
    return _container.back();
}

template<class T, class Container>
const typename ft::stack<T, Container>::value_type    &ft::stack<T, Container>::top() const
{
    return _container.back();
}

template<class T, class Container>
bool        ft::stack<T, Container>::empty() const
{
    return _container.empty();
}
