import linkedlist.*;
import java.lang.Comparable;
import java.util.HashSet;

class solution {
    public static <T extends Comparable<T>> Node<T> split_odd_even(Node<T> head) {
        if (head == null) return null;
        Node<T> curr = head;
        Node<T> even = head.next();
        Node<T> tail = even;

        while (curr != null && curr.next() != null) {
            Node<T> temp = curr.next();

            curr.setNext(temp.next());
            curr = curr.next();

            tail.setNext(temp);
            tail = tail.next();
        }
        if (tail != null) tail.setNext(null);
        return even;
    }

    public static <T extends Comparable<T>> Node<T> merge_alternating (Node<T> head1, Node<T> head2) {
        if (head1 == null) return head2;
        if (head2 == null) return head1;

        Node<T> head = head1;
        while (head1.next() != null && head2 != null) {
            Node<T> temp = head2;
            head2 = head2.next();

            temp.setNext(head1.next());
            head1.setNext(temp);
            head1 = temp.next();
        }

        if (head1.next() == null) head1.setNext(head2);

        return head;
    }

    public static <T extends Comparable<T>> Node<T> reverse_even_nodes(Node<T> head) {
        Node<T> curr = head;
        Node<T> list_even = null;

        while (curr != null && curr.next() != null) {
            Node<T> even = curr.next();
            curr.setNext(even.next());

            even.setNext(list_even);
            list_even = even;

            curr = curr.next();
        }

        return merge_alternating(head, list_even);
    }
    
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        LinkedList<Integer> even = new LinkedList<>();
        
        list.addFront(7);
        list.addFront(6);
        list.addFront(5);
        list.addFront(4);
        list.addFront(3);
        list.addFront(2);
        list.addFront(1);
        
        System.out.println(list);
        // even.setHead(split_odd_even(list.head()));

        System.out.println(list);
        // even.reverse();
        System.out.println(even);

        // list.setHead(merge_alternating(list.head(), even.head()));
        list.setHead(reverse_even_nodes(list.head()));
        System.out.println(list);
    }
}
