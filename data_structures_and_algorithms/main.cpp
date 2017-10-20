#include <iostream>

#include <array>
#include <numeric>
#include <algorithm>
#include <unordered_map>

using namespace std;

template < typename T >
std::string
to_string( const T& array )
{
    std::string s
        = std::accumulate( std::next( array.begin( ) ), array.end( ),
                           std::to_string( array.at( 0 ) ), []( const std::string a, int b )
                           {
                               return a + ", " + std::to_string( b );
                           } );
    return s;
}

template < typename T >
std::pair< int, int >
find_pair( T array, int expected )
{
    std::sort( array.begin( ), array.end( ) );

    std::unordered_map< int, int > map;

    for ( auto const i : array )
    {
        const int to_find = map[ expected - i ];
        const bool found = map.find( to_find ) != map.end( );

        if ( found )
        {
            return std::make_pair( i, to_find );
        }

        map[ i ] = i;
    }

    return std::make_pair( 0, 0 );
}

int
main( int argc, char* argv[] )
{
    const std::array< int, 5 > data = {1, 4, 8, 5, 2};
    std::cout << "data: " << to_string( data ) << std::endl;

    const std::pair< int, int > pair = find_pair( data, 7 );
    std::cout << "pair: " << std::get< 0 >( pair ) << "," << std::get< 1 >( pair ) << std::endl;

    return 0;
}
