"""
Node class
"""
class Node(object):
    def __init__(self, _elem=None, _next=None):
        self._elem = _elem
        self._next = _next

    def __str__(self):
        return str(self._elem)

    # __repr__ = __str__
    
    def value(self):
        return self._elem

    def next(self):
        return self._next

    def setValue(self, e):
        self._elem = e

    def setNext(self, n):
        self._next = n


"""
LinkedList class
"""
class LinkedList(object):
    # Public:
    def __init__(self):
        self._head = None
        self._size = 0

    # Public:
    def empty(self):
        return self.head() == None

    def front(self):
        if self.empty():
            return None
        return self.head().value()

    def addFront(self, e):
        v = Node(e, self.head())
        self.setHead(v)
        self._size += 1        
        
    def removeFront(self):
        if self.empty():
            return
        old = self.head()
        self.setHead(old.next())
        self._size -= 1
        
    # Public (housekeeping):
    def size(self):
        return self._size
    
    def head(self):
        return self._head
    
    def setHead(self, h):
        self._head = h
        
    def __str__(self):
        os = "HEAD->"
        ptr = self.head()
        while (ptr != None):
            os += str(ptr.value()) + "->"
            ptr = ptr.next()
        os += "NULL"
        return os

    # Rust solutions after this point
    def reverse(self):
        # return if the size == 0 or 1
        if (self._head == None or self._head._next == None):
            return

        list_to_do = self._head._next

        reversed_list = self._head
        reversed_list._next = None

        while (list_to_do != None):
            temp = list_to_do
            list_to_do = list_to_do._next

            temp._next = reversed_list
            reversed_list = temp

        self._head = reversed_list

    def reverseRecursive(self):
        self._head = self._reverse_recursive(self._head)

    def _reverse_recursive(self, node):
        # Do not check the size = 0 or 1
        if (node == None or node._next == None):
            return node

        reversed_list = self._reverse_recursive(node._next)

        node._next.setNext(node)
        node.setNext(None)

        return reversed_list

if __name__ == '__main__':
    print "\n1) Testing Node..."
    n = Node('abc', None)
    n.setNext(Node(3, None))
    print "New node n:", n
    print "Next of the n:", n.next()
    
    print "\n2)Testing LinkedList..."
    list = LinkedList()
    print "Initial list is:", list
    print "Front of empty list:", list.front()

    list.addFront(28)
    list.addFront(21)
    list.addFront(14)
    list.addFront(7)
    print "After populating the list:", list
    
    print "\n3) Testing iterative reverse..."
    list.reverse()
    print "After reverse:", list

    print "\n4) Testing recursive reverse..."
    list.reverseRecursive()
    print "After reverse:", list

    