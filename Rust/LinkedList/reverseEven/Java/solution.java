import linkedlist.*;
import java.lang.Comparable;
import java.util.HashSet;

class solution {
    public static <T extends Comparable<T>> Node<T> removeDuplicates (Node<T> head) {
        if (head == null) return head;

        // Track list values in a hash table
        HashSet<T> dup_set = new HashSet<T>();
        Node<T> curr = head;
        dup_set.add(curr.value());

        while (curr.next() != null) {
            if (!dup_set.contains(curr.next().value())) {
                // Element not found, add it to the hashset:
                dup_set.add(curr.next().value());
                curr = curr.next();
            } else {
                // Duplicate found, remove the node
                curr.setNext(curr.next().next());
            }
        }

        return head;
    }
    
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        list.addFront(7);
        list.addFront(4);
        list.addFront(9);
        list.addFront(4);
        list.addFront(7);
        list.addFront(4);

        System.out.println(list);
        list.setHead(removeDuplicates(list.head()));
        System.out.println(list);
    }
}
