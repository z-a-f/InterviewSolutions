import LinkedListJava.*;

class solution1 {
	// This is the solution :)
	public static <T> Node<T> reverse_iterative(Node<T> head) {
		// Do nothing if the size = 0 or 1
		if (head == null || head.next() == null)
			return head;

		Node<T> list_to_do = head.next();
		Node<T> reversed_list = head;

		reversed_list.setNext(null);

		while (list_to_do != null) {
			Node<T> temp = list_to_do;
			list_to_do = list_to_do.next();

			temp.setNext(reversed_list);
			reversed_list = temp;
		}
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

		list.setHead(reverse_iterative(list.head()));
		System.out.println(list);
		
	}
}

	
