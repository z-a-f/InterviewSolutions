import LinkedListJava.*;

public class tstLinkedList{
	public static void main(String[] args) {
		LinkedList<Integer> list = new LinkedList<>();
		try {
			list.front();
		} catch (Exception e) {
			System.out.println ("Exception:\n" + e);
		}
		// Node<Integer> head = new Node<Integer>();
		// list.setHead(head);

		System.out.println("Empty list:\n" + list);
		list.addFront(28);
		list.addFront(21);
		list.addFront(14);
		list.addFront(7);
		System.out.println("Initial list:\n" + list);
		list.removeFront();
		System.out.println("After removing front:\n" + list);
		list.addFront(7);

		list.reverse();
		System.out.println("After iterative reverse:\n" + list);
		
		list.reverseRecursive();
		System.out.println("After recursive reverse:\n" + list);

		list.deleteKey(0);
		System.out.println("After trying to remove non-existent element:\n" + list);

		list.deleteKey(14);
		System.out.println("After removing mid-element:\n" + list);

		list.deleteKey(7);
		System.out.println("After removing head element:\n" + list);

		list.deleteKey(28);
		System.out.println("After removing the last element:\n" + list);

		Int A = new Int(123);
		System.out.println("A:\n" + A);
		Int B = new Int(897);
		System.out.println("B:\n" + B);
		Int C = new Int();
		C.add(A, B);
		System.out.println("A + B:\n" + C);

		System.out.println("\nCreate a linked list with arbitrary pointers:\n");
		LinkedList<Integer> listArb = new LinkedList<>();
		listArb.addFront(21);
		listArb.addFront(14);
		listArb.addFront(7);
		System.out.println(listArb + "\n");
		listArb.head().setArb(listArb.head().next().next());
		listArb.head().next().next().setArb(listArb.head());
		System.out.println(listArb + "\n");
	}
}
