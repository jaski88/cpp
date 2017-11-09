#ifndef LIST_TEST_H
#define LIST_TEST_H

#include "../list.h"

namespace tests
{

class ListTest
{
public:
    bool static run_all( );
private:
    bool static push_pop( );
    bool static interate_loop( );
    bool static for_loop( );
    bool static insert_remove( );
};
}

#endif  // LIST_TEST_H
