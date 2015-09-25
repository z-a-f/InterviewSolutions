#include <iostream>
#include <unordered_set>

#include "../../../Library/C++/LinkedList.hpp"

template <typename T> using pNode = std::shared_ptr< Node<T> >; // This is just for convenience
using namespace std;

// Debug routine:
template <typename T>
void DEBUG(pNode<T> head) {
    if (head == nullptr)
        cout << "[NULL]" << endl;
    pNode<T> ptr = head;
    while (ptr != nullptr) {
        cout << "[" << ptr->value() << "]->";
        ptr = ptr->next();
    }
    cout << endl;
}

/** Split the linked list into two
 *
 * This method gets all the odd values, and keeps them in the original, 
 * while returning the head of another linked list with all the even elements
 *
 * @param pNode<T> head of the original linked list (std::shared_ptr<Node<T>>)
 * @returns pNode<T> the head of all the even elements
 */
template <typename T>
pNode<T> split_odd_even(pNode<T> head) {
    if (head == nullptr) return nullptr;
    pNode<T> curr = head;
    pNode<T> even = head->next();
    pNode<T> tail = even;
    
    while (curr != nullptr && curr->next() != nullptr) {
        pNode<T> temp = curr->next();

        curr->setNext(temp->next());
        curr = curr->next();
        
        // Push at the beginning (You can push in the end to avoid the reversing later):
        // temp->setNext(nullptr);
        tail->setNext(temp);
        tail = tail->next();
        
    }
    if (tail != nullptr) tail->setNext(nullptr);
    return even;
}

/** Merge two linked lists, while alternating the nodes
 *
 * @param pNode<T> head1 of the first linked list (std::shared_ptr<Node<T>>)
 * @param pNode<T> head2 of the second linked list (std::shared_ptr<Node<T>>)
 * @returns pNode<T> head of the merged linked list (std::shared_ptr<Node<T>>)
 */
template <typename T>
pNode<T> merge_alternating (pNode<T> head1, pNode<T> head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    pNode<T> head = head1;
    while (head1->next() != nullptr && head2 != nullptr) {
        pNode<T> temp = head2;
        head2 = head2->next();

        temp->setNext(head1->next());
        head1->setNext(temp);
        head1 = temp->next();
    }

    if (head1->next() == nullptr) head1->setNext(head2);

    return head;
}

/* Reverse Even nodes
 *
 * This is the extension to the first version of the code
 * It avoids the requirement to reverse the result after
 * the whole thing
 */
template <typename T>
pNode<T> reverse_even_nodes(pNode<T> head) {
    // Extract even nodes from teh existing list and create a new list consisting of even nodes.
    // Push the even nodes in a reverse order to keep them in a reverse order
    pNode<T> curr = head;
    pNode<T> list_even = nullptr;

    while (curr != nullptr && curr->next() != nullptr) {
        pNode<T> even = curr->next();
        curr->setNext(even->next());

        // Push at the head of the new list
        even->setNext(list_even);
        list_even = even;

        curr = curr->next();
    }

    return merge_alternating(head, list_even);
}


int main() {
    LinkedList<int> list;
    LinkedList<int> even;
    list.addFront(7);
    list.addFront(6);
    list.addFront(5);
    list.addFront(4);
    list.addFront(3);
    list.addFront(2);
    list.addFront(1);

    // DEBUG(list.head());
    cout << list << endl;
    
    even.setHead(split_odd_even(list.head()));
    // cout << list << endl;
    
    DEBUG(list.head());
    DEBUG(even.head());
    
    even.reverse();
    cout << list << endl;
    cout << even << endl;
    
    list.setHead(merge_alternating(list.head(), even.head()));

    cout << list << endl;
    
    // even.setHead(reverse_even_nodes(list.head()));
    // cout << even << endl;
    return 0;
}
