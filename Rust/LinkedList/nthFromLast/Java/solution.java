import linkedlist.*;
import java.lang.Comparable;

class solution {
    private static <T extends Comparable<T>> Node<T> nth_from_last(Node<T> head, int n) {
        Node<T> second = head;
        if (second == null || n < 1) return null;

        Node<T> first = head;

        while (first != null && n > 0) {
            first = first.next();
            --n;
        }

        // Check out of bounds:
        if (n != 0) return null;

        while (first != null) {
            first = first.next();
            second = second.next();
        }
        return second;
    }
    
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();

        Node<Integer> found = new Node<>();
    
        // Check on empty list first
        found = nth_from_last(list.head(), 1);
        if (found != null)
            System.out.println("Something went wrong!");
        else
            System.out.println("Empty lists work!");
    
        list.addFront(9);
        list.addFront(28);
        list.addFront(21);
        list.addFront(14);
        list.addFront(7);

        // Check on a BIG n:
        found = nth_from_last(list.head(), 100);
        if (found != null)
            System.out.println("Something went wrong!");
        else
            System.out.println("BIG n's work!");
        
        found = nth_from_last(list.head(), 3);
        if (found != null)
            System.out.println("n = 3 value: " + found.value());
        else
            System.out.println("Something went wrong!");
        
        // Make sure the list is still intact:
        System.out.println(list);
    

    }
}
