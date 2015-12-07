#pragma once

#include <list>

/* This is a generic tree class
 *
 * Children of a node would be accessible
 * through std::list<pNode> children(), where
 * pNode = std::shared_ptr<Node> or
 * pNode = Node*
 *
 * @tparam T template parameter describing the value data type
 */
template <typename T>
class Tree {
public:
    /* Declare the internal classes */
    /** Node class */
    class Node {
    private:
        T _val;                 //!< Value of the node
        Node* _parent;          //!< Parent of the node
        std::list<Node*> _children; //!< Childrent of the node
    public:
        /** Constructor */
        Node(T e = 0, Node* p = nullptr) : _val(e), _parent(p) {}
        /* Destructor */
        // ~Node();
        friend class Tree;
    public:
        Node* parent() { return _parent; };
        // The whole thing is accessible through
        // either children(idx) or
        // children()[idx]
        std::list<Node*> children();
        Node* children (int idx);
        Node* child(int idx);   // This is the same as children(idx)
        T value();
        void value(T e);
        /** Is it the root node? */
        bool isRoot() { return _parent == nullptr; }
        bool isExternal();
    private: // Utilities:
        void deleteChildren(Node* n);
    };

public:
    /** Constructor */
    Tree() : _root(nullptr), _n(0) {}
    /** Destructor */
    ~Tree() { this->_root->deleteChildren(_root); }
    /** Size of the  tree */
    int size() { return this->_n; }
    /** Is the tree empty? */
    bool empty() { return this->size() == 0; }
    /** Get the root of the tree */
    Node* root() { return const_cast<Tree<T>*>(this)->_root; }
    /** Add root */
    void addRoot() { _root = new Node; _n = 1; }
private:
    Node* _root;
    int _n;
};

/** Delete all children */
template <typename T>
void Tree<T>::Node::deleteChildren(Tree::Node *n){
    if (n != nullptr) {
        std::list<Node*> temp = n->children();
        if (!temp.empty() )
            for (typename std::list<Node*>::iterator idx = temp.begin();
                 idx != temp.end(); ++idx) {
                deleteChildren(*idx);
            }
        delete(n);
    }
}

/** Is the node external? */
template <typename T>
bool Tree<T>::Node::isExternal() {
    if (this->children().empty()) return true;
    for (typename std::list<typename Tree<T>::Node*>
             ::iterator idx = this->children().begin();
         idx != this->children().end();
         ++idx) {
        if (*idx != nullptr) return false;
    }
    return true;
}
/*
  template <typename T>
  Tree<T>::Node::~Node() {
  deleteChildren(this);
  }
*/

/** Get the list of children */
template <typename T>
typename std::list<typename Tree<T>::Node*> Tree<T>::Node::children() {
    return this->_children;
}

/** Get child idx*/
template <typename T>
typename Tree<T>::Node* Tree<T>::Node::children(int idx) {
    return this->children()[idx];
}

/** Get child idx */
template <typename T>
typename Tree<T>::Node* Tree<T>::Node::child(int idx) {
    return this->children(idx);
}

/** Value setter */
template <typename T>
void Tree<T>::Node::value(T e) {
    this->_val = e;
}

/** value getter */
template <typename T>
T Tree<T>::Node::value() {
    return this->_val;
}
