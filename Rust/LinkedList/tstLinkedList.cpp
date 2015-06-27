#include <iostream>

#include "LinkedList.hpp"

using namespace std;

template <typename T>
void printLinkedList(LinkedList<T> ll) {
  cout << "HEAD->";
  LinkedListNode<T> *ptr = ll.head->next;
  while (ptr != nullptr) {
	cout << ptr->data << "->";
  }
  cout << "NULL\n";
}

int main() {
  LinkedListNode<int> *node1 = new LinkedListNode<int>();
  node1->data = 1;
  cout << "Node value: " << node1->data << endl;
  
  LinkedList<int> ll;
  //printLinkedList(ll);

  delete node1;
}
