package LinkedListJava;

import java.lang.RuntimeException;

class Node<T> {
	
	public Node() {
		this._next = null;
		// this._elem = 0;			
	}

	public T value() { return this._elem; }
	public Node<T> next() { return this._next; }
	public void setValue(T e) { this._elem = e; }
	public void setNext(Node<T> n) { this._next = n; }

	protected T _elem;
	protected Node<T> _next;

	// Linked List is friend as long as it is in the same package
}


public class LinkedList<T> {
	private Node<T> _head;
	private Integer _size;

	// Constructor
	public LinkedList() {
		this._head = null;
		this._size = 0;
	}

	public Boolean empty() { return this.size() == 0; }
	public Integer size() { return this._size; }

	public T front() {
		if (this.empty()) throw new RuntimeException("Cannot get front() of an empty list...");
		return this._head._elem;
	}

	public static void main(String[] args) {
		LinkedList<Integer> list = new LinkedList<>();
		try {
			list.front();
		} catch (Exception e) {
			System.out.println ("Exception: " + e);
		}
	}
}

