#ifndef ICONTAINERS_HPP
# define ICONTAINERS_HPP

# include <iostream>

namespace   ft
{
    // template <typename T>
    class IContainers
    {
        public:
        virtual ~IContainers() = 0;
        // IContainers(const ft::IContainers<T> &) = 0;
        // ft::IContainers<T>  &operator=(const ft::IContainers<T> &) = 0;
    };
}

#endif