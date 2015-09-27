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

template <typename T>
int find_length(pNode<T> head) {
    int len = 0;
    pNode<T> ptr = head;
    while (ptr  != nullptr) {
        ++len;
        ptr = ptr->next();
    }
    return len;
}

int adjust_rotation_needed(int n, int len) {
    n = n % len;
    if (n < 0) {
        n += len;
    }

    return n;
}

template <typename T>
pNode<T> rotate(pNode<T> head, int n) {
    if (head == nullptr || n == 0) {
        return head;
    }

    int len = find_length(head);

    // If n (number of rotations required) is bigger than
    // the length of the linked list or if n is negative,
    // then we need to adjust it
    n = adjust_rotation_needed(n, len);

    if (n == 0) return head;

    // Find the star of rotated list
    // If we have 1, 2, 3, 4, 5, and n = 2,
    // 4 is the start of the rotated list
    int rotations_count = len - n - 1;
    pNode<T> temp = head;

    while (rotations_count > 0) {
        rotations_count--;
        temp = temp->next();
    }

    // After the loop is complete
    pNode<T> new_head = temp->next();

    // Set new end of list:
    temp->setNext(nullptr);

    // Iterate to the end of the list and
    // link that to original head
    temp = new_head;
    while (temp->next() != nullptr) {
        temp = temp->next();
    }
    temp->setNext(head);

    return new_head;
}

int main() {
    LinkedList<int> list;

    list.addFront(7);
    list.addFront(6);
    list.addFront(5);
    list.addFront(4);
    list.addFront(3);
    list.addFront(2);
    list.addFront(1);

    cout << list << endl;

    list.setHead(rotate(list.head(), -8));

    cout << list << endl;

    
    return 0;
}
        
