import linkedlist.*;
import java.lang.Comparable;

class solution {
	// This is the solution :)
	public static <T extends Comparable<T>> Node<T> delete_key(Node<T> head, T key) {
		Node<T> prev = null;
		Node<T> current = head;

		while (current != null) {
			if (current.value() == key) {
				break;
			}
			prev = current;
			current = current.next();
		}

		if (current == null) {
			return head;
		}

		if (current == head) {
			return current.next();
		}

		prev.setNext(current.next());

		return head;
	}

	public static void main(String[] args) {
		LinkedList<Integer> list = new LinkedList<Integer>();
		System.out.println(list);

		list.addFront(28);
		list.addFront(21);
		list.addFront(14);
		list.addFront(7);
		System.out.println(list);

		list.setHead(delete_key(list.head(), 0));
		System.out.println(list);

		list.setHead(delete_key(list.head(), 14));
		System.out.println(list);

		list.setHead(delete_key(list.head(), 7));
		System.out.println(list);

		list.setHead(delete_key(list.head(), 28));
		System.out.println(list);
	}
}

	
