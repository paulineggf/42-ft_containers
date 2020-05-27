#ifndef LIST_HPP
# define LIST_HPP

# include <limits>
# include <iostream>
# include "reverse_iterator.hpp"

namespace ft
{
    template<class T, class Alloc = std::allocator<T> >
    class   list
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


        // ARGUMENTS

        private :

        class      Node
        {
            public:
            T       _data;
            Node    *_M_prev;
            Node    *_M_next;

            Node(const T &data) : _data(data), _M_prev(NULL), _M_next(NULL) {}
            Node(const T &data, Node *previous) : _data(data), _M_prev(previous), _M_next(NULL) {}
            Node(const T &data, Node *previous, Node *next) : _data(data), _M_prev(previous), _M_next(next) {}
            ~Node() {}
        };       

        allocator_type  _alloc;
        Node            *_list;
        size_type       _size;

        public:

        // ITERATOR

        class       iterator
        {
            public:
            typedef T                   value_type;
            typedef T*                  pointer;
            typedef std::size_t         size_type;
            typedef value_type&         reference;
            typedef const value_type&   const_reference;
            typedef std::ptrdiff_t      difference_type;

            public:

            Node      *_M_node;
            
            iterator();
            iterator(Node *list);
            iterator(const Node *list);
            iterator(const iterator &rhs);
            ~iterator();

            void            operator=(const iterator &rhs);
            iterator        &operator++();
            iterator        operator++(int);
            iterator        operator--();
            iterator        operator--(int);
            reference       operator*();
            pointer         operator->();
            bool            operator!=(const iterator &rhs);
            bool            operator==(const iterator &rhs);
        };

        // REVERSE_ITERATOR

        typedef ft::reverse_iterator<iterator>
                                        reverse_iterator;

        // CONST_ITERATOR

        class       const_iterator : public iterator
        {
            public:

            typedef const_reference reference;

            const_iterator() : iterator() {}
            const_iterator(Node *list) : iterator(list) {}
            const_iterator(const iterator it) : iterator(it) {}
            const_iterator(const Node *list) : iterator(list) {}
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

        iterator                  begin();
        iterator                  end();
        const_iterator            begin() const;
        const_iterator            end() const;
        reverse_iterator          rbegin();
        const_reverse_iterator    rbegin() const;
        reverse_iterator          rend();
        const_reverse_iterator    rend() const;

        // INITIALISATIONS

        explicit list(const allocator_type& alloc = allocator_type());
        explicit list(size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type());
        template<class InputIterator>
        list(InputIterator first, InputIterator last,
                        const allocator_type& alloc = allocator_type());
        list(const list& x);
        ~list();
        
        list& operator=(const list& x);

        // CAPACITY

        size_type       size() const;
        bool            empty() const;
        size_type       max_size() const;

        // MODIFIERS

        void            push_front(const value_type &val);
        void            push_back(const value_type &val);
        void            pop_back();
        void            pop_front();
        template<class InputIterator>
        void            assign(InputIterator first, InputIterator last);
        void            assign(size_type n, const value_type &val);
        void            assign(int n, int val);
        void            clear();
        iterator        insert(iterator position, const value_type& val);
        void            insert(iterator position, size_type n, const value_type& val);
        void            insert(iterator position, int n, int val);
        template <class InputIterator>
        void            insert(iterator position, InputIterator first, InputIterator last);
        void            resize(size_type n, value_type val = value_type());
        iterator        erase(iterator position);
        iterator        erase(iterator first, iterator last);
        void            swap(list &x);
    
        // ELEMENT ACCESS

        reference       back();
        const_reference back() const;
        reference       front();
        const_reference front() const;

        // OPERATIONS

        void            splice(iterator position, list &x);
        void            splice(iterator position, list &x, iterator i);
        void            splice(iterator position, list &x, iterator first, iterator last);
        void            remove(const value_type &val);
        template<class Predicate>
        void            remove_if(Predicate pred);
        void            sort();
        template<class Compare>
        void            sort(Compare comp);
        void            unique();
        template<class BinaryPredicate>
        void            unique(BinaryPredicate binary_pred);
        void            merge(list &x);
        template<class Compare>
        void            merge(list &x, Compare comp);
        void            reverse();

        friend
        void                swap(list<T,Alloc>& x, list<T,Alloc>& y)
        {
            list<T, Alloc> tmp;

            tmp.assign(x.begin(), x.end());
            x.assign(y.begin(), y.end());
            y.assign(tmp.begin(), tmp.end());
        }

        private:
        
        static Node     *lastList(Node *list);
        static Node     *listAt(Node *list, int nb);
    };

    # include "listInit.hpp"
    # include "listIterators.hpp"
    # include "listModifiers.hpp"
    # include "listCapacity.hpp"
    # include "listAccess.hpp"
    # include "listOperations.hpp"
    # include "listRelationOperators.hpp"
}

#endif
