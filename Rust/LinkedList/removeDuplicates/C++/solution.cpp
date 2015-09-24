#include <iostream>
#include <unordered_set>

#include "../../../Library/C++/LinkedList.hpp"

template <typename T> using pNode = std::shared_ptr< Node<T> >; // This is just for convenience
using namespace std;

/** Find the duplicates in a linked list and return its head
 *
 * @param pNode<T> head of the original linked list (std::shared_ptr<Node<T>>)
 * @returns pNode<T> node we are looking for or nullptr (std::shared_ptr<Node<T>>)
 */
template <typename T>
pNode<T> removeDuplicates(pNode<T> head) {
    if (head == nullptr) return head;

    std::unordered_set<int> dup_set;
    pNode<T> curr = head;
    // std::weak_ptr< Node<T> > curr = head;
    dup_set.insert(curr->value());

    while (curr->next() != nullptr) {
        if (dup_set.find(curr->next()->value()) == dup_set.end()) {
            // Element not found in the map, add it to the map
            dup_set.insert(curr->next()->value());
            curr = curr->next();
        } else {
            // Duplicate found, delete the node
            std::weak_ptr< Node<T> > temp = curr->next();
            curr->setNext(curr->next()->next());
        }
    }
    return head;
}

int main() {
    LinkedList<int> list;
    list.addFront(7);
    list.addFront(4);
    list.addFront(9);
    list.addFront(4);
    list.addFront(7);
    list.addFront(4);

    cout << list << endl;
    list.setHead(removeDuplicates(list.head()));
    cout << list << endl;
    
    return 0;
}
