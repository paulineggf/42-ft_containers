#ifndef ALLOCATOR_HPP
# define ALLOCATOR_HPP

namespace ft
{
    template<typename T>
    class allocator {
    public : 
    //    typedefs
    typedef T value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

    public : 
    //    convert an allocator<T> to allocator<U>
    template<typename U>
    struct rebind {
        typedef allocator<U> other;
    };

    public : 
    explicit allocator() {}
    ~allocator() {}
    explicit allocator(allocator const&) {}
    template<typename U>
    explicit allocator(allocator<U> const&) {}

    //    address
    pointer address(reference r) { return &r; }
    const_pointer address(const_reference r) { return &r; }

    //    memory allocation
    pointer allocate(size_type cnt, 
    typename std::allocator<void>::const_pointer = 0) { 
        return reinterpret_cast<pointer>(::operator new(cnt * sizeof (T))); 
    }
    void deallocate(pointer p, size_type) { 
        ::operator delete(p); 
    }

    //    size
    size_type max_size() const { 
        return std::numeric_limits<size_type>::max() / sizeof(T);
    }

    //    construction/destruction
    void construct(pointer p, const T& t) { new(p) T(t); }
    void destroy(pointer p) { p->~T(); }

    bool operator==(allocator const&) { return true; }
    bool operator!=(allocator const& a) { return !operator==(a); }
    };
}

#endif
