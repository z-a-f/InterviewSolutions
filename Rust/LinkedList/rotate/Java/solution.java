import linkedlist.*;
import java.lang.Comparable;
import java.util.HashSet;

class solution {

    public static <T extends Comparable<T>> Node<T> rotate(Node<T> head, int n) {
        
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
