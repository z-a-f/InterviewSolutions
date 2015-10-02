#pragma once

#include <iostream>             // For the std::ostream
#include <vector>               // For array of children

template <typename T> class TreeNode;
template <typename T> using treeNode = std::shared_ptr< TreeNode<T> >; // This is just for convenience

/** Gneric Tree Node class
 *
 * The implementation of the class is a little weird:
 * children are stored in a vector of pointers to TreeNodeN
 * objects
 */
template <typename T>
class TreeNode {
public:
    /** Constructor */
    TreeNode (std::size_t N = 0, T e = T(0)) {
        _children = std::vector< treeNode<T> >(N, nullptr);
        _elem = e;
    };

    /** Get value */
    T get() { return _elem; }

    /** Set value */
    void set(T e) { _elem = e; }

    /** Get child */
    treeNode<T> child(std::size_t idx) { return this->_children[idx];}

    /** Set child */
    void child(std::size_t idx, T e) {
        this->_children[idx] = new TreeNode<T>();
        // this->_childrem[idx]->
    }

    /** Overload operator= */
    /*
    void operator=(treeNode<T> tn) {
        if (this == tn) return;
        this = tn;
        }*/
        
private:
    std::vector< treeNode<T> > _children;
    T _elem;
};
