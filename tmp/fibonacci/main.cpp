#include <iostream>

using namespace std;

template < const int N >
struct Fibonacci
{
    static const int value = Fibonacci< N - 1 >::value + Fibonacci< N - 2 >::value;
};

template <>
struct Fibonacci< 1 >
{
    static const int value = 1;
};

template <>
struct Fibonacci< 0 >
{
    static const int value = 1;
};

int
main( int argc, char* argv[] )
{
    cout << "Fib(10) = " << Fibonacci< 10 >::value << endl;
    return 0;
}
