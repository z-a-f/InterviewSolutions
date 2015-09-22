import linkedlist.*;

import java.lang.Exception;
import java.lang.Comparable;

class solution1 {
    // This is the solution :)
    public static <T extends Comparable<T>> Node<T>
        intersects(
                   Node<T> head1,
                   Node<T> head2
                   ) {
        Node<T> l1 = null;
        Node<T> l2 = null;

        int l1len = get_length(head1);
        int l2len = get_length(head2);

        int d = l1len - l2len;

        l1 = (d >= 0) ? head1 : head2;
        l2 = (d >= 0) ? head2 : head1;

        d = d >= 0 ? d : -d;

        while (d > 0) {
            l1 = l1.next();
            d--;
        }

        while (l1 != null) {
            if (l1 == l2) {
                return l1;
            }
            l1 = l1.next();
            l2 = l2.next();
        }
        return null;
    }

    private static <T extends Comparable<T>> int get_length(Node<T> head) {
        int list_length = 0;
        while (head != null) {
            head = head.next();
            list_length++;
        }
        return list_length;
    }
    
    public static void main(String[] args) {
        LinkedList<Integer> list1 = new LinkedList<>();
        LinkedList<Integer> list2 = new LinkedList<>();
        LinkedList<Integer> list3 = new LinkedList<>();

        list1.addFront(27);
        list1.addFront(12);
        list1.addFront(23);
        list1.addFront(29);

        list2.addFront(4);
        list2.addFront(13);

        list2.head().next().setNext(list1.head().next().next());

        list3.addFront(27);
        list3.addFront(12);
        list3.addFront(23);
        list3.addFront(29);

        System.out.println("List 1: " + list1);
        System.out.println("List 2: " + list2);
        System.out.println("List 3: " + list3);

        Node<Integer> intsct;
        
        intsct = intersects(list1.head(), list2.head());
        
        System.out.println("Intersect: " + intsct.value());

        intsct = intersects(list1.head(), list3.head());
        try{
            System.out.println("Intersect: " + intsct.value());
        } catch(Exception e) {
            System.out.println("Exception:\n" + e);
        }
        
    }
}
