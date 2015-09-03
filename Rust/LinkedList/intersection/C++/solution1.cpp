#include <iostream>

#include "../../LinkedList.hpp"

using namespace std;

template <typename T>
std::size_t size(Node<T>* head) {
    std::size_t len = 0;
    while (head != nullptr) {
        head = head->next();
        len++;
    }
    return len;
}

template <typename T>
Node<T>* intersect (Node<T>* head1, Node<T>* head2) {
    Node<T>* l1 = nullptr;
    Node<T>* l2 = nullptr;

    size_t l1len = size(head1);
    size_t l2len = size(head2);

    int d = l1len - l2len;
    l1 = d >= 0 ? head1 : head2;
    l2 = d >= 0 ? head2 : head1;
    d = d >= 0 ? d : -d;

    while (d > 0) {
        l1 = l1->next();
        d--;
    }
    // TODO: Didn't finish the code
}

int main() {
    LinkedList<int> list;
    LinkedList<int> sort;

    list.addFront(11);
    list.addFront(82);
    list.addFront(23);
    list.addFront(29);

    cout << list << endl;

    sort.setHead(insertion_sort(list.head()));

    cout << list << endl;
    cout << sort << endl;

    // cout << list << endl;
    // cout << sort << endl;

    /*
      Node<int>* list = new Node<int>(11);

      Node<int>* sort;

      sort = new Node<int>(82);
      sort->setNext(list);
      list = sort;

      sort = new Node<int>(23);
      sort->setNext(list);
      list = sort;

      sort = new Node<int>(29);
      sort->setNext(list);
      list = sort;

      sort = nullptr;
      DEBUG(list, sort);

      sort = insertion_sort(list);
      DEBUG(list, sort);
    */


    /*LinkedList<int> list;
      list.addFront(11);
      list.addFront(82);
      list.addFront(23);
      list.addFront(29);
      cout << list << endl;

      cout << "\n *********** \n";
      LinkedList<int> sorted;
      sorted.setHead(insertion_sort(list.head()));
      cout << "\n *********** \n";

      cout << list << endl;

      cout << sorted << endl;
    */
    return 0;
}
