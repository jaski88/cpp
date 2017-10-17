#include <iostream>

using namespace std;

struct Coffee
{
    virtual void prepare( ) = 0;
    virtual void
    finish( )
    {
        std::cout << std::endl;
    }
};

struct BlackCoffee : public Coffee
{
public:
    void
    prepare( ) override
    {
        std::cout << "Black coffee";
    }
};

template < typename T >
struct CreamDecorator : public Coffee
{
    CreamDecorator( )
        : m_decorator( )
    {
    }

    T m_decorator;

    void
    prepare( ) override
    {
        m_decorator.prepare( );
        std::cout << " with cream";
    }
};

template < typename T >
struct MilkDecorator : public Coffee
{
    MilkDecorator( )
        : m_decorator( )
    {
    }

    T m_decorator;

    void
    prepare( ) override
    {
        m_decorator.prepare( );
        std::cout << " with milk";
    }
};

template < typename T >
struct SugarDecorator : public Coffee
{
    SugarDecorator( )
        : m_decorator( )
    {
    }

    T m_decorator;

    void
    prepare( ) override
    {
        m_decorator.prepare( );
        std::cout << " and with sugar";
    }
};

int
main( int argc, char* argv[] )
{
    MilkDecorator< BlackCoffee > coffee_with_milk;
    coffee_with_milk.prepare( );
    coffee_with_milk.finish( );

    SugarDecorator< CreamDecorator< BlackCoffee > > coffee_with_sugar_and_cream;
    coffee_with_sugar_and_cream.prepare( );
    coffee_with_sugar_and_cream.finish( );

    return 0;
}
