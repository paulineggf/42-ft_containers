#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <iostream>
# include <exception>
# include <algorithm>
# include "reverse_iterator.hpp"

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
            public:
            typedef T                   value_type;
            typedef T*                  pointer;
            typedef std::size_t         size_type;
            typedef value_type&         reference;
            typedef const value_type&   const_reference;
            typedef std::ptrdiff_t      difference_type;

            protected:
            pointer     _arg;
            size_type   _idx;

            public:

            iterator();
            iterator(pointer arg, size_type idx);
            iterator(const iterator &rhs);
            ~iterator();

            iterator        operator+(int nb);
            friend
            iterator        operator+(int nb, iterator &rhs) { return rhs + nb; }
            iterator        operator-(int nb);
            friend
            difference_type operator-(const iterator lhs, const iterator &rhs) {
                return &((lhs._arg)[lhs._idx]) - &((rhs._arg)[rhs._idx]); }
            void            operator+=(int nb);
            void            operator-=(int nb);
            iterator        operator++();
            iterator        operator++(int);
            iterator        operator--();
            iterator        operator--(int);
            reference       operator*();
            pointer         operator->();
            bool            operator!=(const iterator &rhs);
            void            operator=(const iterator &rhs);
            bool            operator<(const iterator &rhs);
            bool            operator>(const iterator &rhs);
            bool            operator<=(const iterator &rhs);
            bool            operator>=(const iterator &rhs);
            bool            operator==(const iterator &rhs);
            reference       operator[](int nb);
        };

        // REVERSE_ITERATOR

        typedef ft::reverse_iterator<iterator>
                                        reverse_iterator;

        // CONST_ITERATOR

        class       const_iterator : public iterator
        {
            public:

            typedef const_reference reference;

            const_iterator() {}
            const_iterator(pointer arg, int idx) : iterator(arg, idx) {}
            const_iterator(iterator it) : iterator(it) {}
            ~const_iterator() {}
        };

        // CONST_REVERSE_ITERATOR

        class       const_reverse_iterator : public reverse_iterator
        {
            public:
            
            typedef const_reference reference;
            typedef T*              pointer;

            const_reverse_iterator() : ft::reverse_iterator<iterator>() {}
            const_reverse_iterator(const iterator &it) : ft::reverse_iterator<iterator>(it) {}
            const_reverse_iterator(const const_iterator &cit) : ft::reverse_iterator<const_iterator>(cit) {}
            const_reverse_iterator(const reverse_iterator &rit) : ft::reverse_iterator<iterator>(rit) {}
            ~const_reverse_iterator() {}
        };

        public:

        iterator                  begin();
        iterator                  end();
        reverse_iterator          rbegin();
        reverse_iterator          rend();
        const_iterator            begin() const;
        const_iterator            end() const;
        const_reverse_iterator    rbegin() const;
        const_reverse_iterator    rend() const;
        
        // INITIALISATIONS

        explicit vector(const allocator_type& alloc = allocator_type());
        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type& alloc = allocator_type());        
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
        void                assign(size_type n, const value_type &val);
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

        friend
        void                swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
        {
            vector<T, Alloc> tmp;

            tmp.assign(x.begin(), x.end());
            x.assign(y.begin(), y.end());
            y.assign(tmp.begin(), tmp.end());
        }
    };

    # include "vectorIterators.hpp"
    # include "vectorInit.hpp"
    # include "vectorOperators.hpp"
    # include "vectorCapacity.hpp"
    # include "vectorAccess.hpp"
    # include "vectorModifiers.hpp"
    # include "vectorRelationOperators.hpp"
}

#endif
