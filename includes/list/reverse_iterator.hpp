#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{
    template<typename iter_type>
    class       reverse_iterator
    {
        protected:
        iter_type           _it;
        iter_type           _base;

        public:

        typedef std::ptrdiff_t      difference_type;

        reverse_iterator() : _it(0), _base(0) {}
        reverse_iterator(iter_type it) : _it(it), _base(it) {}
        reverse_iterator(const reverse_iterator &rit) : _it(rit._it), _base(rit._base) {}
        ~reverse_iterator() {}

        reverse_iterator        operator+(int nb);
        friend
        reverse_iterator        operator+(int nb, reverse_iterator &rhs) { return rhs - nb; }
        reverse_iterator        operator-(int nb);
        friend
        difference_type         operator-(const reverse_iterator lhs, const reverse_iterator &rhs) {
                return (&((*lhs._arg)[lhs._idx])) - (&((*rhs._arg)[rhs._idx])); }
        reverse_iterator        operator++();
        reverse_iterator        operator++(int);
        reverse_iterator        operator--();
        reverse_iterator        operator--(int);
        typename
        iter_type::reference    operator*();
        bool                    operator!=(const reverse_iterator &rhs);
        void                    operator=(const reverse_iterator &rhs);
        bool                    operator<(const reverse_iterator &rhs);
        bool                    operator>(const reverse_iterator &rhs);
        bool                    operator<=(const reverse_iterator &rhs);
        bool                    operator>=(const reverse_iterator &rhs);
        bool                    operator==(const reverse_iterator &rhs);
        iter_type               base() const;
    };

    template<typename iter_type>
    typename ft::reverse_iterator<iter_type>        ft::reverse_iterator<iter_type>::operator+(int nb)
    {
        _it - nb;
        return *this;
    }
    
    template<typename iter_type>
    typename ft::reverse_iterator<iter_type>        ft::reverse_iterator<iter_type>::operator-(int nb)
    {
        _it + nb;
        return *this;
    }

    template<typename iter_type>
    typename ft::reverse_iterator<iter_type>        ft::reverse_iterator<iter_type>::operator++()
    {
        _it--;
        return *this;
    }

    template<typename iter_type>
    typename ft::reverse_iterator<iter_type>        ft::reverse_iterator<iter_type>::operator++(int)
    {
        _it--;
        return *this;
    }

    template<typename iter_type>
    typename ft::reverse_iterator<iter_type>        ft::reverse_iterator<iter_type>::operator--()
    {
        _it++;
        return *this;
    }

    template<typename iter_type>
    typename ft::reverse_iterator<iter_type>        ft::reverse_iterator<iter_type>::operator--(int)
    {
        _it++;
        return *this;
    }
    
    template<typename iter_type>
    typename iter_type::reference   ft::reverse_iterator<iter_type>::operator*()
    {
        return  *_it;
    }
    
    template<typename iter_type>
    bool                    ft::reverse_iterator<iter_type>::operator!=(const reverse_iterator &rhs)
    {
        return _it != rhs._it;
    }

    template<typename iter_type>
    void                    ft::reverse_iterator<iter_type>::operator=(const ft::reverse_iterator<iter_type> &rhs)
    {
        _it = rhs._it;
    }
    
    template<typename iter_type>
    bool                    ft::reverse_iterator<iter_type>::operator<(const ft::reverse_iterator<iter_type> &rhs)
    {
        return _it < rhs._it;
    }

    template<typename iter_type>
    bool                    ft::reverse_iterator<iter_type>::operator>(const ft::reverse_iterator<iter_type> &rhs)
    {
        return _it > rhs._it;
    }
    
    template<typename iter_type>
    bool                    ft::reverse_iterator<iter_type>::operator<=(const ft::reverse_iterator<iter_type> &rhs)
    {
        return _it <= rhs._it;
    }

    template<typename iter_type>
    bool                    ft::reverse_iterator<iter_type>::operator>=(const ft::reverse_iterator<iter_type> &rhs)
    {
        return _it >= rhs._it;
    }

    template<typename iter_type>
    bool                    ft::reverse_iterator<iter_type>::operator==(const ft::reverse_iterator<iter_type> &rhs)
    {
        return _it == rhs._it;
    }

    template<typename iter_type>
    iter_type               ft::reverse_iterator<iter_type>::base() const
    {
        return _base;
    }

}

#endif
