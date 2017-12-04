#ifndef FIBONACCI_H
#define FIBONACCI_H

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

#endif // FIBONACCI_H
