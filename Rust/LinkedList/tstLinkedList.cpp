#include <iostream>

#include "LinkedListS.hpp"

using namespace std;


int main() {
  // Test Constructors/Destructors
  ListNodeS<int> *h1 = new ListNodeS<int>();
  h1->setValue(1);
  LinkedListS<int> ll1(h1);
  LinkedListS<int> ll2;

  ListNodeS<int> *h2 = ll1.head();
  
  cout << h2 << endl;
  ll1.push(new ListNodeS<int>(12));
  // Friend classes:
  cout << ll1 << endl;
  cout << ll1.size() << endl;
  cout << ll2.size() << endl;

  ListNodeS<int> *h3 = ll1.pop();
  cout << h3->value() << endl;

  cout << ll1 << endl;
  cout << ll1.size() << endl;;

  // delete h1;
  // delete h2;
  // delete h3;
}
