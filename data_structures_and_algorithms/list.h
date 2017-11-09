#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <iostream>

template < typename T >
class List;

template < typename T >
struct ListItem
{
    explicit ListItem( T _value )
        : value( _value )
    {
    }

    T value;
    ListItem< T >* next = nullptr;
    ListItem< T >* prev = nullptr;
};

template < typename T >
struct ListIter
{
    ListItem< T >* _current = nullptr;

    ListIter< T >*
    next( )
    {
        if ( _current != nullptr )
        {
            _current = _current->next;
        }
        return this;
    }

    ListIter< T >* operator++( int )
    {
        return next( );
    }

    T operator*( )
    {
        return _current != nullptr ? _current->value : T( );
    }

    bool operator( )( )
    {
        return _current != nullptr;
    }

    bool operator==( ListIter< T > iter )
    {
        return _current == iter._current;
    }

    bool operator!=( ListIter< T > iter )
    {
        return _current != iter._current;
    }

    ListIter< T >* operator++( )
    {
        return next( );
    }
};

template < typename T >
class List
{
    typedef ListItem< T > Node;
    typedef ListIter< T > Iter;

public:
    void push_back( T value );
    void push_front( T value );

    T pop_front( );
    T pop_back( );

    bool remove( size_t index );
    bool insert( size_t index, T value );

    size_t count( );
    bool empty( );

    Iter begin( );
    Iter end( );

    void print( );

private:
    Node* _root = nullptr;
};

template < typename T >
void
List< T >::push_back( T value )
{
    if ( _root == nullptr )
    {
        _root = new Node( value );
        return;
    }

    Node* node = _root;
    while ( node->next != nullptr )
    {
        node = node->next;
    }

    Node* new_node = new Node( value );
    new_node->prev = node;
    node->next = new_node;
}

template < typename T >
void
List< T >::push_front( T value )
{
    Node* node = new Node( value );
    node->next = _root;
    _root = node;
}

template < typename T >
T
List< T >::pop_front( )
{
    if ( _root == nullptr )
    {
        return T( );
    }

    T value = _root->value;
    Node* node = _root;

    _root = _root->next;
    if ( _root != nullptr )
    {
        _root->prev = nullptr;
    }
    delete node;

    return value;
}

template < typename T >
T
List< T >::pop_back( )
{
    if ( _root == nullptr )
    {
        return T( );
    }

    Node* node = _root;

    while ( node->next != nullptr )
    {
        node = node->next;
    }

    T value = node->value;

    if ( node->prev != nullptr )
    {
        node->prev->next = nullptr;
    }
    else
    {
        _root = nullptr;
    }

    delete node;

    return value;
}

template < typename T >
bool
List< T >::remove( size_t index )
{
    Iter it = begin( );
    for ( size_t i = 0; i < index; i++ )
    {
        it.next( );
    }

    Node* current = it._current;
    if ( current == nullptr )
    {
        return false;
    }
    Node* prev = current->prev;
    Node* next = current->next;

    if ( prev != nullptr )
    {
        prev->next = next;
        if ( next != nullptr )
        {
            next->prev = prev;
        }
    }
    else
    {
        _root = next;
        next->prev = nullptr;
    }

    delete it._current;
    return true;
}

template < typename T >
bool
List< T >::insert( size_t index, T value )
{
    Node* node = new Node( value );

    if ( index == 0 )
    {
        node->next = _root;
        _root = node;
        return true;
    }

    Node* pos = _root;
    for ( size_t i = 1; i < index; i++ )
    {
        if ( pos == nullptr )
        {
            return false;
        }
        pos = pos->next;
    }

    pos->next = node;
    node->prev = pos;
}

template < typename T >
size_t
List< T >::count( )
{
    size_t size = 0;

    Node* node = _root;
    while ( node != nullptr )
    {
        node = node->next;
        size++;
    }

    return size;
}

template < typename T >
bool
List< T >::empty( )
{
    return _root == nullptr;
}

template < typename T >
ListIter< T >
List< T >::begin( )
{
    Iter it;
    it._current = _root;
    return it;
}

template < typename T >
ListIter< T >
List< T >::end( )
{
    return Iter( );
}

template < typename T >
void
List< T >::print( )
{
    Node* node = _root;

    while ( node != nullptr )
    {
        std::cout << node->value << " ";
        node = node->next;
    }

    std::cout << std::endl;
}

#endif  // LIST_H
