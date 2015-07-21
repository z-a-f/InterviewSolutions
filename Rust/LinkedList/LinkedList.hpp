#pragma once

#include <exception>

template <typename T> class LinkedList;
class Int;
template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);
std::ostream& operator<<(std::ostream& os, const Int& num);


/** Node class
 * 
 * @tparam T template type
 */
template <typename T>
class Node {
public:
  /** Constructor */
  Node(T e = T(0)) : _elem(e), _next(nullptr), _arb(nullptr) {}
  // ~Node() { delete _next; }
public:
  // Getters/Setters:
  /** Return the value in the node
   *
   * @returns T value
   */  
  const T& value() const { return this->_elem; }
  /** Return the next node
   *
   * @returns Node<T>*
   */
  Node<T>* next() const { return this->_next; }
  /** Return the arbitrary node
   *
   * @returns Node<T>*
   */
  Node<T>* arb() const { return this->_arb; }
  /** Set the value in the node
   *
   * @param T value
   */
  void setValue(const T& e) { this->_elem = e; }
  /** Set the next pointer
   *
   * @param Node<T>* the next "next" pointer
   */
  void setNext(Node<T>* n) { this->_next = n; }
  /** Set the arbitrary pointer
   *
   * @param Node<T>* the next "arb" pointer
   */
  void setArb(Node<T>* n) { this->_arb = n; }
private:
  T _elem;						//!< Stored value
  Node<T>* _next;				//!< Next element
  Node<T>* _arb;				//!< Arbitrary element

  friend class LinkedList<T>;	//!< Friend class
};

  
/** Singly Linked List
 *
 * @tparam T template type
 */
template <typename T>
class LinkedList {
public:
  LinkedList();
  ~LinkedList();
public:
  bool empty() const;
  const T& front() const throw(std::range_error);
  void addFront(const T& e);
  void removeFront();
public:
  // Housekeeping
  std::size_t size() const;
  Node<T>* head();
  void setHead(Node<T>* h);		// This is dangerous!!!
  // template <typename U>
  // friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list);
  Node<T>* operator[](std::size_t idx);
  friend std::ostream& operator<<<>(std::ostream& os, const LinkedList& list);
  // std::ostream& printArb();
private:
  Node<T>* _head;
  std::size_t _size;

  // Rust solutions after this point
public:
  void reverse();
  void reverseRecursive();
  void deleteKey (T key);
private:
  Node<T>* _reverse_recursive(Node<T>* node);
};

/** Constructor */
template <typename T>
LinkedList<T>::LinkedList() : _head(nullptr), _size(0) {}

/** Destructor */
template <typename T>
LinkedList<T>::~LinkedList() {
  while (!empty()) removeFront();
  // delete _head;
}

/** Empty?
 *
 * @returns bool True if empty
 */
template <typename T>
bool LinkedList<T>::empty() const {
  return _head == nullptr;
}

/** Get front element (read-only)
 *
 * @returns T
 */
template <typename T>
const T& LinkedList<T>::front() const
  throw (std::range_error) {
  if (empty()) {
	throw std::range_error("Linked List empty! Cannot get front()");
	// return 0;
  }
  return _head->_elem;
}

/** Add element in the front of the list
 * 
 * @param e Element to be added
 */
template <typename T>
void LinkedList<T>::addFront(const T& e) {
  Node<T>* v = new Node<T>;
  v->_elem = e;
  v->_next = _head;
  _head = v;
  _size++;
}

/** Remove the first element 
 *
 */
template <typename T>
void LinkedList<T>::removeFront() {
  if (this->empty()) return;
  Node<T>* old = _head;
  _head = old->_next;
  _size--;
  delete old;
}

/** Number of elements in the list
 * 
 * @returns std::size_t Number of elements in the list
 */
template <typename T>
std::size_t LinkedList<T>::size() const {
  return this->_size;
}

/** Returns the head of the linked list
 *
 * @returns Node<T>* the head of the current linked list
 */
template <typename T>
Node<T>* LinkedList<T>::head() { return this->_head; }

/** Set the head to different node
 *
 * NOTE: this method is dangerous as it will lose information
 * about other nodes!!!
 *
 * @params Node<T>* the node to be set as head
 */
template <typename T>
void LinkedList<T>::setHead(Node<T>* h) {
  this->_head = h;
}


/** Operator<< for the linked list
 *
 * @returns std::ostream
 * @param LHS->std::ostream
 * @param RHS->LinkedList<T>
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
  /*
  os << "HEAD->";
  Node<T>* ptr = list._head;
  while (ptr != nullptr) {
	os << ptr->_elem << "->";
	ptr = ptr->_next;
  }
  os << "NULL";
  delete ptr;
  return os;
  */

  os << "[HEAD]\n V\n";
  Node<T>* ptr = list._head;
  while (ptr != nullptr) {
	os << "[" << ptr->_elem << "]->";
	os << "[";// << ( (ptr->arb() == nullptr) ? "NULL" : ptr->arb()->_elem) << "]\n V";
	if (ptr->arb() == nullptr)
	  os << "NULL";
	else
	  os << ptr->arb()->_elem << "|" << (ptr->arb());
	
	os << "]\n V\n";
	ptr = ptr->_next;
  }
  os << "[NULL]";
  delete ptr;
  return os;
}


/* Rust solutions after this point */

/** Reverse the linked list using solution 1 (iterative)
 */
template <typename T>
void LinkedList<T>::reverse() {
  if (this->_head == nullptr || this->_head->_next == nullptr)
	return;

  Node<T>* list_to_do = this->_head->_next;
  this->_head->_next = nullptr;

  while (list_to_do != nullptr) {
	Node<T>* temp = list_to_do;
	list_to_do = list_to_do->_next;

	temp->_next = _head;
	_head = temp;
  }
  delete list_to_do;
}

/** Reverse the linked list using solution 2 (recursive)
 */
template <typename T>
void LinkedList<T>::reverseRecursive() {
  this->_head = this->_reverse_recursive(this->_head); // This method is declared later in the "Helpers" section
}

/** Delete a node with key `key` from the linked list
 *
 * @params T Key value
 */
template <typename T>
void LinkedList<T>::deleteKey (T key) {
  Node<T>* prev = nullptr;
  Node<T>* current = this->head();

  while (current != nullptr) {
	if (current->value() == key) {
	  this->_size--;
	  break;					// Found it! :)
	}

	prev = current;
	current = current->next();
  }
  
  if (current == nullptr) {
	return;				// Didn't find it :(
  }

  if (current == this->head()) {
	this->setHead(this->head()->next());
  } else {
	prev->setNext(current->next());
  }

  delete current;
}


//////////////////////////////////////
// Helpers:

/** Reverse a singly linked list (Recursive)
 *
 * @returns Node<T>* The head of the reversed linked list
 * @param Node<T>* The head of the linked list to be reversed
 */
template <typename T>
Node<T>* LinkedList<T>::_reverse_recursive (Node<T>* node) {
  // If the size of the linked list = 0 or 1, nothing to do :)
  if (node == nullptr || node->next() == nullptr)
	return node;

  Node<T>* reversed_list = this->_reverse_recursive(node->next());

  node->next()->setNext(node);
  node->setNext(nullptr);
  return reversed_list;
}


//////////////////////////////////////
// This is a specialized Linked List
// used for integer representation

/** Int class
 *
 * Every digit in the integer is represented as a node in
 * a singly linked list starting from ones
 */
class Int {
public:
  Int() { this->_num.setHead(nullptr); }
  Int(int n);
  Int (Node<int>* n) { this->_num.setHead(n); }
  // ~Int();
public:
  Node<int>* getHead() const {
	return const_cast<Int*>(this)->_num.head(); }
  Int& operator=(const Int& rhs);
  int value() const;
  // Int operator+(const Int& a, const Int& b);
public:
  friend std::ostream& operator<<(std::ostream& os, const Int& num);
  friend Int operator+(const Int&, const Int&);
private:
  LinkedList<int> _num;
  // bool negative;
};

/** Signed constructor
 */
Int::Int(int n) {
  // delete &_num;
  this->_num = LinkedList<int>();
  if (n < 0)
	throw (std::range_error("No support for negative numbers...!"));
  do {
	_num.addFront(n % 10);
	n = n / 10;
  } while (n > 0);
  _num.reverse();
}
/*
Int::~Int() {
  while (!this->_num.empty()) this->_num.removeFront();
}
*/

/** Copy assignment !!!
 */
Int& Int::operator=(const Int& rhs) {
  while (!this->_num.empty()) this->_num.removeFront();
  int n = rhs.value();
  if (n < 0)
	throw (std::range_error("No support for negative numbers...!"));
  do {
	this->_num.addFront(n % 10);
	n = n / 10;
  } while (n > 0);
  this->_num.reverse();
  return *this;
}

/** Return the value
 */
int Int::value() const {
  long exp = 1;
  int n = 0;
  Node<int>* ptr = this->getHead();
  while (ptr != nullptr) {
	n += exp * ptr->value();
	exp *= 10;
	ptr = ptr->next();
  }
  delete ptr;
  return n;
}

/** Addition operator overloading
 */
Int operator+(const Int& A, const Int& B) {
  Node<int>* a = A.getHead();
  Node<int>* b = B.getHead();

  Node<int>* result = nullptr;
  Node<int>* last = nullptr;
  int carry = 0;
  
  while (a != nullptr || b != nullptr || carry > 0) {
	int first = (a == nullptr ? 0 : a->value());
	int second = (b == nullptr ? 0 : b->value());

	int sum = first + second + carry;
	// cout << "DEBUG: " << first << ' ' << second << endl;
	Node<int>* pNew = new Node<int>(sum % 10);
	carry = sum / 10;

	if (result == nullptr) {
	  result = pNew;
	} else {
	  last->setNext(pNew);
	}

	last = pNew;

	if (a != nullptr) {
	  a = a->next();
	}

	if (b != nullptr) {
	  b = b->next();
	}
  }
  // This is the head of the new LinkedList:
  // return result;
  Int temp;
  temp._num.setHead(result);
  return temp;
}

/** Ostream method
 */
std::ostream& operator<<(std::ostream& os, const Int& num) {
  /*Node<int> *ptr = num.getHead();
  int counter = 1;
  int number = 0;
  while (ptr != nullptr) {
	number = counter * ptr->value();
	ptr = ptr->next();
	counter *= 10;
  }
  os << number;
  return os;*/
  os << num.value();
  return os;
}
