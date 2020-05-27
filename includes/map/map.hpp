#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "../list/list.hpp"

namespace ft
{
    template<class Key, class T>
    struct       pair
    {
        public:

        Key         first;
        T           second;

        pair() {}
        pair(Key key, T data) : first(key), second(data) {}
        pair &operator=(const pair &x) {
                first = x.first;
                second = x.second;
                return *this; }
        ~pair() {}
    };

    template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key, T> > >
    class   map
    {
        public:

        // TYPEDEF

        typedef Key             key_type;
        typedef T               mapped_type;
        typedef Compare         key_compare;
        typedef Alloc           allocator_type;
        typedef std::ptrdiff_t  difference_type;
        typedef std::size_t     size_type;
        typedef ft::pair<key_type, mapped_type>
                                value_type;
        typedef value_type&     reference;
        typedef typename allocator_type::const_reference
                                const_reference;
        typedef typename allocator_type::pointer
                                pointer;

        private:

        key_compare         _comp;
        allocator_type      _alloc;
        ft::list<value_type, allocator_type>
                            _data;

        public:

        class value_compare
        {
            friend class map;
            
            protected:

            key_compare     _comp;
            value_compare (key_compare c) : _comp(c) {}
            value_compare (const value_compare &x) { _comp = x._comp; }
            // value_compare &operator=(const value_compare &x) {
            //     _comp = x._comp;
            //     return *this; }

            public:

            typedef bool        result_type;
            typedef value_type  first_argument_type;
            typedef value_type  second_argument_type;

            bool operator() (const value_type& x, const value_type& y) const
            {
                return _comp(x.first, y.first);
            }
        };

        // ITERATOR

        typedef typename ft::list<value_type, allocator_type>::iterator
                                iterator;
        typedef typename ft::list<value_type, allocator_type>::const_iterator
                                const_iterator;
        typedef typename ft::list<value_type, allocator_type>::reverse_iterator
                                reverse_iterator;                        
        typedef typename ft::list<value_type, allocator_type>::const_reverse_iterator
                                const_reverse_iterator; 

        iterator                  begin()
        {
            return _data.begin();
        }

        iterator                  end()
        {
            return _data.end();
        }

        const_iterator            begin() const
        {
            return _data.begin();
        }

        const_iterator            end() const
        {
            return _data.end();
        }

        reverse_iterator          rbegin()
        {
            return _data.rbegin();
        }

        const_reverse_iterator    rbegin() const
        {
            return _data.rbegin();
        }

        reverse_iterator          rend()
        {
            return _data.rend();
        }

        const_reverse_iterator    rend() const
        {
            return _data.rend();
        }                            

        // INITIALISATIONS

        explicit map(const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type());
        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type());
        map(const map& x);
        ~map() {}

        map             &operator=(const map &x);

        // CAPACITY

        bool            empty() const;
        size_type       size() const;
        size_type       max_size() const;

        // ELEMENT ACCESS

        mapped_type     &operator[](const key_type &k);

        // MODIFIERS

        void            erase(iterator position);
        size_type       erase(const key_type &k);
        void            erase(iterator first, iterator last);
        ft::pair<iterator, bool>
                        insert(const value_type &val);
        iterator        insert(iterator position, const value_type &val);
        template<class InputIterator>
        void            insert(InputIterator first, InputIterator last);
        void            swap(map &x);
        void            clear();

        // OBSERVERS

        key_compare     key_comp() const;
        value_compare   value_comp() const;

        // OPERATIONS

        iterator        find(const key_type &k);
        const_iterator  find(const key_type &k) const;
        size_type       count(const key_type &k) const;
        iterator        lower_bound(const key_type &k);
        const_iterator  lower_bound(const key_type &k) const;
        iterator        upper_bound(const key_type &k);
        const_iterator  upper_bound(const key_type &k) const;
        ft::pair<const_iterator, const_iterator>
                        equal_range(const key_type &k) const;
        ft::pair<iterator, iterator>
                        equal_range(const key_type &k);
    };

    # include "mapInit.hpp"
    # include "mapAcces.hpp"
    # include "mapObservers.hpp"
    # include "mapCapacity.hpp"
    # include "mapModifiers.hpp"
    # include "mapOperations.hpp"
}

#endif
