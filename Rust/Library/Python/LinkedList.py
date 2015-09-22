"""
Node class
"""
class Node(object):
    def __init__(self, _elem=None, _next=None):
        self._elem = _elem
        self._next = _next
        self._arb = None

    def __str__(self):
        return str(self._elem)

    # __repr__ = __str__

    def value(self):
        return self._elem

    def next(self):
        return self._next

    def arb(self):
        return self._arb

    def setValue(self, e):
        self._elem = e

    def setNext(self, n):
        self._next = n

    def setArb(self, n):
        self._arb = n


"""
LinkedList class
"""
class LinkedList(object):
    # Public:
    def __init__(self):
        self._head = None
        # self._size = 0

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

    def __str__(self):
        os = "HEAD->"
        ptr = self.head()
        while (ptr != None):
            os += str(ptr.value()) + "->"
            ptr = ptr.next()
        os += "NULL"
        return os
        # os = "[HEAD]\n V\n"
        # ptr = self.head()
        # while (ptr != None):
        #     os += "[" + str(ptr._elem) + "]->";
        #     os += "[";
        #     if (ptr.arb() == None):
        #         os += "NULL"
        #     else:
        #         os += (str(ptr.arb()._elem) + "|" + str(id(ptr.arb())))
        #     os += "]\n V\n"
        #     ptr = ptr.next()
        # os += "[NULL]"
        # return os

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
                # self._size -= 1
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

    def deepCopy(self):
        copy = LinkedList()
        copy.setHead(self._deep_copy_2(self.head()))
        return copy

    def sort(self):
        # self.setHead(self._insertion_sort(self.head()))
        self.setHead(self._merge_sort(self.head()))

    def intersects(self, list):
        l1 = None
        l2 = None

        d = self.size() - list.size()

        l1 = self.head() if d >= 0 else list.head()
        l2 = list.head() if d >= 0 else self.head()
        d = d if d >= 0 else -d

        while d > 0:
            l1 = l1.next()
            d -= 1

        while l1 != None:
            if l1 == l2:
                return l1
            l1 = l1.next()
            l2 = l2.next()

        return None
        
        
        

        
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

    def _deep_copy_1(self, head):
        if head == None:
            return None

        current = head
        new_head = None
        new_prev = None
        ht = dict()

        # Create copy of the linked list, recording the corresponding
        # nodes in hashmap without updating arbitrary pointer
        while current != None:
            new_node = Node(current.value())

            # copy the old arbitrary pointer in the new node
            new_node.setArb(current.arb())

            if new_prev != None:
                new_prev.setNext(new_node)
            else:
                new_head = new_node

            ht[current] = new_node

            new_prev = new_node
            current = current.next();

        new_current = new_head

        # updating arbitrary pointer
        while new_current != None:
            if new_current.arb() != None:
                node = ht[new_current.arb()]
                new_current.setArb(node)
            new_current = new_current.next()

        return new_head

    def _deep_copy_2(self, head):
        if head == None:
            return None

        current = head

        # inserting new nodes within the existing linkedlist
        while current != None:
            new_node = Node(current.value())

            new_node.setNext(current.next())
            current.setNext(new_node)
            current = new_node.next()

        # setting correct arbitrary pointers
        current = head
        while current != None:
            if current.arb() != None:
                current.next().setArb(current.arb().next())

            current = current.next().next()

        # separating lists
        current = head
        new_head = head.next()
        copied_current = new_head

        while current != None:
            copied_current = current.next()
            current.setNext(copied_current.next())

            if copied_current.next() != None:
                copied_current.setNext(copied_current.next().next())

            current = current.next()

        return new_head

    def _sorted_insert(self, head, node):
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

    def _insertion_sort(self, head):
        sorted = None
        curr = head

        while curr != None:
            temp = curr.next()
            sorted = self._sorted_insert(sorted, curr)
            curr = temp

        return sorted

    def _split(self, head):
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

    def _merge(self, first, second):
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

    def _merge_sort(self, head):
        if (head == None): return None
        if (head.next() == None): return head

        second_half = self._split(head)

        l1 = self._merge_sort(head)
        l2 = self._merge_sort(second_half)

        return self._merge(l1,l2)
    
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
    print "This package is not suited to be called :)))"
