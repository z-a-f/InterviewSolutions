#include <iostream>

#include "../../../Library/C++/LinkedList.hpp"

template <typename T> using pNode = std::shared_ptr< Node<T> >; // This is just for convenience
using namespace std;

/** Find the n-th node from the end of the singly linked list
 *
 * @param pNode<T> head of the original linked list (std::shared_ptr<Node<T>>)
 * @param int n
 * @returns pNode<T> node we are looking for or nullptr (std::shared_ptr<Node<T>>)
 */
template <typename T>
pNode<T> nth_from_last(pNode<T> head, int n) {
    pNode<T> second = head; // This is the head
    if (second == nullptr || n < 1) return nullptr;

    // The first pointer will be n-nodes forward
    pNode<T> first = head; // This is the tail

    while (first != nullptr && n > 0) {
        first = first->next();
        --n;
    }

    // Check if out-of-bounds
    if (n != 0) return nullptr;

    // When first pointer reaches the end of the list, second is pointing at n-th node
    while (first != nullptr) {
        first = first->next();
        second = second->next();
    }

    return second;
}

int main() {
    LinkedList<int> list;

    pNode<int> found;
    
    // Check on empty list first
    found = nth_from_last(list.head(), 1);
    if (found != nullptr) cout << "Something went wrong!\n";
    else cout << "Empty lists work!\n";
    
    list.addFront(9);
    list.addFront(28);
    list.addFront(21);
    list.addFront(14);
    list.addFront(7);

    // Check on a BIG n:
    found = nth_from_last(list.head(), 100);
    if (found != nullptr) cout << "Something went wrong!\n";
    else cout << "BIG n's work!\n";

    found = nth_from_last(list.head(), 3);
    if (found != nullptr) cout << "n = 3 value: " << found->value() << endl;
    else cout << "Something went wrong!\n";

    // Make sure the list is still intact:
    cout << list<< endl;
    
    return 0;
}
