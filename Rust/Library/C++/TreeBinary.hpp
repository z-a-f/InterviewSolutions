#pragma once

#include <list>

/**
 * @TODO : Need to figure out how std::shared_ptr(*) works
 */

////////////////////////////////////////////////
// This is a binary search tree:
/** Binary search tree */
template <typename T>
class BST {
public:
    class Node {
    private:
        T _val;                 //!< Value of the node
        std::shared_ptr<Node> _parent;          //!< Parent of the node
        std::shared_ptr<Node> _left;            //!< Left child
        std::shared_ptr<Node> _right;           //!< Right child
    public:
        /** Constructor */
        Node(T e = 0, std::shared_ptr<Node> p = nullptr) :
            _val(e), _parent(p),
            _left(nullptr), _right(nullptr) {}
        Node(std::shared_ptr<Node> p);
        /* Destructor */
        // ~Node();
        friend class BST;
    public:
        /** Return parent */
        std::shared_ptr<Node> parent() { return this->_parent; }
        // The whole thing is accessible through
        // either children(idx) or
        // children()[idx]
        // std::list<Node*> children();
        // Node* children (int idx);
        // Node* child(int idx);   // This is the same as children(idx)
        std::shared_ptr<Node> left() { return _left; }
        std::shared_ptr<Node> right() { return _right; }
        void left(std::shared_ptr<Node> ptr) { _left = ptr; }
        void right(std::shared_ptr<Node> ptr) { _right = ptr; }
        T value() { return this->_val; }
        void value(T e) { this->_val = e; }
        void expandExternal();
        /** Is it the root node? */
        bool isRoot() { return _parent == nullptr; }
        bool isExternal();
    private: // Utilities:
        void deleteChildren(std::shared_ptr<Node> n);
        
    };
public:
    BST(std::shared_ptr<Node> r = nullptr, std::size_t n = 0) : _root(r), _n(n) {}
    // ~BST() { BST<T>::Node().deleteChildren(_root); }
public:
    /** Add empty root if it doesn't exist */
    bool addRoot(T v = 0) {
        if (empty()) {
            this->_root = std::shared_ptr<Node>(new Node(v));// new Node(v);
            _n = 1;
            return true;
        }
        return false;
        
        /*if (empty()) {
            this->_root = h;
            _n = 1;
            return true;
        }
        return false;
        */
    }
    void addValue(T v);
    /** Is the tree empty? */
    bool empty() const { return this->_root == nullptr; } // return _n == 0; }
    /** Get the root */
    std::shared_ptr<Node> root() const{ return this->_root; }
    /** Get the size */
    std::size_t size() { return _n; }
private:
    std::shared_ptr<Node> _root;
    std::size_t _n;
};

/** Construct from another node */
template <typename T>
BST<T>::Node::Node(std::shared_ptr<Node> p) {
    _parent = p->_parent;
    _left = p->_left;
    _right = p->_right;
    _val = p->val;
}

/** Check if the node is external */
template <typename T>
bool BST<T>::Node::isExternal() { return _left == nullptr && _right == nullptr; }

/** Delete all the children under n (n included) */
template <typename T>
void BST<T>::Node::deleteChildren(std::shared_ptr<BST::Node> n) {
    if (n != nullptr) {
        deleteChildren(_left);
        deleteChildren(_right);
        // delete n;
        n = nullptr;
    }
}

/** Expand external by creating left and right child */
template <typename T>
void BST<T>::Node::expandExternal() {
    if (isExternal()) {
        _left = BST<T>::Node(0, this);
        _right = BST<T>::Node(0, this);
    }
    
}

/** Add a new value to the tree */
template <typename T>
void BST<T>::addValue(T v) {
    if (addRoot(v)) return; 
    std::shared_ptr<Node> ptr = root();
    std::shared_ptr<Node> ptr_p = nullptr;
    while (ptr != nullptr) {
        ptr_p = ptr;
        if (v <= ptr->value()) ptr = ptr->left();
        else ptr = ptr->right();
    }
    // At this point ptr is the place where we have to be,
    // and the ptr_p is the parent place
    ptr = std::shared_ptr<Node>(new Node(v, ptr_p));
    if (v <= ptr_p->value()) ptr_p->left(ptr);
    else ptr_p->right(ptr);
    _n++;
}

/* In order traversal print */
template <typename T>
std::ostream& operator<<(std::ostream& os, const BST<T>& t) {
    
    BST<T> temp = t;
    if (t.empty()) {
        // std::cout << "Empty\n";
        return os;
    }
    if (t.root()->left() != nullptr) {
        os << BST<T>(t.root()->left());
    }
    /*
    if (t.root()->left() == nullptr) {
        os << t.root()->value() << ' ';
        return os;
    } else {
        os << BST<T>(t.root()->left());
    }
    */
    // os << " ";
    os << temp.root()->value() << ' ';
    // os << " ";
    if (t.root()->right() != nullptr) {
        // os << t.root()->value() << ' ';
        // return os;
        os << BST<T>(t.root()->right());
    } /*else {
        os << BST<T>(t.root()->right());
        }*/

    return os;
    /*
      if (node == nullptr) return
      inorder(node->left())
      visit(node)
      inorder(node->right())
    */
}
