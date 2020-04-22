#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <iostream>
# include <exception>

namespace ft
{
    template <typename T>
    class   vector
    {
        private:

        T   *_arg;
        int _capacity;
        int _size;

        public:

        // ITERATORS

        class       iterator
        {
            private:
            vector<T>   *_arg;
            int         _idx;

            iterator() {}

            public:
            iterator(vector<T> *arg, int idx);
            ~iterator();

            iterator        operator+(int nb);
            void            operator++();
            void            operator++(int);
            void            operator--();
            void            operator--(int);
            T               &operator*();
            bool            operator!=(const iterator &rhs);
            void            operator=(vector<T> *rhs);

            size_t          getIdx();
        };

        class       reverse_iterator
        {
            private:
            vector<T>   *_arg;
            int         _idx;

            reverse_iterator() {}

            public:
            reverse_iterator(vector<T> *arg, int idx);
            ~reverse_iterator();

            void            operator++();
            void            operator++(int);
            void            operator--();
            void            operator--(int);
            T               &operator*();
            bool            operator!=(const reverse_iterator &rhs);
        
            size_t          getIdx();
        };

        iterator            begin();
        iterator            end();
        reverse_iterator    rbegin();
        reverse_iterator    rend();
        
        // INITIALISATIONS
        vector();
        vector(int capacity);
        vector(int capacity, T arg);
        vector(const vector &copy);
        ~vector();
        
        // OPERATORS OVERLOAD

        vector              &operator=(const vector &rhs);
        T                   &operator[](int idx);

        // CAPACITY

        int                 capacity();
        size_t              size() const;
        long int            max_size();
        void                resize(int resize);
        void                resize(int resize, T val);
        bool                empty();

        // ELEMENT ACCESS

        T                   &back();
        T                   &front();
        T                   &at(int i);
        
        // MODIFIERS

        void                push_back(T arg);
        void                pop_back();
        void                clear();
        iterator            erase(iterator pos);
        iterator            erase(iterator first, iterator last);

    };

    # include "vectorIterators.hpp"
    # include "vectorInit.hpp"
    # include "vectorOperators.hpp"
    # include "vectorCapacity.hpp"
    # include "vectorAccess.hpp"
    # include "vectorModifiers.hpp"
}

#endif