#include <iostream>

#include "../../LinkedList.hpp"


template <typename T> using pNode = std::shared_ptr< Node<T> >;
using namespace std;

/** Insertion sort helper
 *
 * @tparams T
 * @param pNode<T> head Head of the sorted list
 * @param pNode<T> node Node to be inserted
 * @return pNode<T> List with the node inserted
 */
template <typename T>
static pNode<T> sorted_insert(pNode<T> head, pNode<T> node) {
    if (node == nullptr) {
        return head;
    }

    if (head == nullptr || node->value() <= head->value()) {
        node->setNext(head);
        return node;
    }

    pNode<T> curr = head;

    while (curr->next() != nullptr && curr->next()->value() < node->value()) {
        curr = curr->next();
    }
    node->setNext(curr->next());
    curr->setNext(node);

    return head;
}

/** Sort the linked list (destructive, buggy)
 *
 * @tparams T
 * @params pNode<T> the head of the linked list to be sorted
 * @returns pNode<T> the head of the new linked list
 */
template <typename T>
pNode<T> insertion_sort(pNode<T> head) {
    pNode<T> sorted = nullptr;
    pNode<T> curr = head;

    // DEBUG(curr, sorted);
    while (curr != nullptr) {
        pNode<T> temp = curr->next();
        sorted = sorted_insert(sorted, curr);
        curr = temp;
        // DEBUG(curr, sorted);
    }
    // delete curr;
    return sorted;
}

template<typename T>
void DEBUG(pNode<T>orig, pNode<T> sort) {
    pNode<T> ptr = orig;
    std::cout << "(orig)->";
    while (ptr != nullptr) {
        std::cout << "[" << ptr->value() << "]->";
        ptr = ptr->next();
    }
    std::cout << "(NULL)\n";
    ptr = sort;
    std::cout << "(sort)->";
    while (ptr != nullptr) {
        std::cout << "[" << ptr->value() << "]->";
        ptr = ptr->next();
    }
    std::cout << "(NULL)\n";
    delete ptr;
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
