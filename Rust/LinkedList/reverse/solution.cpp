#include <iostream>
#include <exception>

#include "../../Library/C++/LinkedList.hpp"

using namespace std;

int main() {
  Node <char> a('a');
  Node <char> b('b');
  a.next(&b);

  cout << a.value() << a.next()->value() << endl;

  return 0;
}

