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
	}
}
