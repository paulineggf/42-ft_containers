#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <deque>

namespace ft
{
    template <class T, class Container = std::deque<T> >
    class   stack
    {
        public:

        // TYPEDEF

        typedef T               value_type;
        typedef Container       container_type;
        typedef std::size_t     size_type;

        private:

        // ARGUMENTS

        container_type _container;
        
        public:

        // MEMBER FUNCTIONS

        explicit stack(const container_type &ctnr = container_type());
        size_type           size() const;
        void                pop();
        void                push(const value_type &val);
        value_type          &top();
        const value_type    &top() const;
        bool                empty() const;

        // NON-MEMBER OVERLOADS

        friend
        bool operator==(const ft::stack<T,Container> &lhs, const ft::stack<T,Container> &rhs)
        {
            return lhs._container == rhs._container;
        }

        friend
        bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return lhs._container != rhs._container;
        }

        friend
        bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return lhs._container < rhs._container;
        }

        friend
        bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return lhs._container <= rhs._container;
        }

        friend
        bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return lhs._container > rhs._container;

        }

        friend
        bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return lhs._container >= rhs._container;
        }
    };

    # include "stackMemberFunctions.hpp"
}

#endif
