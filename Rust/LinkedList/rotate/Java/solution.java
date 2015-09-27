import linkedlist.*;
import java.lang.Comparable;
import java.util.HashSet;

class solution {

    public static <T extends Comparable<T>> int find_length(Node<T> head) {
        int len = 0;
        Node<T> ptr = head;
        while (ptr != null) {
            ++len;
            ptr = ptr.next();
        }
        return len;
    }

    public static int adjust_rotation_needed(int n, int len) {
        n = n % len;
        if (n < 0) n += len;
        return n;
    }
    
    public static <T extends Comparable<T>> Node<T> rotate(Node<T> head, int n) {
        if (head == null || n == 0) {
            return head;
        }

        int len = find_length(head);

        // if n (number of rotations required) is bigger than
        // the length of the linked list or if n is negative,
        // we need to adjust it
        n = adjust_rotation_needed(n, len);

        if (n == 0) return head;

        // Find the start of rotated list
        int rotations_count = len - n - 1;
        Node<T> temp = head;

        while (rotations_count > 0) {
            rotations_count--;
            temp = temp.next();
        }

        Node<T> new_head = temp.next();

        // Set the new end of the list
        temp.setNext(null);

        // Iterate to the end of the list and
        // link that to original head
        temp = new_head;
        while (temp.next() != null) {
            temp = temp.next();
        }
        temp.setNext(head);

        return new_head;
    }
    
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        
        list.addFront(7);
        list.addFront(6);
        list.addFront(5);
        list.addFront(4);
        list.addFront(3);
        list.addFront(2);
        list.addFront(1);
        
        System.out.println(list);

        list.setHead(rotate(list.head(), -8));
        
        System.out.println(list);
    }
}
