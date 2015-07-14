# include <iostream>

#include "../../LinkedList.hpp"

using namespace std;

/** Add two integers of type Int
 *
 * @return Int The result of the addition
 * @params Int Both inputs of type Int
 */
Int add_integers (Int A, Int B) {
  Node<int>* result = nullptr;
  Node<int>* last = nullptr;
  int carry = 0;
  
  Node<int>* a = A.getHead();
  Node<int>* b = B.getHead();
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
  return Int(result);
}

int main() {
  Int a = Int(123);
  Int b = Int(999);
  Int c = add_integers(a, b);

  cout << c.value() << endl;
  cout << "TEST" << endl;
  
  return 0;
}
