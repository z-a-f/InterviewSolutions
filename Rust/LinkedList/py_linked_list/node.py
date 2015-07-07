
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


if __name__ == '__main__':
    n = Node('abc', None)
    n.setNext(Node(3, None))
    print n
    print n.next()
