import LinkedListJava.*;

class solution {
	// This is the solution :)
	public static Node<Integer> add_integer (Node<Integer> a, Node<Integer> b) {
		Node<Integer> result = null;
		Node<Integer> last = null;
		int carry = 0;

		while (a != null || b != null || carry > 0) {
			int first = (a == null ? 0 : a.value());
			int second = (b == null ? 0 : b.value());
			int sum = first + second + carry;
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
		return result;
	}

	public static void main(String[] args) {
		LinkedList<Integer> a = new LinkedList<Integer>();
		a.addFront(1);
		a.addFront(2);
		a.addFront(3);
		System.out.println("Integer a: " + a);

		LinkedList<Integer> b = new LinkedList<Integer>();
		b.addFront(8);
		b.addFront(9);
		b.addFront(7);
		System.out.println("Integer b: " + b);

		LinkedList<Integer> c = new LinkedList<Integer>();
		c.setHead(add_integer(a.head(), b.head()));
		System.out.println("Integer a + b: " + c);
	}
}

	
