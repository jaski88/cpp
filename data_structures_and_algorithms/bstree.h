#pragma once

#include <iostream>

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
class BSTree
{
public:
    bool insert( T value );
    bool remove( T value );
    bool contain( T value );
    void print( );
    size_t count( );

private:
    BSTreeNode< T >* _root = nullptr;
    void _insert( BSTreeNode< T >*& node, T value );
    bool _remove( BSTreeNode< T >*& node, T value );
    bool _insert( BSTreeNode< T >*& src, BSTreeNode< T >*& dest );
    void _print( BSTreeNode< T >* node );
    bool _contain( BSTreeNode< T >* node, T value );
    size_t _count( BSTreeNode< T >* node );
};

template < typename T >
bool
BSTree< T >::insert( T value )
{
    _insert( _root, value );
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
bool
BSTree< T >::contain( T value )
{
    return _contain( _root, value );
}

template < typename T >
void
BSTree< T >::_insert( BSTreeNode< T >*& node, T value )
{
    if ( node == nullptr )
    {
        node = new BSTreeNode< T >( value );
        return;
    }

    if ( node->_value == value )
    {
        return;
    }
    else if ( node->_value < value )
    {
        _insert( node->_right, value );
    }
    else
    {
        _insert( node->_left, value );
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
