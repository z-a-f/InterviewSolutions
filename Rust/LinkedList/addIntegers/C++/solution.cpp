# include <iostream>

#include "../../LinkedList.hpp"

using namespace std;

/** Add two integers of type Int
 *
 */
Node<int>* add_integers (Node<int>* a, Node<int>* b) {
  Node<int>* result = nullptr;
  Node<int>* last = nullptr;
  int carry = 0;
  
  while (a != nullptr || b != nullptr || carry > 0) {
	int first = (a == nullptr ? 0 : a->value());
	int second = (b == nullptr ? 0 : b->value());

	int sum = first + second + carry;
	cout << "DEBUG: " << first << ' ' << second << endl;
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
  return result;
}

int main() {
  // Create integer 123:
  LinkedList<int> a;
  a.addFront(1);
  a.addFront(2);
  a.addFront(3);
  cout << "Integer a: " << a << endl;

  // Create integer 897:
  LinkedList<int> b;
  b.addFront(8);
  b.addFront(9);
  b.addFront(7);
  cout << "Integer b: " << b << endl;

  // Add them up:
  LinkedList<int> c;
  c.setHead(add_integers(a.head(), b.head()));
  cout << "Integer a + b: " << c << endl;
  
  return 0;
}
