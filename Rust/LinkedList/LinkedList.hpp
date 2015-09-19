#pragma once

#include <exception>
#include <iostream>
#include <unordered_map>


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
    T _elem;                    //!< Stored value
    Node<T>* _next;             //!< Next element
    Node<T>* _arb;              //!< Arbitrary element

    friend class LinkedList<T>; //!< Friend class
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
    void setHead(Node<T>* h);             // This is dangerous!!!
    // template <typename U>
    // friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list);
    Node<T>* operator[](std::size_t idx);
    friend std::ostream& operator<<<>(std::ostream& os, const LinkedList& list);
    void printArb();
private:
    Node<T>* _head;
    // std::size_t _size;

    // Rust solutions after this point
public:
    void reverse();
    void reverseRecursive();
    void deleteKey (T key);
    LinkedList<T> deepCopy();
    void sort();
private:
    Node<T>* _reverse_recursive(Node<T>* node);
    Node<T>* _deep_copy_1 (Node<T>* head);
    Node<T>* _deep_copy_2 (Node<T>* head);
    Node<T>* _sorted_insert(Node<T>* head, Node<T>* node);
    Node<T>* _insertion_sort(Node<T>* head);
};



/** Constructor */
template <typename T>
LinkedList<T>::LinkedList() : _head(nullptr)/*, _size(0)*/ {}

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
    // _size++;
}

/** Remove the first element
 *
 */
template <typename T>
void LinkedList<T>::removeFront() {
    if (this->empty()) return;
    Node<T>* old = _head;
    _head = old->_next;
    // _size--;
    delete old;
}

/** Number of elements in the list
 *
 * @returns std::size_t Number of elements in the list
 */
template <typename T>
std::size_t LinkedList<T>::size() const {
    // return this->_size;
    Node<T> head = this->head();
    std::size_t len = 0;
    while (head != nullptr) {
        head = head->next();
        len++;
    }
    return len;    
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
    // this->resetSize();
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

    /*
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
    */
}

template <typename T>
void LinkedList<T>::printArb() {
    std::cout << "[HEAD]\n V\n";
    Node<T>* ptr = this->_head;
    while (ptr != nullptr) {
        std::cout << "[" << ptr->_elem << "]->";
        std::cout << "[";// << ( (ptr->arb() == nullptr) ? "NULL" : ptr->arb()->_elem) << "]\n V";
        if (ptr->arb() == nullptr)
            std::cout << "NULL";
        else
            std::cout << ptr->arb()->_elem << "|" << (ptr->arb());

        std::cout << "]\n V\n";
        ptr = ptr->_next;
    }
    std::cout << "[NULL]";
    delete ptr;
    // return std::cout;
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
            // this->_size--;
            break;              // Found it! :)
        }

        prev = current;
        current = current->next();
    }

    if (current == nullptr) {
        return;                         // Didn't find it :(
    }

    if (current == this->head()) {
        this->setHead(this->head()->next());
    } else {
        prev->setNext(current->next());
    }

    delete current;
}

/** Deep copy method
 *
 * @returns LinkedList<T> New linked list
 */
template <typename T>
LinkedList<T> LinkedList<T>::deepCopy() {
    LinkedList<T> copy;
    copy.setHead(this->_deep_copy_2(this->head()));
    return copy;
}

/** Sort the current linked list */
template <typename T>
void LinkedList<T>::sort() {
    this->setHead(this->_insertion_sort(this->head()));
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

/** Deep copy the single linked list (solution 1)
 *
 * @returns Node<T>* The head of the new linked list
 * @params Node<T>* The head of the original linked list
 */
template <typename T>
Node<T>* LinkedList<T>::_deep_copy_1 (Node<T>* head) {
    // If the linked list is empty, return
    if (head == nullptr) {
        return nullptr;
    }

    Node<T>* current = head;
    Node<T>* new_head = nullptr;
    Node<T>* new_prev = nullptr;
    std::unordered_map<Node<T>*, Node<T>*> map;

    // Create copy of the linked list, recording the corresponding
    // nodes in hashmap without updating arbitrary pointer
    while (current != nullptr) {
        Node<T>* new_node = new Node<T>(current->value());

        // Copy the old arbitrary pointer in the new node
        new_node->setArb(current->arb());

        if (new_prev != nullptr) {
            new_prev->setNext(new_node);
        } else {
            new_head = new_node;
        }

        map[current] = new_node;
        new_prev = new_node;
        current = current->next();
    }

    Node<T>* new_current = new_head;

    // Update arbitrary pointer:
    while (new_current != nullptr) {
        if (new_current->arb() != nullptr) {
            Node<T>* node = map[new_current->arb()];
            new_current->setArb(node);
        }
        new_current = new_current->next();
    }
    return new_head;
}

/** Deep copy the single linked list (solution 2)
 *
 * @returns Node<T>* The head of the new linked list
 * @params Node<T>* The head of the original linked list
 */
template <typename T>
Node<T>* LinkedList<T>::_deep_copy_2 (Node<T>* head) {
    // If the linked list is empty, return
    if (head == nullptr) {
        return nullptr;
    }

    Node<T>* current = head;

    // Inserting new nodes within the existing linked list
    while (current != nullptr) {
        Node<T>* new_node = new Node<T>(current->value());
        new_node->setNext(current->next());
        current->setNext(new_node);
        current = new_node->next();
    }

    // Setting correct arbitrary pointers
    current = head;
    while (current != nullptr) {
        if (current->arb() != nullptr) {
            current->next()->setArb(current->arb()->next());
        }
        current = current->next()->next();
    }

    // Separating lists
    current = head;
    Node<T>* new_head = head->next();
    Node<T>* copied_current = nullptr;

    while (current != nullptr) {
        copied_current = current->next();
        current->setNext(copied_current->next());

        if (copied_current->next() != nullptr) {
            copied_current->setNext(copied_current->next()->next());
        }

        current = current->next();
    }
    return new_head;
}

/** Insert in a sorted manner
 *
 * This method looks for an appropriate position
 * for a given node and inserts it into the linked
 * list with head "head"
 *
 * @returns Node<T>* The head of the new linked list
 * @param Node<T>* head -> the head of the linked list
 * @param Node<T>* node -> node to be inserted
 */
template <typename T>
Node<T>* LinkedList<T>::_sorted_insert(Node<T> *head, Node<T> *node) {
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


/** Sort the linked list (destructive)
 *
 * Sort the linked list and destroy the original
 *
 * @returns Node<T>* The head of the new linked list
 * @param Node<T>* head -> the head of the old linked list
 */

template <typename T>
Node<T>* LinkedList<T>::_insertion_sort(Node<T> *head){
    Node<T>* sorted = nullptr;
    Node<T>* curr = head;

    while (curr != nullptr) {
        Node<T>* temp = curr->next();
        sorted = this->_sorted_insert(sorted, curr);
        curr = temp;
    }

    return sorted;
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
