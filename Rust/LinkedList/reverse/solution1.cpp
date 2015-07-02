# include <iostream>

#include "../LinkedList.hpp"

using namespace std;

/** Reverse a singly linked list
 *
 * @returns Node<T>* The head of the reversed linked list
 * @param Node<T>* The head of the linked list to be reversed
 */
template <typename T>
Node<T>* reverse_iterative (Node<T>* head) {
  // If the size of the linked list = 0 or 1, nothing to do :)
  if (head == nullptr || head->next() == nullptr)
	return head;

  Node<T>* list_to_do = head->next();
  Node<T>* reversed_list = head;
  reversed_list->setNext(nullptr);

  while (list_to_do != nullptr) {
	Node<T>* temp = list_to_do;
	list_to_do = list_to_do->next();

	temp->setNext(reversed_list);
	reversed_list = temp;
  }
  delete list_to_do;
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

  list.setHead(reverse_iterative(list.head()));
  cout << list << endl;
  
  return 0;
}
