#include <iostream>

#include "LinkedList.hpp"

using namespace std;

int main() {
  LinkedList<int> list;
  cout << list << endl;

  list.addFront(28);
  list.addFront(21);
  list.addFront(14);
  list.addFront(7);
  cout << list << endl;

  list.reverse();
  cout << list << endl;
  
  return 0;
}
