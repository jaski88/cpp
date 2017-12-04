#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include <iostream>

template < int N >
struct INT
{
    static const int VALUE = N;
};

struct FLOAT
{
    static constexpr float VALUE = 10.2;
};

struct NIL
{
    typedef NIL HEAD;
    typedef NIL TAIL;
    static constexpr int VALUE = 0;
};

template < typename H, typename T = NIL >
struct List
{
    typedef H HEAD;
    typedef T TAIL;
};

template < typename LIST >
struct Length
{
    typedef typename LIST::TAIL TAIL;
    static const int value = Length< TAIL >::result;
    static const int result = 1 + value;
};

template <>
struct Length< NIL >
{
    static const int result = 0;
};

template < typename LIST >
struct Sum
{
    typedef typename LIST::TAIL TAIL;
    typedef typename LIST::HEAD HEAD;
    static const int value = Sum< TAIL >::result;
    static const int result = HEAD::VALUE + value;
};
template <>
struct Sum< NIL >
{
    static const int result = 0;
};

template < typename LIST, int N >
struct Nth
{
    typedef typename LIST::TAIL TAIL;
    typedef typename Nth< TAIL, N - 1 >::result result;
};

template < typename LIST >
struct Nth< LIST, 0 >
{
    typedef typename LIST::HEAD result;
};

template < typename LST >
struct Multiply
{
    typedef typename LST::TAIL TAIL;
    typedef typename LST::HEAD HEAD;
    static const int value = Multiply< TAIL >::result;
    static const int result = HEAD::VALUE * value;
};

template <>
struct Multiply< NIL >
{
    static const int result = 1;
};

template < class X, class Y >
struct Eq
{
    static const bool result = false;
};

template < class X >
struct Eq< X, X >
{
    static const bool result = true;
};

template < class Elm, class LST >
struct Includes
{
    static const bool result = std::is_same< Elm, typename LST::HEAD >::value
                               || Includes< Elm, typename LST::TAIL >::result;
};

template < class Elm >
struct Includes< Elm, NIL >
{
    static const bool result = false;
};

template < typename Elm, typename LIST = NIL >
struct Prepend
{
    typedef List< Elm, LIST > result;
};

template < class Elm, typename LST = NIL >
struct Append
{
    typedef typename LST::HEAD Head;
    typedef typename LST::TAIL Tail;

    typedef typename Append< Elm, Tail >::result Next;
    typedef List< Head, Next > result;
};

template < class Elm >
struct Append< Elm, NIL >
{
    typedef List< Elm > result;
};

// template <typename Elm, typename Lst=NIL>
// struct Append {
//    typedef typename _Append<Elm, Lst>::result result;
//};

template < class Elm, class Lst >
struct _Position
{
//    static const char* msg = "No element";

    static_assert( Includes< Elm, Lst >::result, "No element"  );

    typedef typename Lst::HEAD Head;
    typedef typename Lst::TAIL Tail;
    static const bool found = std::is_same< Head , Elm >::value;
    static const int result = found ? 0 : 1 + _Position< Elm, Tail >::result;
//    static const int next = Position< Elm, Tail >::result;
};

// The compiler will try to expand the position check
// after NIL has been reached if this isn't here
template <typename Elm> struct _Position<Elm, NIL> {
    static const int result = -100;
};

//template <typename Elm, typename LST>
//struct Position {
//    typedef typename Assert<Includes< Elm, LST >::result>::check include;
//    static const int result = _Position<Elm, LST>::result;
//};



template< typename Lst>
struct Print
{
    typedef typename Lst::HEAD HEAD;
    typedef typename Lst::TAIL TAIL;
    static const void print( )
    {
        std::cout << HEAD::VALUE << ", ";
        Print<TAIL>::print( );
    }
};

template<>
struct Print<NIL>
{
    static const void print( )
    {
         std::cout << std::endl;
    }
};


#endif // STATIC_LIST_H
