package LinkedListJava;

public class Node<T> {
	
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
