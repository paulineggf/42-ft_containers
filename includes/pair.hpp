#ifndef PAIR_HPP
# define PAIR_HPP

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
}

#endif
