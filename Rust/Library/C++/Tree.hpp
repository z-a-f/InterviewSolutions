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


////////////////////////////////////////////////
// This is a binary search tree:
/** Binary search tree */
template <typename T>
class BST {
public:
    class Node {
    private:
        T _val;                 //!< Value of the node
        Node* _parent;          //!< Parent of the node
        Node* _left;            //!< Left child
        Node* _right;           //!< Right child
    public:
        /** Constructor */
        Node(T e = 0, Node* p = nullptr) :
            _val(e), _parent(p),
            _left(nullptr), _right(nullptr) {}
        Node(Node* p);
        /* Destructor */
        // ~Node();
        friend class BST;
    public:
        /** Return parent */
        Node* parent() { return this->_parent; }
        // The whole thing is accessible through
        // either children(idx) or
        // children()[idx]
        // std::list<Node*> children();
        // Node* children (int idx);
        // Node* child(int idx);   // This is the same as children(idx)
        Node* left() { return _left; }
        Node* right() { return _right; }
        void left(Node* ptr) { _left = ptr; }
        void right(Node* ptr) { _right = ptr; }
        T value() { return this->_val; }
        void value(T e) { this->_val = e; }
        void expandExternal();
        /** Is it the root node? */
        bool isRoot() { return _parent == nullptr; }
        bool isExternal();
    private: // Utilities:
        void deleteChildren(Node* n);
        
    };
public:
    BST(Node* r = nullptr, std::size_t n = 0) : _root(r), _n(n) {}
    ~BST() { BST<T>::Node().deleteChildren(_root); }
public:
    /** Add empty root if it doesn't exist */
    bool addRoot(T v = 0) {
        if (empty()) {
            _root = new Node(v);
            _n = 1;
            return true;
        }
        return false;
    }
    void addValue(T v);
    /** Is the tree empty? */
    bool empty() const { return _n == 0; }
    /** Get the root */
    Node* root() const{ return this->_root; }
    /** Get the size */
    std::size_t size() { return _n; }
private:
    Node* _root;
    std::size_t _n;
};

/** Construct from another node */
template <typename T>
BST<T>::Node::Node(Node* p) {
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
void BST<T>::Node::deleteChildren(BST::Node *n) {
    if (n != nullptr) {
        deleteChildren(_left);
        deleteChildren(_right);
        delete n;
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
    Node* ptr = root();
    Node* ptr_p = nullptr;
    while (ptr != nullptr) {
        ptr_p = ptr;
        if (v <= ptr->value()) ptr = ptr->left();
        else ptr = ptr->right();
    }
    // At this point ptr is the place where we have to be,
    // and the ptr_p is the parent place
    ptr = new Node(v, ptr_p);
    if (v <= ptr_p->value()) ptr_p->left(ptr);
    else ptr_p->right(ptr);
    _n++;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const BST<T>& t) {
    
    BST<T> temp = t;
    if (t.empty()) return os;
    os << BST<T>(t.root()->left());
    os << temp.root()->value();
    os << BST<T>(t.root()->right());

    return os;
    /*
      if (node == nullptr) return
      inorder(node->left())
      visit(node)
      inorder(node->right())
     */
}
