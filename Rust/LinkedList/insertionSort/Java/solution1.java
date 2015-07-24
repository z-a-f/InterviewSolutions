import LinkedListJava.*;
import java.util.Hashtable;

class solution1 {
	// This is the solution :)
	public static <T> Node<T> deep_copy_arbitrary_pointer(Node<T> head) {
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

	
