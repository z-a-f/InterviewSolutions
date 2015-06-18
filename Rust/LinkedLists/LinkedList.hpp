#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <iostream>

template <typename T>
class LinkedListNode {
public:
  T data;
  LinkedListNode<T>* next;
  LinkedListNode(T data = 0x0, LinkedListNode<T>* next = NULL)
	: data(data), next(next) {}

  void printChain() {
	LinkedListNode<T> *p = this;
	do {
	  
	  std::cout << p->data << "->";
	  p = p->next;
	} while (p->next != nullptr);
	std::cout << p->data << "->";
	std:: cout << "NULL\n";
  }
};

/*
template <typename T>
LinkedListNode<T>* create_junk_SLL (size_t size) {
  LinkedListNode<T> *head, *first, *p;
  head->next = first;
  
  p = first;
  for (size_t i = 0; i < size; i++) {
	p->next = new LinkedListNode<T>(T(p));
	p = p->next;
  }
  p->next = NULL;

  return head;
}
*/
#endif
