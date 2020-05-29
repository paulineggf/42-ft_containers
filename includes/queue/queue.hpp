#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <iostream>
# include "../list/list.hpp"

namespace ft
{
    template <class T, class Container = ft::list<T> >
    class   queue
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
        
        explicit queue (const container_type& ctnr = container_type());
        value_type&         back();
        const value_type&   back() const;
        bool                empty() const;
        value_type&         front();
        const value_type&   front() const;
        void                pop();
        void                push(const value_type& val);
        size_type           size()const;

               // NON-MEMBER OVERLOADS

        friend
        bool operator==(const ft::queue<T,Container> &lhs, const ft::queue<T,Container> &rhs)
        {
            return lhs._container == rhs._container;
        }

        friend
        bool operator!=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
        {
            return lhs._container != rhs._container;
        }

        friend
        bool operator<(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
        {
            return lhs._container < rhs._container;
        }

        friend
        bool operator<=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
        {
            return lhs._container <= rhs._container;
        }

        friend
        bool operator>(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
        {
            return lhs._container > rhs._container;

        }

        friend
        bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
        {
            return lhs._container >= rhs._container;
        }
    };

    # include "queueMemberFunctions.hpp"
}

#endif
