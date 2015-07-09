import LinkedListJava.*;

class solution2 {
	// This is the solution :)
	public static <T> Node<T> reverse_recursive(Node<T> head) {
		// Do nothing if the size = 0 or 1
		if (head == null || head.next() == null)
			return head;

		Node<T> reversed_list = reverse_recursive(head.next());

		head.next().setNext(head);
		head.setNext(null);
		
		return reversed_list;
	}

	public static void main(String[] args) {
		LinkedList<Integer> list = new LinkedList<Integer>();
		System.out.println(list);

		list.addFront(28);
		list.addFront(21);
		list.addFront(14);
		list.addFront(7);
		System.out.println(list);

		list.setHead(reverse_recursive(list.head()));
		System.out.println(list);
		
	}
}

	
