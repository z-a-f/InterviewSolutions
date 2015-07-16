import sys                      # Need that to set path
sys.path.insert(0, '../..')     # Need that to import LL

from LinkedList import *    # Linked List defined here

def add_integers(a, b):
    result = None
    last = None
    carry = 0

    while (a != None or b != None or carry > 0):
        first = (0 if a == None else a.value())
        second = (0 if b == None else b.value())
        sum = first + second + carry
        pNew = Node(sum % 10)
        carry = sum / 10
        if result == None:
            result = pNew
        else:
            last.setNext(pNew)

        last = pNew
        if a != None:
            a = a.next()

        if b != None:
            b = b.next()

    return result


if __name__ == '__main__':
    a = LinkedList()
    a.addFront(1)
    a.addFront(2)
    a.addFront(3)
    print "Integer a:", a
    
    b = LinkedList()
    b.addFront(8)
    b.addFront(9)
    b.addFront(7)
    print "Integer b:", b

    c = LinkedList()
    c.setHead(add_integers(a.head(), b.head()))
    print "Integer a + b:", c
