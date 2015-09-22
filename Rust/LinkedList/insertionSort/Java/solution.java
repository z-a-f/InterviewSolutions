import LinkedList.*;
// import java.lang.Comparable;

/* This solution doesn't work so far :'( */

class solution1 {
    // This is the solution :)
    public static <T extends Comparable<T>> Node<T> sorted_insert(Node<T> head, Node<T> node) {
        
        if (node == null) return head;

        // if (head == null || node.value() <= head.value()) {
        if (head == null || node.value().compareTo(head.value()) <= 0) {
            node.setNext(head);
            return node;
        }

        Node<T> curr = head;

        while (curr.next() != null && (curr.next().value().compareTo(node.value()) < 0 ))
            curr = curr.next();

        node.setNext(curr.next());
        curr.setNext(node);

        return head;
    }

    public static <T extends Comparable<T>> Node<T> insertion_sort(Node<T> head) {
        Node<T> sorted = null;
        Node<T> curr = head;

        while (curr != null) {
            Node<T> temp = curr.next();
            sorted = sorted_insert(sorted, curr);
            curr = temp;
        }
        return sorted;
    }

    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();

        list.addFront(11);
        list.addFront(82);
        list.addFront(23);
        list.addFront(29);

        System.out.println(list);
        LinkedList<Integer> list1 = new LinkedList<>();
        list1.setHead(insertion_sort(list.head()));

        System.out.println(list);
        System.out.println(list1);
    }
}
