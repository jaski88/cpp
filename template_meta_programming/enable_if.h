#ifndef ENABLE_IF_H
#define ENABLE_IF_H

#include <iostream>

template < class T, class Enable  = void >
struct A
{
    void operator( )( )
    {
        std::cout << "basic type" << std::endl;
    }
};

template < class T >
struct A< T, typename std::enable_if< std::is_class< T >::value >::type >
{
    void operator()()
    {
        std::cout << "class type" << std::endl;
    }
};

class Test
{};

#endif // ENABLE_IF_H
