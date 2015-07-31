package LinkedListJava;

public class Node<T extends Comparable<T>> {
	public Node(T e, Node<T> n, Node<T> a) {
		this._next = n;
		this._elem = e;
		this._arb = a;
	}
	public Node(T e, Node<T> n) {
		this._next = n;
		this._elem = e;
		this._arb = null;
	}
	public Node(T e) {
		this._next = null;
		this._elem = e;
		this._arb = null;
	}
	public Node() {
		this._next = null;
		this._arb = null;
		// this._elem = 0;
	}

	public T value() { return this._elem; }
	public Node<T> next() { return this._next; }
	public Node<T> arb() { return this._arb; }
	public void setValue(T e) { this._elem = e; }
	public void setNext(Node<T> n) { this._next = n; }
	public void setArb(Node<T> n) { this._arb = n; }
	
	protected T _elem;
	protected Node<T> _next;
	protected Node<T> _arb;

	// Linked List is friend as long as it is in the same package
}
