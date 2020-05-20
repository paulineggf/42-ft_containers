#include <iostream>
#include "vector.hpp"
#include <vector>

template<typename T>
class myAllocator {
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
    //    convert an myAllocator<T> to myAllocator<U>
    template<typename U>
    struct rebind {
        typedef myAllocator<U> other;
    };

public : 
    inline explicit myAllocator() { std::cout << "myAlloctor" << std::endl;}
    inline ~myAllocator() {}
    inline explicit myAllocator(myAllocator const&) {}
    template<typename U>
    inline explicit myAllocator(myAllocator<U> const&) {}

    //    address
    inline pointer address(reference r) { return &r; }
    inline const_pointer address(const_reference r) { return &r; }

    //    memory allocation
    inline pointer allocate(size_type cnt, 
       typename std::allocator<void>::const_pointer = 0) { 
      return reinterpret_cast<pointer>(::operator new(cnt * sizeof (T))); 
    }
    inline void deallocate(pointer p, size_type) { 
        ::operator delete(p); 
    }

    //    size
    inline size_type max_size() const { 
        return std::numeric_limits<size_type>::max() / sizeof(T);
 }

    //    construction/destruction
    inline void construct(pointer p, const T& t) { new(p) T(t); }
    inline void destroy(pointer p) { p->~T(); }

    inline bool operator==(myAllocator const&) { return true; }
    inline bool operator!=(myAllocator const& a) { return !operator==(a); }
};   

struct Player
{
	int id;
	std::string name;
 
	Player(int playerId, std::string playerName) :
			id(playerId), name(playerName)
	{
	}
};

int        main(void)
{
      // constructors used in the same order as described above:
    ft::vector<int> first;                                // empty vector of ints
    ft::vector<int> second (4,100);                       // four ints with value 100
    ft::vector<int> third (second.begin(),second.end());  // iterating through second
    ft::vector<int> fourth (third);                       // a copy of third

    std::cout << "The contents of first are:";
    for (ft::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "The contents of second are:";
    for (int i = 0; i < 4; i++)
        std::cout << second[i] << std::endl;
    for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    ft::vector<int, myAllocator<int> > alloc;

    ft::vector<std::string> str (4, "HELLO");                            
    for (ft::vector<std::string>::iterator it = str.begin(); it != str.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    	ft::vector<Player> listofPlayers;

    listofPlayers.push_back(Player(22, "Sid"));
    listofPlayers.push_back(Player(3, "Laura"));
    listofPlayers.push_back(Player(43, "Riti"));
 
	std::cout << "*******Iterate std::list using Iterators*******" << std::endl;
 
//Create an iterator of std::list
	ft::vector<Player>::iterator it;
 
// Make iterate point to begining and incerement it one by one till it reaches the end of list.
	for (it = listofPlayers.begin(); it != listofPlayers.end(); it++)
	{
		// Access the object through iterator
		// int id = it->id;
		// std::string name = it->name;
 
		//Print the contents
		// std::cout << id << " :: " << name << std::endl;
		std::cout << (*it).name << " :: " << std::endl;
		std::cout << it->name << " :: " << std::endl;
 
	}

    return 0;
}
