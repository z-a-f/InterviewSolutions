# include <iostream>

#include "../../../Library/C++/LinkedList.hpp"

template <typename T> using pNode = std::shared_ptr< Node<T> >;
using namespace std;

/** Delete a node with key `key` from the linked list
 *
 * @returns pNode<T> The head of the new linked list (std::shared_ptr< Node<T> >)
 * @param pNode<T> The head of the linked list to search for `key` (std::shared_ptr< Node<T> >)
 */
template <typename T>
pNode<T> delete_key (pNode<T> head, T key) {
  pNode<T> prev = nullptr;
  pNode<T> current = head;

  while (current != nullptr) {
	if (current->value() == key) {
	  break;					// Found it! :)
	}

	prev = current;
	current = current->next();
  }
  
  if (current == nullptr) {
	return head;				// Didn't find it :(
  }

  if (current == head) {
	head = head->next();
  } else {
	prev->setNext(current->next());
  }

  // delete current;
  return head;
}

int main() {
  LinkedList<int> list;
  cout << list << endl;

  list.addFront(22);
  list.addFront(55);
  list.addFront(10);
  list.addFront(70);
  cout << list << endl;

  list.setHead(delete_key(list.head(), 55));
  cout << list << endl;

  list.setHead(delete_key(list.head(), 70));
  cout << list << endl;

  list.setHead(delete_key(list.head(), 0));
  cout << list << endl;

  list.setHead(delete_key(list.head(), 22));
  cout << list << endl;
  
  return 0;
}
