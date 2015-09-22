package linkedlist;

import java.util.Hashtable;
import java.lang.RuntimeException;
import java.lang.Comparable;


public class LinkedList<T extends Comparable<T>> {
    private Node<T> _head;
    // private Integer _size;

    // Constructor
    public LinkedList() {
        this._head = null;
        // this._size = 0;
    }

    public Node<T> head() { return this._head; }
    public void setHead(Node<T> h) { this._head = h; }
    public Boolean empty() { return this.size() == 0; }
    // public Integer size() { return this._size; }
    public int size() {
        int list_length = 0;
        Node<T> head = this.head();
        while (head != null) {
            head = head.next();
            list_length++;
        }
        return list_length;
    }

    public T front() {
        if (this.empty())
            throw new RuntimeException("Cannot get front() of an empty list...");
        return this._head._elem;
    }

    public void addFront(T e) {
        Node<T> v = new Node<T>();
        v._elem = e;
        v._next = this._head;
        this._head = v;
        // this._size++;
    }

    public void removeFront() {
        if(this.empty()) return;
        Node<T> old = this._head;
        this._head = old._next;
        // this._size--;
    }

    // This is the printing routine:
    @Override
    public String toString() {

        String os = "HEAD->";
        Node<T> ptr = this._head;
        while (ptr != null) {
            os += ptr._elem+"->";
            ptr = ptr._next;
        }
        os += "NULL";
        return os;
        /*
          String os = "[HEAD]\n V\n";
          Node<T> ptr = this._head;
          while (ptr != null) {
          os += "[" + ptr._elem + "]->";
          os += "[";
          if (ptr.arb() == null)
          os += "NULL";
          else
          os += ptr.arb()._elem + "|" + ptr.arb().hashCode();

          os += "]\n V\n";
          ptr = ptr.next();
          }
          os += "[NULL]";
          return os;
        */}

    /* Rust solutions here */

    // Iterative reverse:
    public void reverse() {
        // Do nothing if the size = 0 or 1
        if (this._head == null || this._head._next == null)
            return;

        Node<T> list_to_do = this._head._next;
        // Node<T> reversed_list = head;

        this._head._next = null;

        while (list_to_do != null) {
            Node<T> temp = list_to_do;
            list_to_do = list_to_do.next();

            temp._next = this._head;
            this._head = temp;
        }
    }

    // Recursive reverse:
    public void reverseRecursive() {
        this._head = _reverse_recursive(this._head);
    }

    // delete by key:
    public void deleteKey(T key) {
        Node<T> prev = null;
        Node<T> current = this._head;

        while (current != null) {
            if (current.value() == key) {
                // this._size--;
                break;
            }
            prev = current;
            current = current.next();
        }

        if (current == null) {
            return;
        }

        if (current == this._head) {
            this._head = current.next();
            return;
        }

        prev.setNext(current.next());
    }

    public LinkedList<T> deepCopy() {
        LinkedList<T> copy = new LinkedList<>();
        copy.setHead(this._deep_copy_2(this.head()));
        return copy;
    }

    public void sort() {
        this.setHead(this._insertion_sort(this.head()));
        // System.out.println("This function is still not implemented!");
        // System.out.println("Still need to figure out the Comparable");
    }

    public Node<T> intersects (LinkedList<T> list) {
        Node<T> l1 = null;
        Node<T> l2 = null;

        int d = this.size() - list.size();

        l1 = (d >= 0) ? this.head() : list.head();
        l2 = (d >= 0) ? list.head() : this.head();
        d = (d >= 0) ? d : -d;

        while (d > 0) {
            l1 = l1.next();
            d--;
        }

        while (l1 != null) {
            if (l1 == l2) {
                return l1;
            }
            l1 = l1.next();
            l2 = l2.next();
        }
        return null;
    }
    
    
    //////////////////////////////////////
    // Helper utilities
    private Node<T> _reverse_recursive(Node<T> node) {
        if (node == null || node._next == null)
            return node;

        Node<T> reversed_list = _reverse_recursive(node._next);

        node._next._next = node;
        node._next = null;

        return reversed_list;
    }

    private Node<T> _deep_copy_1(Node<T> head) {
        if (head == null) {
            return null;
        }

        Node<T> current = head;
        Node<T> new_head = null;
        Node<T> new_prev = null;
        Hashtable<Node<T>, Node<T>> map = new Hashtable<Node<T>, Node<T>>();

        // Create copy of the linked list, recording the corresponding
        // nodes is hashmap without updating arbitrary pointer
        while (current != null) {
            Node<T> new_node = new Node<T>(current.value());

            // copy the old arbitrary pointer in the new node
            new_node.setArb(current.arb());

            if (new_prev != null) {
                new_prev.setNext(new_node);
            } else {
                new_head = new_node;
            }

            map.put(current, new_node);

            new_prev = new_node;
            current = current.next();
        }

        Node<T> new_current = new_head;

        // updating arbitrary_pointer
        while (new_current != null) {
            if (new_current.arb() != null) {
                Node<T> node = map.get(new_current.arb());
                new_current.setArb(node);
            }

            new_current = new_current.next();
        }

        return new_head;
    }

    private Node<T> _deep_copy_2(Node<T> head) {
        if (head == null) {
            return null;
        }

        Node<T> current = head;

        // inserting new nodes within the existing linkedlist
        while (current != null) {
            Node<T> new_node = new Node<T>(current.value());
            new_node.setNext(current.next());
            current.setNext(new_node);
            current = new_node.next();
        }

        // Setting correct arbitrary pointers:
        current = head;
        while (current != null) {
            if (current.arb() != null) {
                current.next().setArb(current.arb().next());
            }
            current = current.next().next();
        }

        // separating lists
        current = head;
        Node<T> new_head = head.next();
        Node<T> copied_current = new_head;

        while (current != null) {
            copied_current = current.next();
            current.setNext(copied_current.next());
            if (copied_current.next() != null) {
                copied_current.setNext(copied_current.next().next());
            }
            current = current.next();
        }

        return new_head;
    }
    
    private Node<T> _sorted_insert(Node<T> head, Node<T> node) {
        if (node == null) return head;

        if (head == null || node.value().compareTo(head.value()) <= 0) {
            node.setNext(head);
            return node;
        }

        Node<T> curr = head;

        while (curr.next() != null && (curr.next().value().compareTo(node.value()) < 0))
            curr = curr.next();

        node.setNext(curr.next());
        curr.setNext(node);

        return head;
    }

    private Node<T> _insertion_sort (Node<T> head) {
        Node<T> sorted = null;
        Node<T> curr = head;

        while (curr != null) {
            Node<T> temp = curr.next();
            sorted = this._sorted_insert(sorted, curr);
            curr = temp;
        }
        return sorted;
    }
    
}
