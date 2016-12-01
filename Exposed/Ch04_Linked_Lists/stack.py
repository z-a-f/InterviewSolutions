#!/usr/bin/env python

## Simple Linked List Node
class Node(object):
  def __init__(self, value = 0, next = None):
    self.value = value
    self.next = next

class Stack(object):
  def __init__(self):
    self.size = 0
    self.__head = None

  def push(self, value):
    node = Node(value, self.__head)
    self.__head = node
    self.size += 1

  def pop(self):
    if self.size == 0:
      return None
    node = self.__head
    self.__head = self.__head.next
    self.size -= 1
    return node.value

  def peek(self):
    if self.size == 0:
      return None
    return self.__head.value

  def __repr__(self):
    res = 'STACK->['
    if self.size == 0:
      res += 'EMPTY'
    else:
      node = self.__head
      while node is not None:
        res += repr(node.value)+','
        node = node.next
    return res+']'

if __name__ == '__main__':
  st = Stack()

  st.push(1)
  st.push('a')
  st.push(32)
  st.push([1,2,3])
  print st
  print st.peek()
  print st.pop()
  print st.pop()
  print st
