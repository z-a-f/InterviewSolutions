#include <iostream>

#include "../../LinkedList.hpp"

using namespace std;

/** Insertion sort helper
 *
 * @tparams T
 * @param Node<T>*head Head of the sorted list
 * @param Node<T>*node Node to be inserted
 * @return Node<T>* List with the node inserted
 */
template <typename T>
static Node<T>* sorted_insert(Node<T>* head, Node<T>* node) {
  if (node == nullptr) {
	return head;
  }

  if (head == nullptr || node->value() <= head->value()) {
	node->setNext(head);
	return node;
  }

  Node<T>* curr = head;

  while (curr->next() != nullptr && curr->next()->value() < node->value()) {
	curr = curr->next();
  }
  node->setNext(curr->next());
  curr->setNext(node);

  return head;
}

/** Sort the linked list (destructive, buggy)
 *
 * @tparams T
 * @params Node<T>* the head of the linked list to be sorted
 * @returns Node<T>* the head of the new linked list
 */
template <typename T>
Node<T>* insertion_sort(Node<T>* head) {
  Node<T>* sorted = nullptr;
  Node<T>* curr = head;

  // DEBUG(curr, sorted);
  while (curr != nullptr) {
	Node<T>* temp = curr->next();
	sorted = sorted_insert(sorted, curr);
	curr = temp;
	// DEBUG(curr, sorted);
  }
  delete curr;
  return sorted;
}

template<typename T>
void DEBUG(Node<T>*orig, Node<T>* sort) {
  Node<T>* ptr = orig;
  std::cout << "(orig)->";
  while (ptr != nullptr) {
	std::cout << "[" << ptr->value() << "]->";
	ptr = ptr->next();
  }
  std::cout << "(NULL)\n";
  ptr = sort;
  std::cout << "(sort)->";
  while (ptr != nullptr) {
	std::cout << "[" << ptr->value() << "]->";
	ptr = ptr->next();
  }
  std::cout << "(NULL)\n";
  delete ptr;
}

int main() {
  Node<int>* list = new Node<int>(11);

  Node<int>* sort;

  sort = new Node<int>(82);
  sort->setNext(list);
  list = sort;

  sort = new Node<int>(23);
  sort->setNext(list);
  list = sort;

  sort = new Node<int>(29);
  sort->setNext(list);
  list = sort;

  sort = nullptr;
  DEBUG(list, sort);

  sort = insertion_sort(list);
  DEBUG(list, sort);
  

  
  /*LinkedList<int> list;
  list.addFront(11);
  list.addFront(82);
  list.addFront(23);
  list.addFront(29);
  cout << list << endl;

  cout << "\n *********** \n";
  LinkedList<int> sorted;
  sorted.setHead(insertion_sort(list.head()));
  cout << "\n *********** \n";
  
  cout << list << endl;

  cout << sorted << endl;
  */
  return 0;
}
