"""@package customLibs

LinkedList and node package
"""

## Node class
#
# This is a generic node for singly linked list
class Node(object):
    ## Default constructor
    # 
    # @param _elem The value stored in the node
    # @param _next Pointer to the next node
    def __init__(self, _elem=None, _next=None):
        self._elem = _elem
        self._next = _next
        self._arb = None

    ## toString overloader
    #
    # Shows the value stored in the node
    # @returns _elem The internal value (String)
    def __str__(self):
        return str(self._elem)

    # __repr__ = __str__

    ## Return the value
    #
    # @return _elem The internal value
    def value(self):
        return self._elem

    ## Next node
    #
    # Returns the pointer to the next node
    # @returns _next The next Node object
    def next(self):
        return self._next

    ## Arbitrary pointer
    #
    # @returns _arb Pointer to an arbitrary Node
    def arb(self):
        return self._arb

    ## Set the stored value
    #
    # Changes the internal value self._elem
    # @param e New element
    def setValue(self, e):
        self._elem = e

    ## Set the next pointer
    #
    # @param n Next node pointer
    def setNext(self, n):
        self._next = n

    ## Set the arbitrary pointer
    #
    # @param n Arbitrary node pointer
    def setArb(self, n):
        self._arb = n
    
    # def DEBUG(self):
    #     temp = self
    #     while temp._next != None:
    #         print '[', temp.value(), "]->",
    #         temp = temp._next
    #     print '[', temp.value(), ']'


## Linked List class
#
# Generic linked list class
class LinkedList(object):
    ## Default constructor
    def __init__(self):
        self._head = None
        # self._size = 0

    ## Check if the list is empty
    #
    # @returns Boolean 
    def empty(self):
        return self.head() == None

    ## Return the value of the front
    #
    # @returns _elem The value of the head
    def front(self):
        if self.empty():
            return None
        return self.head().value()

    def addFront(self, e):
        v = Node(e, self.head())
        self.setHead(v)
        # self._size += 1

    def removeFront(self):
        if self.empty():
            return
        old = self.head()
        self.setHead(old.next())
        # self._size -= 1

    # Public (housekeeping):
    def size(self):
        list_length = 0
        head = self.head()
        while head != None:
            head = head.next()
            list_length += 1
        return list_length
        # return self._size

    def head(self):
        return self._head

    def setHead(self, h):
        self._head = h

    def clear(self):
        while not self.empty():
            self.removeFront()

    def __str__(self):
        os = "HEAD->"
        ptr = self.head()
        while (ptr != None):
            os += str(ptr.value()) + "->"
            ptr = ptr.next()
        os += "NULL"
        return os

if __name__ == '__main__':
    print "This package is not suited to be called :)))"
