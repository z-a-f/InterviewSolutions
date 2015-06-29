#pragma once

#include <iostream>
#include "ListNodeS.hpp"

/*********************************************************************/
/* Singly linked list */
template <typename T>
class LinkedListS {
public:
  // Constructors/Destructors
  LinkedListS();
  LinkedListS(ListNodeS<T>* head) : _head(head) {};
  ~LinkedListS();
public:
  // Housekeeping
  ListNodeS<T>* head() { return this->_head; }
public:
  // Friends:
  friend inline std::ostream& operator<<(
										 std::ostream& os,
										 LinkedListS<T> list){
	ListNodeS<T> *ptr = list.head();
	os << "HEAD->";
	while (ptr->next() != nullptr) {
	  ptr = ptr->next();
	  os << ptr->value() << "->";
	}
	os << "NULL";
	return os;
  }
private:
  ListNodeS<T> *_head;
};

// Constructors/Destructors
template <typename T>
LinkedListS<T>::LinkedListS() {
  this->_head = nullptr;
}
template <typename T>
LinkedListS<T>::~LinkedListS() {}


