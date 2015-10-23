#pragma once

#include <iostream>             // Need that for ostream
#include <list>

/** This is a binary search tree ADT */

template <typename T>
class BST {
protected:
    // Node structure:
    struct Node {
        T elt;
        Node* parent;
        Node* left;
        Node* right;
        Node(T e = 0) : elt(e), par(nullptr), left(nullptr), right(nullptr) {}
    };
public:
    class Position {
    private:
        Node* v;
    public:
        Position(Node* _v = nullptr) : v(_v) {}
        T& operator*() { return v->elt; }
        Position left() const { return Position(v->left); }
        Position right() const { return Position(v->right); }
        Position parent() const { return Position(v->parent); }
        bool isRoot() const { return v->parent == nullptr; }
        bool isExternal() const{
            return v->left == nullptr && v->right == nullptr;
        }
        friend class BST;
    };
    typedef std::list<Position> PositionList;
public:
    BST();
    int size() const;
    bool empty() const;
    Position root() const;
    PositionList positions() const;
    void addRoot();
    void expandExternal(const Position& p);
    Position removeAboveExternal(const Position& p);
    // TODO: housekeeping
protected:
    void preorder(Node* v, PositionList& pl) const; // utility
private:
    Node* _root;
    int n;
};


template <typename T>
BST<T>::BST() : _root (nullptr), n(0) {}

template <typename T>
int BST<T>::size() const { return n; }

template <typename T>
bool BST<T>::empty() const { return size() == 0; }

template <typename T>
typename BST<T>::Position BST<T>::root() const {
    return Position(_root);
}

template <typename T>
void BST<T>::addRoot() {
    _root = new Node; n = 1;
}

// Update functions 
