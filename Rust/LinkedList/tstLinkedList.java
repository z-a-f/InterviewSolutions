import LinkedListJava.*;

public class tstLinkedList{
	public static void main(String[] args) {
		LinkedList<Integer> list = new LinkedList<>();
		try {
			list.front();
		} catch (Exception e) {
			System.out.println ("Exception: " + e);
		}
		// Node<Integer> head = new Node<Integer>();
		// list.setHead(head);

		System.out.println("Empty list: " + list);
		list.addFront(28);
		list.addFront(21);
		list.addFront(14);
		list.addFront(7);
		System.out.println("Initial list: " + list);
		list.removeFront();
		System.out.println("After removing front: " + list);
		list.addFront(7);

		list.reverse();
		System.out.println("After iterative reverse: " + list);
		
		list.reverseRecursive();
		System.out.println("After recursive reverse: " + list);

		list.deleteKey(0);
		System.out.println("After trying to remove non-existent element: " + list);

		list.deleteKey(14);
		System.out.println("After removing mid-element: " + list);

		list.deleteKey(7);
		System.out.println("After removing head element: " + list);

		list.deleteKey(28);
		System.out.println("After removing the last element: " + list);

		Int num = new Int(100);
		System.out.println("After creating new Int: " + (num + 1));
		
	}
}
