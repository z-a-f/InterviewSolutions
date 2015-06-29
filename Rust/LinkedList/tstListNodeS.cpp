#include <iostream>
#include <assert.h>

#include "ListNodeS.hpp"

using namespace std;

int main() {
  // Test constructors
  ListNodeS<int> node1;
  ListNodeS<int> node2(5, &node1);

  // Test setters:
  node1.setNext(&node2);
  node1.setValue(3);

  // Test getters:
  assert(node2.value() == 5);
  assert(node2.next()->value() == 3);
}
