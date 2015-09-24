import sys                      # Need that to set path
sys.path.insert(0, '../../../Library/Python') # Need that to import LL

from LinkedList import *    # Linked LIst defined here

def removeDuplicates(head):
    if head == None:
        return head

    dup_set = set()

    dup_set.add(head.value())
    curr = head

    while curr.next() != None:
        if curr.next().value() not in dup_set:
            # Element not found, add it to the hashset
            dup_set.add(curr.next().value())
            curr = curr.next()
        else:
            curr.setNext(curr.next().next())

    return head

if __name__ == '__main__':
    list = LinkedList()

    list.addFront(7)
    list.addFront(4)
    list.addFront(9)
    list.addFront(4)
    list.addFront(7)
    list.addFront(4)

    print list
    list.setHead(removeDuplicates(list.head()))
    print list
