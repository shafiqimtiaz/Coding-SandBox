package datastructures.LinkedList;

public class revLinkedList<E> {

    private static class Node<E> {
        private E data;
        private Node<E> next;

        public Node(E e, Node<E> n) {
            data = e;
            next = n;
        }
    }

    private Node<E> head = null;
    private Node<E> tail = null;

    public void insert(E e) {
        Node<E> insert = new Node<>(e, null);
        if (head == null) {
            head = insert;
        } else {
            Node<E> newNode = new Node<>(e, null);
            Node<E> curr = head;
            while (curr.next != null) {
                curr = curr.next;
            }
            curr.next = newNode;
        }
        tail = insert;
    }

    public void reverseIterativeList() {
        Node<E> curr = head;
        Node<E> prev = null;
        Node<E> next = null;

        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    public void printList() {
        Node<E> curr = head;
        while (curr != null) {
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
        System.out.println();
    }

    // ************** DOEST WORK **************

    public Node<E> reverseRecursiveList(Node<E> curr) {
        if (curr == null) {
            return null;
        }

        if (curr.next == null) {
            this.head = curr;
            return curr;
        }

        Node<E> newHead = reverseRecursiveList(curr.next);
        curr.next.next = curr;
        curr.next = null;

        return newHead;
    }

    // ************** DOEST WORK **************

    public void sortList() {
        Node<E> curr = head;
        Node<E> index = null;
        E temp;

        if (head == null) {
            return;
        } else {
            while (curr != null) {
                index = curr.next;
                while (index != null) {
                    if (((Comparable) curr.data).compareTo((Comparable) index.data) > 0) {
                        temp = curr.data;
                        curr.data = index.data;
                        index.data = temp;
                    }
                    index = index.next;
                }
                curr = curr.next;
            }
        }
    }

    public static void main(String[] args) {
        revLinkedList<Integer> stringList = new revLinkedList<>();

        stringList.insert(1);
        stringList.insert(7);
        stringList.insert(23);
        stringList.insert(19);
        stringList.insert(42);
        stringList.printList();

        stringList.sortList();
        stringList.printList();

        stringList.reverseIterativeList();
        // stringList.reverseRecursiveList(stringList.head);
        stringList.printList();

        stringList.insert(16);
        stringList.insert(21);
        stringList.insert(11);
        stringList.printList();

        // stringList.reverseIterativeList();
        stringList.reverseRecursiveList(stringList.head);
        stringList.printList();

        stringList.insert(57);
        stringList.insert(33);
        stringList.insert(30);
        stringList.printList();

        stringList.reverseIterativeList();
        // stringList.reverseRecursiveList(stringList.head);
        stringList.printList();

        stringList.sortList();
        stringList.printList();
    }
}
