import sys                      # Need that to set path
sys.path.insert(0, '../..') # Need that to import LL

from LinkedList import *    # Linked LIst defined here

def split(head):
    slow = head
    fast = head.next()

    while (fast != None):
        fast = fast.next()
        if (fast != None):
            fast = fast.next()
            slow = slow.next()

    fast = slow.next()
    slow.setNext(None)

    return fast

def merge(first, second):
    if (first == None): return second
    if (second == None): return first

    # new_head = Node()
    if (first.value() <= second.value()):
        new_head = first
        first = first.next()
    else:
        new_head = second
        second = second.next()

    current = new_head
    while (first != None) and (second != None):
        temp = None
        if (first.value() <= second.value()):
            temp = first
            first = first.next()
        else:
            temp = second
            second = second.next()
        current.setNext(temp)
        current = temp

    if (first != None):
        current.setNext(first)
    elif (second != None):
        current.setNext(second)

    return new_head

def merge_sort(head):
    if (head == None): return None
    if (head.next() == None): return head

    second_half = split(head)

    l1 = merge_sort(head)
    l2 = merge_sort(second_half)

    return merge(l1,l2)

            
if __name__ == '__main__':
    list = LinkedList()
    sort = LinkedList()

    list.addFront(1)
    list.addFront(2)
    list.addFront(3)
    list.addFront(5)
    list.addFront(6)
    list.addFront(7)
    list.addFront(8)
    list.addFront(9)
    

    print list
    sort.setHead(merge_sort(list.head()))
    print list
    print sort

