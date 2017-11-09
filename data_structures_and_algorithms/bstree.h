#pragma once

#include <iostream>
#include <functional>
#include <list>

template < typename T >
class BSTree;

template < typename T >
struct BSTreeNode
{
    BSTreeNode( T value )
        : _value( value )
    {
    }

    T _value;
    BSTreeNode* _left = nullptr;
    BSTreeNode* _right = nullptr;
};

template < typename T >
struct Itter
{
    typedef BSTreeNode< T > Node;
    typedef BSTree< T > Tree;

    Itter< T >( Tree* tree )
        : _tree( tree )
    {
        step_down( tree->_root );
    }

    void
    step_down( BSTreeNode< T >* node )
    {
        while ( node != nullptr )
        {
            _parents.emplace_back( node );
            node = node->_left;
        }
    }

    void
    step_up( )
    {
        BSTreeNode< T >* current = _parents.back( );

        while ( 1 )
        {
            if ( _parents.size( ) < 2 )
            {
                return;
            }

            _parents.pop_back( );

            if ( _parents.back( )->_left == current )
            {
                return;
            }

            current = _parents.back( );
        }
    }

    void
    next( )
    {
        BSTreeNode< T >* node = _parents.back( );

        if ( node->_right != nullptr )
        {
            step_down( node->_right );
            return;
        }

        step_up( );
    }

    Node*
    last( )
    {
        Node* node = _tree._root;
        while ( 1 )
        {
            if ( node->_right == nullptr )
            {
                return node;
            }
            node = node->_right;
        }
    }

    T operator*( )
    {
        return _parents.empty( ) ? T( ) : _parents.back( )->_value;
    }

    void operator++( int )
    {
        return next( );
    }

    std::list< BSTreeNode< T >* > _parents;
    BSTree< T >* _tree;
};

template < typename T >
class BSTree
{
    friend class Itter< T >;

public:
    typedef BSTreeNode< T > Node;

    bool insert( T value );
    bool remove( T value );
    bool contain( T value );
    void print( );
    size_t count( );

    Itter< T > begin( );

    Node* find( std::function< Node*( Node* ) > pred );

    ~BSTree( )
    {
        _delete( _root );
    }

private:
    Node* _root = nullptr;
    bool _insert( BSTreeNode< T >*& node, T value );
    bool _remove( BSTreeNode< T >*& node, T value );
    bool _insert( BSTreeNode< T >*& src, BSTreeNode< T >*& dest );
    void _print( BSTreeNode< T >* node );
    bool _contain( BSTreeNode< T >* node, T value );
    size_t _count( BSTreeNode< T >* node );

    void _delete( BSTreeNode< T >* node );
};

template < typename T >
bool
BSTree< T >::insert( T value )
{
    return _insert( _root, value );
}

template < typename T >
bool
BSTree< T >::remove( T value )
{
    return _remove( _root, value );
}

template < typename T >
void
BSTree< T >::print( )
{
    _print( _root );
    std::cout << std::endl;
}

template < typename T >
size_t
BSTree< T >::count( )
{
    return _count( _root );
}

template < typename T >
Itter< T >
BSTree< T >::begin( )
{
    return Itter< T >( this );
}

template < typename T >
BSTreeNode< T >*
BSTree< T >::find( std::function< Node*( Node* ) > pred )
{
    return pred( _root );
}

template < typename T >
bool
BSTree< T >::contain( T value )
{
    return _contain( _root, value );
}

template < typename T >
bool
BSTree< T >::_insert( BSTreeNode< T >*& node, T value )
{
    if ( node == nullptr )
    {
        node = new BSTreeNode< T >( value );
        return true;
    }

    if ( node->_value == value )
    {
        return false;
    }
    else if ( node->_value < value )
    {
        return _insert( node->_right, value );
    }
    else
    {
        return _insert( node->_left, value );
    }
}

template < typename T >
bool
BSTree< T >::_remove( BSTreeNode< T >*& node, T value )
{
    if ( node == nullptr )
    {
        return false;
    }

    if ( node->_value == value )
    {
        // delete node;
        BSTreeNode< T >* old_node = node;

        node = node->_right;
        _insert( old_node->_left, node );

        // clean deleted node
        old_node->_left = nullptr;
        old_node->_right = nullptr;
        delete old_node;

        return true;
    }

    if ( node->_value < value )
    {
        return _remove( node->_right, value );
    }
    else
    {
        return _remove( node->_left, value );
    }
}

template < typename T >
bool
BSTree< T >::_insert( BSTreeNode< T >*& src, BSTreeNode< T >*& dest )
{
    if ( src == nullptr || dest == nullptr )
    {
        return false;
    }

    BSTreeNode< T >*& node = src->_value < dest->_value ? dest->_left : dest->_right;

    if ( node == nullptr )
    {
        node = src;
        return true;
    }

    return _insert( src, node );
}

template < typename T >
void
BSTree< T >::_print( BSTreeNode< T >* node )
{
    if ( node == nullptr )
    {
        return;
    }

    _print( node->_left );
    std::cout << node->_value << " - ";
    _print( node->_right );
}

template < typename T >
bool
BSTree< T >::_contain( BSTreeNode< T >* node, T value )
{
    if ( node == nullptr )
    {
        return false;
    }

    if ( node->_value == value )
    {
        return true;
    }

    return node->_value < value ? _contain( node->_right, value ) : _contain( node->_left, value );
}

template < typename T >
size_t
BSTree< T >::_count( BSTreeNode< T >* node )
{
    return ( node == nullptr ) ? 0 : ( 1 + _count( node->_left ) + _count( node->_right ) );
}

template < typename T >
void
BSTree< T >::_delete( BSTreeNode< T >* node )
{
    if ( node == nullptr )
    {
        return;
    }

    _delete( node->_left );
    _delete( node->_right );

    delete node;
}
