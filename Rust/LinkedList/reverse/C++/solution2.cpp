# include <iostream>

#include "../../LinkedList.hpp"

using namespace std;

/** Reverse a singly linked list (Recursive)
 *
 * @returns Node<T>* The head of the reversed linked list
 * @param Node<T>* The head of the linked list to be reversed
 */
template <typename T>
Node<T>* reverse_recursive (Node<T>* head) {
  // If the size of the linked list = 0 or 1, nothing to do :)
  if (head == nullptr || head->next() == nullptr)
	return head;

  Node<T>* reversed_list = reverse_recursive(head->next());

  head->next()->setNext(head);
  head->setNext(nullptr);
  return reversed_list;
}

int main() {
  LinkedList<int> list;
  cout << list << endl;

  list.addFront(28);
  list.addFront(21);
  list.addFront(14);
  list.addFront(7);
  cout << list << endl;

  list.setHead(reverse_recursive(list.head()));
  cout << list << endl;
  
  return 0;
}
