
#include <iostream>
using namespace std;


#include <vector>



template <typename T>
class TreeNode {
public:
    TreeNode(T e = 0,
             TreeNode<T>* p = nullptr,
             std::vector< TreeNode<T>* > vec = std::vector< TreeNode<T>* >(0, nullptr)
        ) : _elem(e), _parent(p), _child(vec) {}
    void set(T e) { this->_elem = e; }
    T get() { return this->_elem; }
    TreeNode<T>* parent() { return _parent; }
    void addChild(TreeNode<T> node);
    void addChild(TreeNode<T>* node);
    void addChild(T e);
    void removeChild(std::size_t idx);
    void removeChild(typename std::vector<T>::iterator it);
private:
    T _elem;
    TreeNode<T>* _parent;
    std::vector< TreeNode<T>* > _child;
};

template <typename T>
void TreeNode<T>::addChild(TreeNode<T> node) {
    this->addChild(&node);
}

template <typename T>
void TreeNode<T>::addChild(TreeNode<T> *node) {
    this->_child.push_back(node);
}

template <typename T>
void TreeNode<T>::addChild(T e) {
    this->_child.push_back(new TreeNode<T>);
    this->_child.end()->set(e);
}

template <typename T>
void TreeNode<T>::removeChild(typename std::vector<T>::iterator it) {
    this->_child.erase(it);
}

template <typename T>
void TreeNode<T>::removeChild(std::size_t idx) {
    this->_child.erase(this->_child.begin() + idx);
}



template <typename T>
class Tree {
public:
    TreeNode<T>* root() { return this->_root; }
    
private:
    TreeNode<T>* _root;
};

int main() {
    std::vector< TreeNode<int>* > tn;
    tn.push_back(new TreeNode<int>());
    tn[0]->set(12);
    cout << tn[0]->get() << endl;
}
