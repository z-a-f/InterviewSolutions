import LinkedListJava.*;
import java.util.Hashtable;

class solution2 {
	// This is the solution :)
	public static <T> Node<T> deep_copy_arbitrary_pointer(Node<T> head) {
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

	public static void main(String[] args) {
		LinkedList<Integer> listArb = new LinkedList<>();
		listArb.addFront(21);
		listArb.addFront(14);
		listArb.addFront(7);
		listArb.head().setArb(listArb.head().next().next());
		listArb.head().next().next().setArb(listArb.head());
		// cout << listArb << endl;
		System.out.println("List with arbitrary pointers:\n" + listArb);

		LinkedList<Integer> listArbCopy = new LinkedList<>();
		listArbCopy.setHead(deep_copy_arbitrary_pointer(listArb.head()));

		// Change some stuff to check if the linked lists are really separate
		listArbCopy.head().next().setValue(123);
		listArb.head().setValue(321);

		System.out.println("Updated List with arbitrary pointers:\n" + listArb);
		System.out.println("Copied List with arbitrary pointers:\n" + listArbCopy);

	}
}

	
