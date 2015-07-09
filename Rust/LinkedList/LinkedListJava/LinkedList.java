package LinkedListJava;

import java.lang.RuntimeException;

public class LinkedList<T> {
	private Node<T> _head;
	private Integer _size;

	// Constructor
	public LinkedList() {
		this._head = null;
		this._size = 0;
	}

	public Node<T> head() { return this._head; }
	public void setHead(Node<T> h) { this._head = h; }
	public Boolean empty() { return this.size() == 0; }
	public Integer size() { return this._size; }

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
		this._size++;
	}

	public void removeFront() {
		if(this.empty()) return;
		Node<T> old = this._head;
		this._head = old._next;
		this._size--;
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
	}

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

	// Recursive helper:
	private Node<T> _reverse_recursive(Node<T> node) {
		if (node == null || node._next == null)
			return node;

		Node<T> reversed_list = _reverse_recursive(node._next);

		node._next._next = node;
		node._next = null;

		return reversed_list;
	}
}

