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

  list.addFront('a');           // Should be invalid, but works
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
  cout << a << "+" << b << "=" << c << endl;
  

  LinkedList<int> listArb;
  listArb.addFront(15);
  listArb.addFront(21);
  listArb.addFront(14);
  listArb.addFront(7);
  listArb.head()->setArb(listArb.head()->next()->next());
  listArb.head()->next()->next()->setArb(listArb.head());

  cout << "List with arbitraries for deep copy:"  << listArb << endl;
  listArb.printArb();
  LinkedList<int> listArbCopy = listArb.deepCopy();
  // listArbCopy.setHead(deep_copy_arbitrary_pointer(listArb.head()));

  // Change some stuff to check if the linked lists are really separate
  listArbCopy.head()->next()->setValue(123);
  listArb.head()->setValue(321);
  
  cout << listArbCopy << endl;
  cout << listArb << endl;
  
  // Check the sorting algos:
  LinkedList<int> sort;
  sort.addFront(11);
  sort.addFront(82);
  sort.addFront(23);
  sort.addFront(29);

  cout << sort << endl;
  sort.sort();
  cout << sort << endl;
  
  // Check the intersections:
  cout << "Check the intersections...\n";
  LinkedList<int> list1;
  LinkedList<int> list2;

  list1.addFront(27);
  list1.addFront(12);
  list1.addFront(23);
  list1.addFront(29);

  list2.addFront(4);
  list2.addFront(13);

  list2.head()->next()->setNext(list1.head()->next()->next());

  cout << list1 << endl;
  cout << list2 << endl;

  std::shared_ptr< Node<int> > intsct = list1.intersects(list2);

  if (intsct == nullptr) cout << "NULL" << endl;
  else cout << intsct->value() << endl;

  LinkedList<int> list3;
  list3.addFront(27);
  list3.addFront(12);
  list3.addFront(23);
  list3.addFront(29);
  intsct = list1.intersects(list3);
  if (intsct == nullptr) cout << "NULL" << endl;
  else cout << intsct->value() << endl;

  
  
  return 0;
}


