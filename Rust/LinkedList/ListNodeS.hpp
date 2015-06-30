#pragma once

#include <iostream>

/*********************************************************************/
/* Singly Node class */
template <typename T>
class ListNodeS {
public:
  ListNodeS();
  ListNodeS(const T &value, ListNodeS<T> *next = nullptr);
  ~ListNodeS();
public:
  // Getters:
  ListNodeS<T>* next();
  T value();
  // Setters:
  void set(T, ListNodeS<T>*);
  void setNext(ListNodeS<T>*);
  void setValue(T);
public:
  // Friends:
  friend inline std::ostream& operator<<(std::ostream& os,
										 ListNodeS<T> const& node){
	os << node.value();
	return os;
  }
private:
  T _value;
  ListNodeS<T> *_next;
};

// Constructors/Destructors
template <typename T> ListNodeS<T>::ListNodeS() {
  this->_next = nullptr;
  this->_value = 0;
}
template <typename T>
ListNodeS<T>::ListNodeS(const T &value, ListNodeS<T> *next) {
  this->_value = value;
  this->_next = next;
}
template <typename T> ListNodeS<T>::~ListNodeS() { /*delete this->_next;*/ }

// Getters:
template <typename T>
typename ListNodeS<T>::ListNodeS* ListNodeS<T>::next() {
  return this->_next;
}
template <typename T> T ListNodeS<T>::value() { return this->_value; }

// Setters:
template <typename T>
void ListNodeS<T>::setNext(ListNodeS<T>::ListNodeS<T>* next) {
  this->_next = next;
}
template <typename T>
void ListNodeS<T>::setValue(T value) {
  this->_value = value;
}
template <typename T>
void ListNodeS<T>::set(T value, ListNodeS<T>* next) {
  this->setNext(next);
  this->setValue(value);
}
