#ifndef SOLVER_H
#define SOLVER_H

#include <memory>
#include <queue>
#include "board.h"

struct SolverStep;

typedef std::shared_ptr< SolverStep > SolverStepPtr;

struct SolverStep
{
    SolverStep( Board board, int step, SolverStepPtr parent )
        : board( board )
        , step( step )
        , parent( parent )
    {
    }

    Board board;
    int step;
    SolverStepPtr parent;

    int
    prio( )
    {
        return board.priority( ) + step;
    }
};

class Solver
{
public:
    Solver( ) = default;
    void run( Board& initial );
    std::vector< Board > solution( );

private:
    std::vector< Board > _solution;
};

#endif  // SOLVER_H
