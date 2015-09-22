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
    pNode<T> new_head = nullptr;
    pNode<T> new_prev = nullptr;
    std::unordered_map<pNode<T>, pNode<T>> map;

    // Create copy of the linked list, recording the corresponding
    // nodes in hashmap without updating arbitrary pointer
    while (current != nullptr) {
        pNode<T> new_node = pNode<T>(new Node<T>(current->value()));

	// Copy the old arbitrary pointer in the new node
	new_node->setArb(current->arb());

	if (new_prev != nullptr) {
            new_prev->setNext(new_node);
	} else {
            new_head = new_node;
	}

	map[current] = new_node;
	new_prev = new_node;
	current = current->next();
    }

    pNode<T> new_current = new_head;

    // Update arbitrary pointer:
    while (new_current != nullptr) {
	if (new_current->arb() != nullptr) {
            pNode<T> node = map[new_current->arb()];
            new_current->setArb(node);
	}
	new_current = new_current->next();
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
