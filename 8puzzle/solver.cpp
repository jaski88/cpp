#include "solver.h"

#include <iostream>
#include <memory>

struct BoardPrio
{
    bool
    operator( )( SolverStepPtr& lhs, SolverStepPtr& rhs ) const
    {
        return lhs->prio( ) + lhs->step > rhs->prio( );
    }
};

void
Solver::run( Board& initial )
{
    std::priority_queue< SolverStepPtr, std::vector< SolverStepPtr >, BoardPrio > queue;

    SolverStepPtr current_step = std::make_shared< SolverStep >( initial, 0, nullptr );
    queue.push( current_step );

    int i = 0;

    while ( !current_step->board.isGoal( ) )
    {
        current_step = queue.top( );
        queue.pop( );

        for ( Board neighbour : current_step->board.neighbours( ) )
        {
            // add new node if it was not added before
            if ( current_step->parent == nullptr || current_step->parent->board != neighbour )
            {
                SolverStepPtr sptr = std::make_shared< SolverStep >(
                    neighbour, current_step->step + 1, current_step );
                queue.push( sptr );
            }
        }

        i++;

        if ( i > 10000 )
        {
            std::cout << "failed" << std::endl;
            return;
        }
    }

    std::cout << "solved" << std::endl;

    while ( current_step != nullptr )
    {
        _solution.insert( _solution.begin( ), current_step->board );
        current_step = current_step->parent;
    }
}

std::vector< Board >
Solver::solution( )
{
    return _solution;
}
