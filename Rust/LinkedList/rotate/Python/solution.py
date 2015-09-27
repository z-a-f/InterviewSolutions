import sys                      # Need that to set path
sys.path.insert(0, '../../../Library/Python') # Need that to import LL

from LinkedList import *    # Linked LIst defined here

def find_length(head):
    len = 0
    ptr = head
    while (ptr != None):
        len += 1
        ptr = ptr.next()
    return len

def adjust_rotation_needed(n, len):
    n = n % len
    if n < 0: n += len
    return n

def rotate(head, n):
    if head == None or n == 0:
        return head

    len = find_length(head)

    n = adjust_rotation_needed(n, len)

    if n == 0: return head

    rotations_count = len - n - 1
    temp = head

    while rotations_count > 0:
        rotations_count -= 1
        temp = temp.next()

    new_head = temp.next()

    temp.setNext(None)

    temp = new_head
    while temp.next() != None:
        temp = temp.next()
    temp.setNext(head)

    return new_head

if __name__ == '__main__':
    list = LinkedList()
    
    list.addFront(7)
    list.addFront(6)
    list.addFront(5)
    list.addFront(4)
    list.addFront(3)
    list.addFront(2)
    list.addFront(1)

    print list
    list.setHead(rotate(list.head(), -8))
    print list
    
