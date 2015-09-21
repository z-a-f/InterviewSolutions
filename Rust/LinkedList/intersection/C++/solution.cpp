#include <iostream>

#include "../../LinkedList.hpp"

// template <typename T> using pNode = std::shared_ptr< Node<T> >;
using namespace std;

template <typename T>
static std::size_t size(std::shared_ptr< Node<T> > head) {
    std::size_t list_length = 0;
    while (head != nullptr) {
        head = head->next();
        list_length++;
    }
    return list_length;
}

template <typename T>
std::shared_ptr< Node<T> > intersects (
                                       std::shared_ptr< Node<T> > head1,
                                       std::shared_ptr< Node<T> > head2) {
    // std::shared_ptr< Node<T> > l1 = nullptr;
    // std::shared_ptr< Node<T> > l2 = nullptr;

    size_t l1len = size(head1);
    size_t l2len = size(head2);

    int d = l1len - l2len;
    std::shared_ptr< Node<T> > l1 = d >= 0 ? head1 : head2;
    std::shared_ptr< Node<T> > l2 = d >= 0 ? head2 : head1;
    d = d >= 0 ? d : -d;

    while (d > 0) {
        l1 = l1->next();
        d--;
    }

    while (l1 != nullptr) {
        // cout << l1->value() << " " << l2->value() << endl;
        if (l1 == l2) {
            return l1;
        }
        l1 = l1->next();
        l2 = l2->next();

    }
    return nullptr;    
}

int main() {
    LinkedList<int> list1;
    LinkedList<int> list2;

    list1.addFront(27);
    list1.addFront(12);
    list1.addFront(23);
    list1.addFront(29);

    list2.addFront(4);
    list2.addFront(13);

    list2.head()->next()->setNext(list1.head()->next()->next());

    cout << list1 << endl;
    cout << list2 << endl;

    std::shared_ptr< Node<int> > intsct = intersects(list1.head(), list2.head());

    if (intsct == nullptr) cout << "NULL" << endl;
    else cout << intsct->value() << endl;

    LinkedList<int> list3;
    list3.addFront(27);
    list3.addFront(12);
    list3.addFront(23);
    list3.addFront(29);
    intsct = intersects(list1.head(), list3.head());
    if (intsct == nullptr) cout << "NULL" << endl;
    else cout << intsct->value() << endl;
    
    return 0;
}
