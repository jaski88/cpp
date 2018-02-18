#include "board.h"

#include <algorithm>  // std::find
#include <iostream>
#include <vector>

namespace
{
const int EMPTY = 0;
}

Board::Board( const std::vector< int > list, int n )
    : _board( list )
    , _n( n )
{
    size_t board_size = _n * _n;

    _solution.resize( board_size );
    for ( size_t i = 0; i < board_size - 1; i++ )
    {
        _solution[ i ] = i + 1;
    }
    _solution[ board_size - 1 ] = EMPTY;
}

bool
Board::operator==( const Board& other )
{
    return _board == other._board;
}

bool
Board::operator!=( const Board& other )
{
    return _board != other._board;
}

// Board::Board( const Board& other )
//{
//    std::cout << "copy" << std::endl;
//}
// Board::Board(Board &&other )
//{
//    std::cout << "move" << std::endl;
//}

bool
Board::isGoal( )
{
    return _board == _solution;
}

int
Board::priority( )
{
    return hamming( ) + manhattan( );
}

std::vector< Board >
Board::neighbours( )
{
    std::vector< Board > boards;

    auto it = std::find( std::begin( _board ), std::end( _board ), EMPTY );
    int index = std::distance( _board.begin( ), it );

    // top
    {
        int top_index = index - _n;
        if ( top_index > 0 )
        {
            std::vector< int > cpy = _board;
            cpy[ index ] = cpy[ top_index ];
            cpy[ top_index ] = EMPTY;
            boards.push_back( Board( cpy, _n ) );
        }
    }

    // bottom
    {
        int bottom_index = index + _n;
        if ( bottom_index < _n * _n )
        {
            std::vector< int > cpy = _board;
            cpy[ index ] = cpy[ bottom_index ];
            cpy[ bottom_index ] = EMPTY;
            boards.push_back( Board( cpy, _n ) );
        }
    }

    // right
    {
        int _index = index + 1;
        if ( _index % _n != 0 )
        {
            std::vector< int > cpy = _board;
            cpy[ index ] = cpy[ _index ];
            cpy[ _index ] = EMPTY;
            boards.push_back( Board( cpy, _n ) );
        }
    }

    // left
    {
        int _index = index - 1;
        if ( index % _n != 0 )
        {
            std::vector< int > cpy = _board;
            cpy[ index ] = cpy[ _index ];
            cpy[ _index ] = EMPTY;
            boards.push_back( Board( cpy, _n ) );
        }
    }

    return boards;
}

int
Board::hamming( )
{
    if ( _hamming == -1 )
    {
        _hamming = 0;

        for ( size_t i = 0; i < _solution.size( ); i++ )
        {
            if ( _solution[ i ] != 0 )
            {
                _hamming += ( _board[ i ] == i + 1 ) ? 0 : 1;
            }
        }

        return _hamming;
    }
}

int
Board::manhattan( )
{
    if ( _manhattan == -1 )
    {
        _manhattan = 0;

        for ( size_t i = 0; i < _solution.size( ); i++ )
        {
            if ( _solution[ i ] != 0 )
            {
                _manhattan += abs( _board[ i ] - ( i + 1 ) );
            }
        }
    }

    return _manhattan;
}

void
Board::print( ) const
{
    int i = 0;
    for ( int it : _board )
    {
        std::cout << " | " << it;
        i++;
        if ( i % _n == 0 )
        {
            std::cout << " | " << std::endl;
        }
    }
}
