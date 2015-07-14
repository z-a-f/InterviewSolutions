package LinkedListJava;

import java.lang.RuntimeException;

public class Int {
	private LinkedList<Integer> _num;
	public Int(Integer n) {
		this._num = new LinkedList<Integer>();
		if (n < 0)
			throw new RuntimeException("No support for negative numbers...!");
		do {
			this._num.addFront(n % 10);
			n = n / 10;
		} while (n > 0);
		this._num.reverse();
	}

	public Node<Integer> getHead() {
		return this._num.head();
	}

	@Override
	public String toString() {
		return String.valueOf(this.value());
	}

	// @Override
	public Integer value () {
		Node<Integer> ptr = this.getHead();
		int counter = 1;
		int number = 0;
		while (ptr != null) {
			number = counter * ptr.value();
			ptr = ptr.next();
			counter *= 10;
		}
		return number;
	}
	
	
	/*
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
	*/
}
