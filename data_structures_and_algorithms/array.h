#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iostream>

class Array
{
public:
    template < typename T >
    static void
    print_pairs( T array, int expected )
    {
        std::sort( array.begin( ), array.end( ) );

        std::unordered_map< int, int > map;

        for ( auto const i : array )
        {
            const int to_find = map[ expected - i ];
            const bool found = map.find( to_find ) != map.end( );

            if ( found )
            {
                std::cout << "print_pair: " << i << "," << to_find << " for " << expected
                          << std::endl;
            }

            map[ i ] = i;
        }
    }

    template < typename T >
    static void
    print_subarray( const T& array, int expected_sum )
    {
        std::vector< int > sum;

        for ( auto it = array.begin( ); it < array.end( ); it++ )
        {
            for ( auto it2 = it; it2 < array.end( ); it2++ )
            {
                sum.push_back( *it2 );

                if ( std::accumulate( sum.begin( ), sum.end( ), 0 ) == expected_sum )
                {
                    std::cout << "print_subarray: " << to_str( sum ) << " for " << expected_sum
                              << std::endl;
                }
            }

            sum.clear( );
        }
    }

    template < typename T >
    static void
    sort_binary_array( T& array )
    {
        int zero_elements = std::count( array.begin( ), array.end( ), 0 );
        for( int i = 0; i < array.size( ); i++ )
        {
            const int element = i <= zero_elements - 1 ? 0 : 1;
            array[ i ] = element;
        }
    }

    template < typename T >
    static std::string
    to_str( const T& array )
    {
        return std::accumulate( std::next( array.begin( ) ), array.end( ),
                                std::to_string( array.at( 0 ) ), []( const std::string a, int b )
                                {
                                    return a + ", " + std::to_string( b );
                                } );
    }
};

#endif  // ARRAY_H
