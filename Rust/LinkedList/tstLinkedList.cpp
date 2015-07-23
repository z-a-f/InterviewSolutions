#include <iostream>
#include <exception>

#include "LinkedList.hpp"

using namespace std;

int main() {
  LinkedList<int> list;
  cout << list << endl;
  try {
	cout << list.front() << endl;
  } catch (std::exception& e) {
	cout << "Exception caught: " << e.what() << endl;
  }

  list.addFront(28);
  list.addFront(21);
  list.addFront(14);
  list.addFront(7);

  cout << "Initial list:\n";
  cout << list << endl;


  // Check iterative reversing:
  cout << "\nAfter iterative reverse:\n";
  list.reverse();
  cout << list << endl;

  // Check recursive reversing:
  cout << "\nAfter recursive reverse:\n";
  list.reverseRecursive();
  cout << list << endl;

  // Check deleting nodes:
  cout << "\nAfter deleting non-existing key:\n";
  list.deleteKey(0);
  cout << list << endl;

  cout << "\nAfter deleting head key:\n";
  list.deleteKey(list.head()->value());
  cout << list << endl;

  cout << "\nAfter deleting middle key:\n";
  list.deleteKey(list.head()->next()->value());
  cout << list << endl;

  cout << "\nAfter deleting key:\n";
  list.deleteKey(list.head()->next()->value());
  cout << list << endl;

  cout << "\nCreate an Linked List Int:\n";
  Int num(100);
  cout << num << endl;
  num = Int(200);
  cout << num << endl;

  Int a(123);
  Int b(897);
  Int c = a + b;
  cout << c << endl;

  LinkedList<int> listArb;
  listArb.addFront(21);
  listArb.addFront(14);
  listArb.addFront(7);
  listArb.head()->setArb(listArb.head()->next()->next());
  listArb.head()->next()->next()->setArb(listArb.head());
  cout << listArb << endl;

  LinkedList<int> listArbCopy = listArb.deepCopy();
  // listArbCopy.setHead(deep_copy_arbitrary_pointer(listArb.head()));

  // Change some stuff to check if the linked lists are really separate
  listArbCopy.head()->next()->setValue(123);
  listArb.head()->setValue(321);
  
  cout << listArbCopy << endl;
  cout << listArb << endl;
  
  return 0;
}
