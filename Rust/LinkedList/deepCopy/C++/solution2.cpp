#include <iostream>
#include <unordered_map>

#include "../../Library/C++/LinkedList.hpp"

template <typename T> using pNode = std::shared_ptr< Node<T> >;
using namespace std;

/** Deep copy a singly linked list with arbitrary pointers
 *
 * @tparams T
 * @params pNode<T> the head of the linked list to be copied (std::shred_ptr< Node<T> >)
 * @returns pNode<T> the head of the new linked list (std::shred_ptr< Node<T> >)
 */
template <typename T>
pNode<T> deep_copy_arbitrary_pointer (pNode<T> head) {
    // If the linked list is empty, return
    if (head == nullptr) {
	return nullptr;
    }

    pNode<T> current = head;

    // Inserting new nodes within the existing linked list
    while (current != nullptr) {
        pNode<T> new_node = pNode<T>(new Node<T>(current->value()));
	new_node->setNext(current->next());
	current->setNext(new_node);
	current = new_node->next();
    }

    // Setting correct arbitrary pointers
    current = head;
    while (current != nullptr) {
	if (current->arb() != nullptr) {
            current->next()->setArb(current->arb()->next());
	}
	current = current->next()->next();
    }

    // Separating lists
    current = head;
    pNode<T> new_head = head->next();
    pNode<T> copied_current = nullptr;

    while (current != nullptr) {
	copied_current = current->next();
	current->setNext(copied_current->next());

	if (copied_current->next() != nullptr) {
            copied_current->setNext(copied_current->next()->next());
	}

	current = current->next();
    }
    return new_head;
}

int main() {
    LinkedList<int> listArb;
    listArb.addFront(21);
    listArb.addFront(14);
    listArb.addFront(7);
    listArb.head()->setArb(listArb.head()->next()->next());
    listArb.head()->next()->next()->setArb(listArb.head());
    cout << listArb << endl;

    LinkedList<int> listArbCopy;
    listArbCopy.setHead(deep_copy_arbitrary_pointer(listArb.head()));

    // Change some stuff to check if the linked lists are really separate
    listArbCopy.head()->next()->setValue(123);
    listArb.head()->setValue(321);
  
    cout << listArbCopy << endl;
    cout << listArb << endl;
  
    return 0;
}
