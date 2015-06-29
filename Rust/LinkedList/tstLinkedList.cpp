#include <iostream>

#include "LinkedListS.hpp"

using namespace std;


int main() {
  // Test Constructors/Destructors
  ListNodeS<int> *h1 = new ListNodeS<int>();
  LinkedListS<int> ll1(h1);
  LinkedListS<int> ll2;

  ListNodeS<int> *h2 = ll1.head();
  
  cout << h2 << endl;

  // Friend classes:
  cout << ll1 << endl;
  
  // delete h1;
  // delete h2;
}
