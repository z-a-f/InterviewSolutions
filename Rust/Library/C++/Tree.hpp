#pragma once

#include <iostream>             // For the std::ostream
#include <list>                 // For array of children

template <typename T>
class Tree {
protected:
    struct Node {
        T elt;                       // element value
        std::shared_ptr<Node> par;   // parent
        std::shared_ptr<Node> left;  // left
        std::shared_ptr<Node> right; // right child
        Node(T e = 0) : elt(e), par(nullptr), left(nullptr), right(nullptr) {} // Constructor
    };
    typedef std::shared_ptr<Node> pNode;
public:
    class Position {
    private:
        pNode v;                // Pointer of the node
    public:
        Position(pNode _v = NULL) : v(_v) {} // Constructor
        T& operator*() { return v->elt; }    // Get element
        Position left() const                // Get left children
        { return Position(v->left); }        // 
        Position right() const               // Get right child
        { return Position(v->right); }       // 
        Position parent() const              // Get parent
        { return Position(v->par); }         // 
        bool isRoot() const                  // Is it root?
        { return v->par == nullptr; }        //
        bool isExternal() const              //
        { return v->left == nullptr &&       // 
                v->right == nullptr; }       // Is it external?
        friend class Tree;                    // Give tree access
    };
    typedef std::list<Position> PositionList; // List of positions
public:
    Tree();
    int size() const;
    bool empty() const;
    Position root() const;
    PositionList positions() const;
    void addRoot();
    void expandExternal(const Position& p);
    Position removeAboveExternal(const Position& p);
    // TODO: HOUSEKEEPING FUNCTIONS!
    /*
      1. Copy constructor
      2. Assignment operator
      3. Destructor
      4. Operator<<
     */
protected:
    void preorder(pNode v, PositionList& pl) const;
private:
    pNode _root;                // Root of the tree
    int n;                      // Size
    
};


template <typename T>
Tree<T>::Tree() : _root(nullptr), n(0) {} // Constructor

template <typename T>
int Tree<T>::size() const { return n; } // number of nodes

template <typename T>
bool Tree<T>::empty() const { return size() == 0; } // is tree empty

template <typename T>
typename Tree<T>::Position Tree<T>::root() const // Get the root
{ return Position(_root); }

template <typename T>
void Tree<T>::addRoot()          // Add root to empty tree
{ _root = pNode(); n = 1; }

