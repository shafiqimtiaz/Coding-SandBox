package datastructures.LinkedList;

public class linkedList {

    private static class Node<E> {
        private E data;
        private Node<E> next;

        public Node(E e, Node<E> n) {
            data = e;
            next = n;
        }

        public E getData() {
            return data;
        }

        public Node<E> getNext() {
            return next;
        }

        public void setNext(Node<E> n) {
            next = n;
        }
    }

    public static class LinkedList<E> {

        private Node<E> head = null;
        private Node<E> tail = null;

        public boolean isEmpty() {
            return head == null;
        }

        public E first() {
            if (isEmpty()) {
                return null;
            }
            return head.getData();
        }

        public E last() {
            if (isEmpty()) {
                return null;
            }
            return tail.getData();
        }

        public void insert(E e) {
            Node<E> n = new Node<>(e, null);
            if (isEmpty()) {
                head = n;
            } else {
                tail.setNext(n);
            }
            tail = n;
        }

        public void printList() {
            Node<E> n = head;
            while (n != null) {
                System.out.print(n.getData() + " ");
                n = n.next;

            }
        }
    }

    public static void main(String[] args) {
        LinkedList<String> stringList = new LinkedList<>();

        stringList.insert("A");
        stringList.insert("B");
        stringList.insert("C");
        stringList.insert("D");
        stringList.printList();
    }
}