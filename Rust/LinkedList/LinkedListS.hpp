#pragma once

#include <iostream>
#include "ListNodeS.hpp"

/**
 * Singly linked list
 */
template <typename T>
class LinkedListS {
public:
  // Constructors/Destructors
  LinkedListS();
  LinkedListS(ListNodeS<T>* node); // Adds the first node
  ~LinkedListS();
public:
  // Housekeeping
  ListNodeS<T>* head() { return this->_head; }
  std::size_t size() { return this->_tail->value(); }
  void push(ListNodeS<T>*);
  ListNodeS<T>* pop();
public:
  // Friends:
  friend inline std::ostream& operator<<(std::ostream& os,
										 LinkedListS<T>  list){
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
  ListNodeS<T> *_tail; // Keeps track of the last element
  // Tail value holds the size of the linked list

  void deleteAll(ListNodeS<T>*);
};

// Constructors/Destructors
template <typename T>
LinkedListS<T>::LinkedListS() {
  this->_head = new ListNodeS<T>(0, nullptr);
  this->_tail = new ListNodeS<T>(0, nullptr);
}
template <typename T>
LinkedListS<T>::LinkedListS(ListNodeS<T>* node) {
  this->_head = new ListNodeS<T>(0, nullptr);
  this->_head->setNext(node);
  this->_tail = new ListNodeS<T>(1, this->_head->next());
}
template <typename T>
LinkedListS<T>::~LinkedListS() {
  // delete _tail;
  this->deleteAll(_head);

}
template <typename T>
void LinkedListS<T>::deleteAll(ListNodeS<T>* node) {
  if (node->next() == nullptr){
	delete node;
	return;
  }
  else {
	this->deleteAll(node->next());
  }
}


// Housekeeping
template <typename T>
void LinkedListS<T>::push(ListNodeS<T>* node) {
  this->_tail->next()->setNext(node);
  this->_tail->setNext(node);
  this->_tail->setValue(this->_tail->value() + 1);
}

/* Pop the last element and return its pointer 
 * 
 * @tparam T template data type
 * @returns ListNodeS<T>
 */
template <typename T>
ListNodeS<T>* LinkedListS<T>::pop() {
  if (this->head()->next() == nullptr) return nullptr;
  
  ListNodeS<T> *ptrLast = this->_tail->next();
  ListNodeS<T> *ptr = this->head()->next();
  while (ptr->next() != ptrLast) {
	ptr = ptr->next();
  }
  ptr->setNext(nullptr);
  this->_tail->setNext(ptr);
  this->_tail->setValue(this->_tail->value()-1);
  return ptrLast;
}
