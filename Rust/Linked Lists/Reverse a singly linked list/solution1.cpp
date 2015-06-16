# include <iostream>

#include "../../support/support.hpp" // This has useful stuff

using namespace std;

template <typename T>
LinkedListNode<T>* reverse_iterative (LinkedListNode<T>* head) {
  // Check size:
  if (head == nullptr || head->next == nullptr) return head;

  // Initialize the stuff still to do, and set head to be the last
  LinkedListNode<T>* still_to_do = head->next;
  head->next = nullptr;

  // While there is still stuff to do - move from one pile to other
  while (still_to_do != nullptr) {
	LinkedListNode<T>* temp = still_to_do;
	still_to_do = still_to_do->next;

	temp->next = head;
	head = temp;

  }
  return head;
}

int main() {
  // Example case:
  LinkedListNode<int>* head = new LinkedListNode<int>(7);
  LinkedListNode<int>* temp = head;
  temp->next = new LinkedListNode<int>(14);
  temp = temp->next;
  temp->next = new LinkedListNode<int>(21);
  temp = temp->next;
  temp->next = new LinkedListNode<int>(28);

  // 
  cout << "HEAD->";
  head->printChain();

  head = reverse_iterative(head);
  cout << "HEAD->";
  head->printChain();

  return 0;
}
