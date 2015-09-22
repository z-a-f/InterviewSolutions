import LinkedListJava.*;
// import java.lang.Comparable;

class solution {
    // This is the solution :)
    public static <T extends Comparable<T>> Node<T> merge_sort (Node<T> head) {
        if (head == null) return null;
        if (head.next() == null) return head;

        Node<T> second_half = split(head);

        Node<T> l1 = merge_sort(head);
        Node<T> l2 = merge_sort(second_half);

        return merge(l1, l2);
    }

    private static <T extends Comparable<T>> Node<T> split (Node<T> head) {
        Node<T> slow = new Node<T>();
        Node<T> fast = new Node<T>();

        slow = head;
        fast = head.next();

        while (fast != null) {
            fast = fast.next();
            if (fast != null) {
                fast = fast.next();
                slow = slow.next();
            }
        }
        fast = slow.next();
        slow.setNext(null);
        return fast;
    }

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
        LinkedList<Integer> list = new LinkedList<>();

        list.addFront(1);
        list.addFront(2);
        list.addFront(3);
        list.addFront(4);
        list.addFront(5);
        list.addFront(6);
        list.addFront(7);
        list.addFront(8);
        list.addFront(9);
        list.addFront(10);
        list.addFront(11);

        System.out.println(list);
        LinkedList<Integer> sort = new LinkedList<>();
        sort.setHead(merge_sort(list.head()));

        System.out.println(list);
        System.out.println(sort);
    }
}
