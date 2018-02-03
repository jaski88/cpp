#ifndef STRONG_TYPE_H
#define STRONG_TYPE_H

#include <map>

template < typename T >
struct strong_type
{
    const T value;
    explicit strong_type( T v )
        : value{v}
    {
    }

    T
    operator( )( )
    {
        return value;
    }
};

template < typename T >
bool
operator<( const strong_type< T > first, const strong_type< T > second )
{
    return first.value < second.value;
}

typedef strong_type< std::string > product_t;
typedef strong_type< std::string > category_t;

typedef strong_type< unsigned int > price_t;
typedef strong_type< unsigned int > quantity_t;

typedef std::map< product_t, price_t > price_list_t;

price_list_t price_list = {{product_t{"product#1"}, price_t{20}}};

std::map< category_t, price_list_t > product_map
    = {{category_t{"category#1"},
        {{product_t{"product#1"}, price_t{10}}, {product_t{"product#2"}, price_t{20}}}},
       {category_t{"category#2"},
        {{product_t{"product#3"}, price_t{10}}, {product_t{"product#4"}, price_t{20}}}}};

#endif  // STRONG_TYPE_H
