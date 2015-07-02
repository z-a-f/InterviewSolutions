#pragma once

template <typename T> class LinkedList;
template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);


/** Node class
 * 
 * @tparam T template type
 */
template <typename T>
class Node {
public:
  /** Constructor */
  Node() : _elem(0), _next(nullptr) {}
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
private:
  T _elem;						//!< Stored value
  Node<T>* _next;				//!< Next element

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
  const T& front() const;
  void addFront(const T& e);
  void removeFront();
public:
  // Housekeeping
  std::size_t size() const;
  Node<T>* head();
  void setHead(Node<T>* h);		// This is dangerous!!!
  // template <typename U>
  // friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list);
  friend std::ostream& operator<<<>(std::ostream& os, const LinkedList& list);
private:
  Node<T>* _head;
  std::size_t _size;

  // Rust solutions after this point
public:
  void reverse();
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
const T& LinkedList<T>::front() const {
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
  if (empty()) return;
  Node<T>* old = _head;
  _head = old->_next;
  _size--;
  delete old;
}

// Housekeeping functions

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
  os << "HEAD->";
  Node<T>* ptr = list._head;
  while (ptr != nullptr) {
	os << ptr->_elem << "->";
	ptr = ptr->_next;
  }
  os << "NULL";
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
