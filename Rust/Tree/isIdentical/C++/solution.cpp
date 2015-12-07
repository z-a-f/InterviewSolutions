# include <iostream>

#include "../../../Library/C++/Tree.hpp"

using namespace std;

template <typename T>
bool is_identical(
    std::shared_ptr<typename BST<T>::Node> root1,
    std::shared_ptr<typename BST<T>::Node> root2) {
    if (root1 == nullptr && root2 == nullptr) return true;

    if (root1 != nullptr && root2 != nullptr) {
        return ((root1->value() == root2->value())
                && is_identical<T>(root1->left(), root2->left())
                && is_identical<T>(root1->right(), root2->right()));
    }

    return false;
}

template <typename T>
bool is_identical(typename BST<T>::Node* root1, typename BST<T>::Node* root2) {
    return is_identical<T>(
        std::shared_ptr<typename BST<T>::Node>(root1),
        std::shared_ptr<typename BST<T>::Node>(root2));
}


template <typename T>
bool is_identical(BST<T> t1, BST<T> t2) {
    return is_identical<T>(t1.root(), t2.root());
}

int main() {
    BST<int> myTree1;
    BST<int> myTree2;
    BST<int> myTree3;
    
    myTree1.addValue(50);
    myTree1.addValue(30);
    myTree1.addValue(40);
    
    myTree2.addValue(50);
    myTree2.addValue(40);
    myTree2.addValue(30);

    myTree3.addValue(50);
    myTree3.addValue(30);
    myTree3.addValue(40);
    
    
    cout << "Tree 1: " << myTree1 << endl;
    cout << "Tree 2: " << myTree2 << endl;
    cout << "Trees 1 and 2 are identical: " << is_identical<int>(myTree1, myTree2);
    cout << endl;
    cout << "Trees 1 and 3 are identical: " << is_identical<int>(myTree1, myTree3);
    cout << endl;
    // cout << myTree1.root()->left()->right()->value() << endl;
    return 0;
}
