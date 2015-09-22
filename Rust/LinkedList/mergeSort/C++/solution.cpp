#include <iostream>

#include "../../LinkedList.hpp"

template <typename T> using pNode = std::shared_ptr< Node<T> >;
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

/** Merge sort helper: split routine
 *
 * Splits a linked list into two, and returns the head of the second half.
 * Note that the `head` __cannot__ be a `NULL`
 *
 * @params pNode<T> head of the original linked list (std::shared_ptr< Node<T> >)
 * @returns pNode<T> head of the second-half linked list (std::shared_ptr< Node<T> >)
 */
template <typename T>
pNode<T> split(pNode<T> head) {
    pNode<T> slow, fast;
    slow = head;
    fast = head->next();

    while (fast != nullptr) {
        fast = fast->next();
        if (fast != nullptr) {
            fast = fast->next();
            slow = slow->next();
        }
    }

    fast = slow->next();
    slow->setNext(nullptr);

    return fast;
}

/** Merge sort helper: merge routine
 *
 * Merges two linked lists into one, and returns the head of the combined linked list
 *
 * @params pNode<T> first linked list head (std::shared_ptr< Node<T> >)
 * @params pNode<T> second linked list head (std::shared_ptr< Node<T> >)
 * @returns pNode<T> head of the combined linked list (std::shared_ptr< Node<T> >)
 */
template <typename T>
pNode<T> merge(pNode<T> first, pNode<T> second) {
    if (first == nullptr) return second;
    if (second == nullptr) return first;

    pNode<T> new_head;
    if (first->value() <= second->value()) {
        new_head = first;
        first = first->next();
    } else {
        new_head = second;
        second = second->next();
    }

    pNode<T> current = new_head;
    while (first != nullptr && second != nullptr) {
        
        pNode<T> temp = nullptr;
        if (first->value() <= second->value()) {
            temp = first;
            first = first->next();
        } else {
            temp = second;
            second = second->next();
        }
        current->setNext(temp);
        current = temp;
    }
    
    if (first != nullptr) {
        current->setNext(first);
    } else if (second != nullptr) {
        current->setNext(second);
    }
    
    return new_head;
}

/** Merge sort routine
 *
 * This sorting is DESTRUCTIVE (as any sorting in the linked list)
 *
 * @param pNode<T> head of the unsorted linked list
 * @returns pNode<T> head of the sorted linked list
 */
template <typename T>
pNode<T> merge_sort (pNode<T> head) {
    if (head == nullptr) return nullptr; // Size 0
    if (head->next() == nullptr) return head; // Size 1

    pNode<T> second_half = split(head); // Split in two

    // Sort the sub-lists:
    pNode<T> l1 = merge_sort(head);
    pNode<T> l2 = merge_sort(second_half);

    // Merge the two and return
    // pNode<T> out = merge(l1, l2);

    return merge(l1, l2);
}


int main() {
    LinkedList<int> list;
    LinkedList<int> sort;

    list.addFront(1);
    list.addFront(2);
    list.addFront(3);
    list.addFront(4);
    list.addFront(5);
    list.addFront(6);
    list.addFront(7);
    list.addFront(8);
    list.addFront(9);

    cout << list << endl;

    sort.setHead(merge_sort(list.head()));

    cout << list << endl;
    cout << sort << endl;
}
