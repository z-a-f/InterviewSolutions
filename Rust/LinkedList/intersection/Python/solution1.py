import sys                      # Need that to set path
sys.path.insert(0, '../..') # Need that to import LL

from LinkedList import *    # Linked LIst defined here

def sorted_insert(head, node):
    if node == None:
        return head

    if head == None or node.value() <= head.value():
        node.setNext(head)
        return node

    curr = head
    while curr.next() != None and curr.next().value() < node.value():
        curr = curr.next()

    node.setNext(curr.next())
    curr.setNext(node)

    return head

def insertion_sort(head):
    sorted = None
    curr = head

    while curr != None:
        temp = curr.next()
        sorted = sorted_insert(sorted, curr)
        curr = temp

    return sorted

if __name__ == '__main__':
    list = LinkedList()
    sort = LinkedList()

    list.addFront(11)
    list.addFront(82)
    list.addFront(23)
    list.addFront(29)

    print list
    sort.setHead(insertion_sort(list.head()))
    print sort
    print list

