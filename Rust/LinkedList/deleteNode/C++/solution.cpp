# include <iostream>

#include "../../LinkedList.hpp"

using namespace std;

/** Delete a node with key `key` from the linked list
 *
 * @returns Node<T>* The head of the new linked list
 * @param Node<T>* The head of the linked list to search for `key`
 */
template <typename T>
Node<T>* delete_key (Node<T>* head, T key) {
  Node<T>* prev = nullptr;
  Node<T>* current = head;

  while (current != nullptr) {
	if (current->value()
  }
}

int main() {
  LinkedList<int> list;
  cout << list << endl;

  list.addFront(28);
  list.addFront(21);
  list.addFront(14);
  list.addFront(7);
  cout << list << endl;

  list.setHead(reverse_iterative(list.head()));
  cout << list << endl;
  
  return 0;
}
