#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board
{
public:
    //    Board( const std::initializer_list< int > list, int n );
    Board( const std::vector< int > list, int n );
    Board( ) = default;
//    Board( const Board& other );
//    Board( Board&& other );
//    Board& operator=(const Board& other ) = default;

    bool operator==(const Board& other);
    bool operator!=(const Board& other);

    bool isGoal( );
    int priority( );
    std::vector< Board > neighbours( );

    int hamming( );
    int manhattan( );
    void print( ) const;

private:
    int _hamming = -1;
    int _manhattan = -1;
    int _step = 0;
    std::vector< int > _board;
    std::vector< int > _solution;
    int _n;
};

#endif  // BOARD_H
