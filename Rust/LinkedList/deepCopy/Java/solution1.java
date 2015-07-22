import LinkedListJava.*;

class solution1 {
	// This is the solution :)
	public static <T> Node<T> deep_copy_arbitrary_pointer(Node<T> head) {
		if (head == null) {
			return nullptr;
		}

		Node<T> current = head;
		Node<T> new_head = null;
		Node<T> new_prev = null;
		Hashtable<Node<T>, Node<T>> map = new Hashtable<Node<T>, Node<T>>();
	}

	public static void main(String[] args) {
		LinkedList<int> listArb;
		listArb.addFront(21);
		listArb.addFront(14);
		listArb.addFront(7);
		listArb.head()->setArb(listArb.head()->next()->next());
		listArb.head()->next()->next()->setArb(listArb.head());
		cout << listArb << endl;

		LinkedList<int> listArbCopy;
		listArbCopy.setHead(deep_copy_arbitrary_pointer(listArb.head()));

		// Change some stuff to check if the linked lists are really separate
		listArbCopy.head()->next()->setValue(123);
		listArb.head()->setValue(321);
  
		cout << listArbCopy << endl;
		cout << listArb << endl;
	}
}

	
