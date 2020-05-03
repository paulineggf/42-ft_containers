#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <iostream>
# include <exception>
# include <algorithm>

namespace ft
{
    template <typename T, class Alloc = std::allocator<T> >
    class   vector
    {
        public:

        // TYPEDEF
        
        typedef T                           value_type;
        typedef T*                          pointer;
        typedef std::size_t                 size_type;
        typedef value_type&                 reference;
        typedef const value_type&           const_reference;
        typedef Alloc                       allocator_type;
        typedef std::ptrdiff_t              difference_type;

        private:

        // ARGUMENTS

        allocator_type          _alloc;
        pointer                 _arg;
        size_type               _capacity;
        size_type               _size;

        public:

        // ITERATORS

        class       iterator
        {
            private:
            vector<T>   *_arg;
            size_type   _idx;

            public:

            iterator();
            iterator(vector<T, Alloc> *arg, int idx);
            ~iterator();

            iterator        operator+(int nb);
            iterator        operator-(int nb);
            iterator        operator++();
            iterator        operator++(int);
            iterator        operator--();
            iterator        operator--(int);
            reference       operator*();
            bool            operator!=(const iterator &rhs); // à revoir
            void            operator=(vector<T, Alloc> *rhs);
            bool            operator<(const iterator &rhs);
            bool            operator>(const iterator &rhs);
            bool            operator<=(const iterator &rhs);
            bool            operator>=(const iterator &rhs);
            bool            operator==(const iterator &rhs);


            size_type       getIdx();
        };

        class       reverse_iterator
        {
            private:
            vector<T>   *_arg;
            int         _idx;


            public:
            reverse_iterator();
            reverse_iterator(vector<T, Alloc> *arg, int idx);
            ~reverse_iterator();

            reverse_iterator        operator+(int nb);
            reverse_iterator        operator-(int nb);
            void                    operator++();
            void                    operator++(int);
            void                    operator--();
            void                    operator--(int);
            T                       &operator*();
            bool                    operator!=(const reverse_iterator &rhs); // à revoir
            void                    operator=(vector<T, Alloc> *rhs);
            bool                    operator<(const reverse_iterator &rhs);
            bool                    operator>(const reverse_iterator &rhs);
            bool                    operator<=(const reverse_iterator &rhs);
            bool                    operator>=(const reverse_iterator &rhs);
            // bool                    operator==(const reverse_iterator &rhs);
        
            size_type               getIdx();
        };

        class       const_iterator
        {
            private:
            const vector<T>     *_arg;
            size_type           _idx;

            public:
            const_iterator();
            const_iterator(const vector<T, Alloc>  *arg, int idx);
            ~const_iterator();

            const_iterator        operator+(int nb);
            const_iterator        operator-(int nb);
            void                  operator++();
            void                  operator++(int);
            void                  operator--();
            void                  operator--(int);
            value_type            operator*();
            bool                  operator!=(const const_iterator &rhs); // à revoir
            void                  operator=(vector<T, Alloc> *rhs);
            bool                  operator<(const const_iterator &rhs);
            bool                  operator>(const const_iterator &rhs);
            bool                  operator<=(const const_iterator &rhs);
            bool                  operator>=(const const_iterator &rhs);
            // bool                  operator==(const const_iterator &rhs);

            size_type       getIdx();
        };

        class       const_reverse_iterator
        {
            private:
            vector<T>   *_arg;
            int         _idx;


            public:
            const_reverse_iterator();
            const_reverse_iterator(vector<T, Alloc> *arg, int idx);
            ~const_reverse_iterator();

            const_reverse_iterator          operator+(int nb);
            const_reverse_iterator          operator-(int nb);
            void                            operator++();
            void                            operator++(int);
            void                            operator--();
            void                            operator--(int);
            T                               &operator*();
            bool                            operator!=(const const_reverse_iterator &rhs); // à revoir
            void                            operator=(vector<T, Alloc> *rhs);
            bool                            operator<(const const_reverse_iterator &rhs);
            bool                            operator>(const const_reverse_iterator &rhs);
            bool                            operator<=(const const_reverse_iterator &rhs);
            bool                            operator>=(const const_reverse_iterator &rhs);
            // bool                    operator==(const const_reverse_iterator &rhs);
        
            size_type               getIdx();
        };

        iterator                  begin();
        const_iterator            begin() const;
        iterator                  end();
        const_iterator            end() const;
        reverse_iterator          rbegin();
        const_reverse_iterator    rbegin() const;
        reverse_iterator          rend();
        const_reverse_iterator    rend() const;
        
        // INITIALISATIONS

        explicit vector(const allocator_type& alloc = allocator_type());
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type());        
        template<typename InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
        vector(const vector<T, Alloc> &copy);            
        ~vector();

        // OPERATORS OVERLOAD

        vector              &operator=(const vector &rhs);
        reference           operator[](size_type idx);
        const_reference     operator[](size_type idx) const;

        // // CAPACITY

        size_type           capacity() const;
        size_type           size() const;
        size_type           max_size();
        void                resize(size_type n, value_type val = value_type());
        bool                empty() const;
        void                reserve(size_type n);

        // // ELEMENT ACCESS

        reference           back();
        const_reference     back() const;
        reference           front();
        const_reference     front() const;
        reference           at(size_type n);
        const_reference     at(size_type n) const;
        
        // // MODIFIERS

        template<class InputIterator>
        void                assign(InputIterator first, InputIterator last);
        void                assign(size_type n, const T &val);
        void                assign(int n, int val);
        void                push_back(const value_type &arg);
        void                pop_back();
        iterator            insert(iterator position, const value_type& val);
        void                insert(iterator position, size_t n, const value_type& val);
        void                insert(iterator position, int n, int val);
        template <class InputIterator>
        void                insert(iterator position,
                            InputIterator first, InputIterator last);
        iterator            erase(iterator pos);
        iterator            erase(iterator first, iterator last);
        void                swap(vector<T, Alloc> &x);
        void                clear();

        void                swap(vector<T,Alloc>& x, vector<T,Alloc>& y);
    };

        # include "vectorIterators.hpp"
        # include "vectorReverseIterators.hpp"
        # include "vectorConstIterator.hpp"
        # include "vectorInit.hpp"
        # include "vectorOperators.hpp"
        # include "vectorCapacity.hpp"
        # include "vectorAccess.hpp"
        # include "vectorModifiers.hpp"
        # include "vectorRelationOperators.hpp"
}


#endif