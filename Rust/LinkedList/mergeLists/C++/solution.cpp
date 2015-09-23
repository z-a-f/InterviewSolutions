#include <iostream>

#include "../../../Library/C++/LinkedList.hpp"

template <typename T> using pNode = std::shared_ptr< Node<T> >; // This is just for convenience
using namespace std;

/*
template <typename T>
void DEBUG(pNode<T> head, pNode<T> tail) {
    // cout << "[HEAD]->";
    pNode<T> ptr = head;
    while (ptr != tail) {
        
        cout << "[" << ptr->value() << "]->";
        ptr = ptr->next();
    }
    // cout << "[NULL]";
}
*/

/** Merge sort helper: merge routine
 *
 * Merges two linked lists into one, and returns the head of the combined linked list
 * Note that the original linked lists will be destroyed, and will sometimes represent
 * some non-sense
 *
 * @params pNode<T> first linked list head (std::shared_ptr< Node<T> >)
 * @params pNode<T> second linked list head (std::shared_ptr< Node<T> >)
 * @returns pNode<T> head of the combined linked list (std::shared_ptr< Node<T> >)
 */
template <typename T>
pNode<T> merge(pNode<T> head1, pNode<T> head2) {
    // If one of the lists is empty, return the other
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    pNode<T> merged = nullptr;
    if (head1->value() <= head2->value()) {
        merged = head1;
        head1 = head1->next();
    } else {
        merged = head2;
        head2 = head2->next();
    }

    pNode<T> tail = merged;

    while (head1 != nullptr && head2 != nullptr) {
        pNode<T> temp = nullptr;
        if (head1->value() <= head2->value()) {
            temp = head1;
            head1 = head1->next();
        } else {
            temp = head2;
            head2 = head2->next();
        }

        tail->setNext(temp);
        tail = temp;
    }

    if (head1 != nullptr) tail->setNext(head1);
    else if (head2 != nullptr) tail->setNext(head2);

    return merged;
}

int main() {
    LinkedList<int> list1;
    LinkedList<int> list2;

    list1.addFront(19);
    list1.addFront(15);
    list1.addFront(8);
    list1.addFront(4);

    list2.addFront(16);
    list2.addFront(10);
    list2.addFront(9);
    list2.addFront(7);

    cout << "Original 1: " << list1 << endl;
    cout << "Original 2: " << list2 << endl;

    LinkedList<int> merged;
    merged.setHead(merge(list1.head(), list2.head()));

    cout << "Merged: " << merged << endl;
    cout << "Original 1: " << list1 << endl;
    cout << "Original 2: " << list2 << endl;        
}
