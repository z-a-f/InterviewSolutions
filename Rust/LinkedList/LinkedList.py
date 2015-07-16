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

    def deleteKey(self, key):
        prev = None
        current = self.head()

        while (current != None):
            if (current.value() == key):
                self._size -= 1
                break
            prev = current
            current = current.next()

        # Key not found:
        if current == None:
            return
        
        # If node is found:
        if current == self.head():
            self.setHead(self.head().next())
            return

        prev._next = current.next()

        
    ######################################
    # Internal utilities:
    
    def _reverse_recursive(self, node):
        # Do not check the size = 0 or 1
        if (node == None or node._next == None):
            return node

        reversed_list = self._reverse_recursive(node._next)

        node._next.setNext(node)
        node.setNext(None)

        return reversed_list

"""
Int class
"""
class Int:
    def __init__(self, n = 0):
        try:
            n = int(n)
        except ValueError:
            print ("Int has to be numeric...!")
        else:
            self._num = LinkedList()
            if (n < 0):
                raise ValueError("No support for negative numbers...!")
            while True:
                self._num.addFront(n % 10)
                n = n / 10
                if (n <= 0):
                    break
            self._num.reverse()

    def getHead(self):
        return self._num.head()
        
    def value(self):
        exp = 1
        n = 0
        ptr = self.getHead()
        while (ptr != None):
            n += exp * ptr.value()
            exp *= 10
            ptr = ptr.next()
        return n

    def __add__(self, other):
        a = self._num.head();
        b = other._num.head();

        result = None
        last = None
        carry = 0;

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

        # result is the head of the sum
        temp = Int()
        temp._num.setHead(result)
        return temp

    # def __radd__(self, other):
    #     return self + other
        
    def __str__(self):
        return str(self.value())
    
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

    
    list.deleteKey(0)
    print "\n5)After removing non-existent element:", list

    list.deleteKey(list.head().next().value())
    print "6)After removing existent element:", list

    list.deleteKey(list.head().value())
    print "7)After removing headelement:", list

    A = Int(123)
    B = Int(897)

    print "Integer A:", A
    print "Integer B:", B
    print "Integer A + B:", A + B
    # print "Integer A + B:", sum(A, B)
    
    
