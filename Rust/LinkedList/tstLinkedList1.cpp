#include <iostream>


#include "LinkedList.hpp"

using namespace std;

int main() {
  LinkedList<int> ll1;
  ll1.removeFront();
  ll1.addFront(1);

  cout << ll1 << endl;
}
