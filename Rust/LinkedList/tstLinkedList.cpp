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
  
  return 0;
}
