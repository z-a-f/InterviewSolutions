#include <iostream>
#include <unordered_map>

#include "../../LinkedList.hpp"

using namespace std;

/** Deep copy a singly linked list with arbitrary pointers
 *
 * @tparams T
 * @params Node<T>* the head of the linked list to be copied
 * @returns Node<T>* the head of the new linked list
 */
template <typename T>
Node<T>* deep_copy_arbitrary_pointer (Node<T>* head) {
  // If the linked list is empty, return
  if (head == nullptr) {
	return nullptr;
  }

  Node<T>* current = head;
  Node<T>* new_head = nullptr;
  Node<T>* new_prev = nullptr;
  std::unordered_map<Node<T>*, Node<T>*> map;

  // Create copy of the linked list, recording the corresponding
  // nodes in hashmap without updating arbitrary pointer
  while (current != nullptr) {
	Node<T>* new_node = new Node<T>(current->value());

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

  Node<T>* new_current = new_head;

  // Update arbitrary pointer:
  while (new_current != nullptr) {
	if (new_current->arb() != nullptr) {
	  Node<T>* node = map[new_current->arb()];
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
