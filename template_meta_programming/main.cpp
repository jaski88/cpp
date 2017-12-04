#include <iostream>
#include <type_traits>

#include "fibonacci.h"
#include "prime.h"
#include "enable_if.h"
#include "static_list.h"

using namespace std;

typedef List< INT< 1 >, List< INT< 2 >, List< INT< 10 >, List< INT< 1210 > > > > > my_list;

template < bool Condition >
class IF
{
public:
    static inline void
    EXEC( )
    {
        std::cout << "Statement is true" << std::endl;
    }
};

template <>
class IF< false >
{
public:
    static inline void
    EXEC( )
    {
        std::cout << "Statement is false" << std::endl;
    }
};

int
main( int argc, char* argv[] )
{
    // Print prime numbers
    Prime_print< 18 > prime;
    prime.f( );

    cout << "Fib(10) = " << Fibonacci< 10 >::value << endl;

    IF< Fibonacci< 10 >::value == 89 >::EXEC( );

    A< int > a;
    a( );

    A< Test > b;
    b( );

    std::cout << "Print: " << std::endl;
    Print< my_list >::print( );

    std::cout << "Pos: " << _Position< INT< 1210 >, my_list >::result << std::endl;

    std::cout << "includes: " << Includes< INT< 6 >, my_list >::result << std::endl;

    std::cout << "length: " << Length< my_list >::result << std::endl;

    typedef Prepend< INT< 22 >, my_list >::result fancy_list;

    typedef Append< INT< 10 >, fancy_list >::result one_element_list;

    std::cout << "new length: " << Length< one_element_list >::result << std::endl;

    std::cout << Sum< my_list >::result << std::endl;

    std::cout << Nth< my_list, 40 >::result::VALUE << std::endl;

    std::cout << Multiply< my_list >::result << std::endl;

    return 0;
}
