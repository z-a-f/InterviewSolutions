# include <iostream>

#include "../../../Library/C++/LinkedList.hpp"

template <typename T> using pNode = std::shared_ptr< Node<T> >;
using namespace std;

/** Reverse a singly linked list
 *
 * @returns pNode<T> The head of the reversed linked list
 * @param pNode<T> The head of the linked list to be reversed
 */
template <typename T>
pNode<T> reverse_iterative (pNode<T> head) {
  // If the size of the linked list = 0 or 1, nothing to do :)
  if (head == nullptr || head->next() == nullptr)
	return head;

  pNode<T> list_to_do = head->next();
  pNode<T> reversed_list = head;
  reversed_list->setNext(nullptr);

  while (list_to_do != nullptr) {
	pNode<T> temp = list_to_do;
	list_to_do = list_to_do->next();

	temp->setNext(reversed_list);
	reversed_list = temp;
  }
  // delete list_to_do;
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
