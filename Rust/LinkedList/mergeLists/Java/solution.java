import linkedlist.*;
import java.lang.Comparable;

class solution {
    private static <T extends Comparable<T>> Node<T> merge (
        Node<T> first, Node<T> second) {
        if (first == null) return second;
        if (second == null) return first;

        Node<T> new_head = new Node<T>();
        if (first.value().compareTo(second.value()) <= 0) {
            new_head = first;
            first = first.next();
        } else {
            new_head = second;
            second = second.next();
        }

        Node<T> current = new_head;
        while (first != null && second != null) {
            Node<T> temp = null;
            if (first.value().compareTo(second.value()) <= 0) {
                temp = first;
                first = first.next();
            } else {
                temp = second;
                second = second.next();
            }
            current.setNext(temp);
            current = temp;
        }

        if (first != null) {
            current.setNext(first);
        } else if (second != null) {
            current.setNext(second);
        }

        return new_head;
    }
    
    
    public static void main(String[] args) {
        LinkedList<Integer> list1 = new LinkedList<>();
        LinkedList<Integer> list2 = new LinkedList<>();

        list1.addFront(19);
        list1.addFront(15);
        list1.addFront(8);
        list1.addFront(4);

        list2.addFront(16);
        list2.addFront(10);
        list2.addFront(9);
        list2.addFront(7);

        System.out.println("Original 1: " + list1);
        System.out.println("Original 2: " + list2);

        LinkedList<Integer> merged = new LinkedList<>();
        merged.setHead(merge(list1.head(), list2.head()));

        System.out.println("Merged: " + merged);
        System.out.println("Original 1: " + list1);
        System.out.println("Original 2: " + list2);
        
        
    }
}
