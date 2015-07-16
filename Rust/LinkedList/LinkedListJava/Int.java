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
	public Int() {
		this._num = new LinkedList<Integer>();
		this._num.addFront(0);
	}

	public Node<Integer> getHead() {
		return this._num.head();
	}

	public void add (Int A, Int B) {
		Node<Integer> a = A._num.head();
		Node<Integer> b = B._num.head();
	
		Node<Integer> result = null;
		Node<Integer> last = null;
		int carry = 0;

		while (a != null || b != null || carry > 0) {
			Integer first = (a == null ? 0 : a.value());
			Integer second = (b == null ? 0 : b.value());
			Integer sum = first + second + carry;
			Node<Integer> pNew = new Node<Integer>(sum % 10);
			carry = sum / 10;
			if (result == null) {
				result = pNew;
			} else {
				last.setNext(pNew);
			}

			last = pNew;
			if (a != null) {
				a = a.next();
			}
			if (b != null) {
				b = b.next();
			}
		}

		this._num.setHead(result);
		// return temp;
	}

	@Override
	public String toString() {
		return String.valueOf(this.value());
	}

	// @Override
	public Integer value () {
		Node<Integer> ptr = this.getHead();
		Integer exp = 1;
		Integer n = 0;
		while (ptr != null) {
			n += exp * ptr.value();
			exp *= 10;
			ptr = ptr.next();
		}
		return n;
	}
}

