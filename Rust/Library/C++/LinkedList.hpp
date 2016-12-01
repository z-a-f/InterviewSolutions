#pragma once

#include <iostream>
#include <memory>
#include <exception>

/** Node class
 *
 * @tparam T template type
 */
template <class T>
class Node {
public:
  Node(T v = T(0)): _value(v), _next(nullptr) {}
  // ~Node() {} // No need for destructor
public:
  T value() { return _value; } // Getter
  void value(T v) { this->_value = v; } // Setter
  Node<T>* next() { return this->_next; }
  void next(Node<T>* n) { this->_next = n; }
private:
  T _value;
  Node<T>* _next;
};

/** Singly Linked List
 *
 * @tparam T template type
 */
template <class T>
class LinkedList {
public:
  LinkedList(): { this->_head = nullptr; }
public:
  Node<T>* head() { return this->_head; }
  void head(Node<T> * h) { this->_head = h; }
public:
  void push(Node<T> *node);
  void push(T value);
  Node<T> * pop();
  Node<T> * peek();
private:
  Node<T> * _head;
}

template <class T>
void LinkedList<T>::push(Node<T> *node) {
  node->next(this->head());
  this->head(node);
}

template <class T>
void LinkedList<T>::push(T value) {
  LinkedList<T>::push(new Node<T>(value));
}

template <class T>
Node<T>* LinkedList<T>::pop() {
  Node<T>* peek = LinkedList<T>::peek();
  this->head(this->head()->next());
  return peek
}

template <class T>
Node<T>* LinkedList<T>::peek() {
  return this->head();
}

// #pragma once

// #include <exception>
// #include <iostream>

// template <typename T> class LinkedList;
// class Int;
// template <typename T>
// std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);
// std::ostream& operator<<(std::ostream& os, const Int& num);


// /** Node class
//  *
//  * @tparam T template type
//  */
// template <typename T>
// class Node {
// public:
//     /** Constructor */
//     // Node(T e = T(0)) : _elem(e), _next(nullptr), _arb(nullptr) {}
//     Node(T e = T(0)) : _elem(e), _next(nullptr), _arb(std::weak_ptr< Node<T> >()) {}
//     // ~Node() { delete _next; }
// public:
//     // Getters/Setters:
//     /** Return the value in the node
//      *
//      * @returns T value
//      */
//     const T& value() const { return this->_elem; }
//     /** Return the next node
//      *
//      * @returns std::shared_ptr< Node<T> >
//      */
//     std::shared_ptr< Node<T> > next() const { return this->_next; }
//     /** Return the arbitrary node
//      *
//      * @returns std::shared_ptr< Node<T> >
//      */
//     std::shared_ptr< Node<T> > arb() const {
//         // std::shared_ptr< Node<T> > sp(this->_arb);
//         // return sp;
//         if (this->_arb.expired()) return nullptr;
//         return std::shared_ptr< Node<T> > (this->_arb);
//     }
//     /** Set the value in the node
//      *
//      * @param T value
//      */
//     void setValue(const T& e) { this->_elem = e; }
//     /** Set the next pointer
//      *
//      * @param std::shared_ptr< Node<T> > the next "next" pointer
//      */
//     void setNext(std::shared_ptr< Node<T> > n) { this->_next = n; }
//     /** Set the arbitrary pointer
//      *
//      * @param std::shared_ptr< Node<T> > the next "arb" pointer
//      */
//     void setArb(std::shared_ptr< Node<T> > n) { this->_arb = n; }
//     /** Set the arbitrary pointer
//      *
//      * @param std::weak_ptr< Node<T> > the next "arb" pointer
//      */
//     void setArb(std::weak_ptr< Node<T> > n) { this->_arb = n; }
// private:
//     T _elem;                    //!< Stored value
//     std::shared_ptr< Node<T> > _next;             //!< Next element
//     std::weak_ptr< Node<T> > _arb;              //!< Arbitrary element

//     friend class LinkedList<T>; //!< Friend class
// };


// /** Singly Linked List
//  *
//  * @tparam T template type
//  */
// template <typename T>
// class LinkedList {
// public:
//     LinkedList();
//     // ~LinkedList();
// public:
//     bool empty() const;
//     const T& front() const throw(std::range_error);
//     void addFront(const T& e);
//     void removeFront();
// public:
//     // Housekeeping
//     std::size_t size() const;
//     std::shared_ptr< Node<T> > head();
//     void setHead(std::shared_ptr< Node<T> > h);             // This is dangerous!!!
//     /** Remove all elements in the linked list */
//     void clear() { while(!empty()) removeFront(); }
//     std::shared_ptr< Node<T> > operator[](std::size_t idx);
//     friend std::ostream& operator<<<>(std::ostream& os, const LinkedList& list);
//     void printArb();
// private:
//     std::shared_ptr< Node<T> > _head;
// };



// /** Constructor */
// template <typename T>
// LinkedList<T>::LinkedList() : _head(nullptr)/*, _size(0)*/ {}

// /** Empty?
//  *
//  * @returns bool True if empty
//  */
// template <typename T>
// bool LinkedList<T>::empty() const {
//     return _head == nullptr;
// }

// /** Get front element (read-only)
//  *
//  * @returns T
//  */
// template <typename T>
// const T& LinkedList<T>::front() const
//     throw (std::range_error) {
//     if (empty()) {
//         throw std::range_error("Linked List empty! Cannot get front()");
//         // return 0;
//     }
//     return _head->_elem;
// }

// /** Add element in the front of the list
//  *
//  * @param e Element to be added
//  */
// template <typename T>
// void LinkedList<T>::addFront(const T& e) {
//     // std::shared_ptr< Node<T> > v = std::make_shared< Node<T> >();// (new Node<T>);
//     std::shared_ptr< Node<T> > v(new Node<T>);
//     v->_elem = e;
//     v->_next = _head;
//     _head = v;
//     // _size++;
// }

// /** Remove the first element
//  *
//  */
// template <typename T>
// void LinkedList<T>::removeFront() {
//     if (this->empty()) return;
//     std::shared_ptr< Node<T> > old = _head;
//     _head = old->_next;
//     // _size--;
//     // delete old;
//     old.reset();
// }

// /** Number of elements in the list
//  *
//  * @returns std::size_t Number of elements in the list
//  */
// template <typename T>
// std::size_t LinkedList<T>::size() const {
//     // return this->_size;
//     std::shared_ptr< Node<T> > head = const_cast<LinkedList<T>*>(this)->head(); // Need to cast this as const
//     std::size_t len = 0;
//     while (head != nullptr) {
//         head = head->next();
//         len++;
//     }
//     return len;
// }

// /** Returns the head of the linked list
//  *
//  * @returns std::shared_ptr< Node<T> > the head of the current linked list
//  */
// template <typename T>
// std::shared_ptr< Node<T> > LinkedList<T>::head() { return this->_head; }

// /** Set the head to different node
//  *
//  * NOTE: this method is dangerous as it will lose information
//  * about other nodes!!!
//  *
//  * @params std::shared_ptr< Node<T> > the node to be set as head
//  */
// template <typename T>
// void LinkedList<T>::setHead(std::shared_ptr< Node<T> > h) {
//     this->_head = h;
//     // this->resetSize();
// }


// /** Operator<< for the linked list
//  *
//  * @returns std::ostream
//  * @param LHS->std::ostream
//  * @param RHS->LinkedList<T>
//  */
// template <typename T>
// std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
//     os << "HEAD->";
//     std::shared_ptr< Node<T> > ptr = list._head;
//     while (ptr != nullptr) {
//         os << ptr->_elem << "->";
//         ptr = ptr->_next;
//     }
//     os << "NULL";
//     // delete ptr;
//     ptr.reset();
//     return os;
// }

// template <typename T>
// void LinkedList<T>::printArb() {
//     std::cout << "[HEAD]\n V\n";
//     std::shared_ptr< Node<T> > ptr = this->_head;
//     while (ptr != nullptr) {
//         std::cout << "[" << ptr->_elem << "]->";
//         std::cout << "[";// << ( (ptr->arb() == nullptr) ? "NULL" : ptr->arb()->_elem) << "]\n V";
//         // std::cout << "DEBUG1\n";
//         if (ptr->arb() == nullptr) { // ptr->arb() == nullptr) {
//             // std::cout << "DEBUG2\n";
//             std::cout << "NULL";
//         } else{
//             // std::cout << "DEBUG3\n";
//             std::cout << ptr->arb()->_elem << "|" << (ptr->arb());
//         }

//         std::cout << "]\n V\n";
//         ptr = ptr->_next;
//     }
//     std::cout << "[NULL]";
//     // delete ptr;
//     ptr.reset();
//     // return std::cout;
// }
