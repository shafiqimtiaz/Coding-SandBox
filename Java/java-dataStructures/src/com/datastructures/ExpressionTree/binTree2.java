package datastructures.ExpressionTree;

import java.io.*;
import java.util.Scanner;

public class binTree2 {

    // This is a java program to construct Expression Tree using Infix Expression

    public static class Node {
        public char data;
        public Node leftChild;
        public Node rightChild;

        public Node(char x) {
            data = x;
        }

        public void displayNode() {
            System.out.print(data);
        }
    }

    public static class Stack1 {
        private Node[] a;
        private int top, m;

        public Stack1(int max) {
            m = max;
            a = new Node[m];
            top = -1;
        }

        public void push(Node key) {
            a[++top] = key;
        }

        public Node pop() {
            return (a[top--]);
        }

        public boolean isEmpty() {
            return (top == -1);
        }
    }

    public static class Stack2 {
        private char[] a;
        private int top, m;

        public Stack2(int max) {
            m = max;
            a = new char[m];
            top = -1;
        }

        public void push(char key) {
            a[++top] = key;
        }

        public char pop() {
            return (a[top--]);
        }

        public boolean isEmpty() {
            return (top == -1);
        }
    }

    public static class Conversion {
        private Stack2 s;
        private String input;
        private String output = "";

        public Conversion(String str) {
            input = str;
            s = new Stack2(str.length());
        }

        public String inToPost() {
            for (int i = 0; i < input.length(); i++) {
                char ch = input.charAt(i);
                switch (ch) {
                case '+':
                case '-':
                    gotOperator(ch, 1);
                    break;
                case '*':
                case '/':
                    gotOperator(ch, 2);
                    break;
                case '(':
                    s.push(ch);
                    break;
                case ')':
                    gotParenthesis();
                    break;
                default:
                    output = output + ch;
                }
            }
            while (!s.isEmpty())
                output = output + s.pop();
            return output;
        }

        private void gotOperator(char opThis, int prec1) {
            while (!s.isEmpty()) {
                char opTop = s.pop();
                if (opTop == '(') {
                    s.push(opTop);
                    break;
                } else {
                    int prec2;
                    if (opTop == '+' || opTop == '-')
                        prec2 = 1;
                    else
                        prec2 = 2;
                    if (prec2 < prec1) {
                        s.push(opTop);
                        break;
                    } else
                        output = output + opTop;
                }
            }
            s.push(opThis);
        }

        private void gotParenthesis() {
            while (!s.isEmpty()) {
                char ch = s.pop();
                if (ch == '(')
                    break;
                else
                    output = output + ch;
            }
        }
    }

    public static class Tree {
        private Node root;

        public Tree() {
            root = null;
        }

        public void insert(String s) {
            Conversion c = new Conversion(s);
            s = c.inToPost();
            Stack1 stk = new Stack1(s.length());
            s = s + "#";
            int i = 0;
            char symbol = s.charAt(i);
            Node newNode;
            while (symbol != '#') {
                if (symbol >= '0' && symbol <= '9' || symbol >= 'A' && symbol <= 'Z'
                        || symbol >= 'a' && symbol <= 'z') {
                    newNode = new Node(symbol);
                    stk.push(newNode);
                } else if (symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*') {
                    Node ptr1 = stk.pop();
                    Node ptr2 = stk.pop();
                    newNode = new Node(symbol);
                    newNode.leftChild = ptr2;
                    newNode.rightChild = ptr1;
                    stk.push(newNode);
                }
                symbol = s.charAt(++i);
            }
            root = stk.pop();
        }

        public void traverse(int type) {
            switch (type) {
            case 1:
                System.out.print("Preorder Traversal:    ");
                preOrder(root);
                break;
            case 2:
                System.out.print("Inorder Traversal:     ");
                inOrder(root);
                break;
            case 3:
                System.out.print("Postorder Traversal:   ");
                postOrder(root);
                break;
            default:
                System.out.println("Invalid Choice");
            }
        }

        private void preOrder(Node localRoot) {
            if (localRoot != null) {
                localRoot.displayNode();
                preOrder(localRoot.leftChild);
                preOrder(localRoot.rightChild);
            }
        }

        private void inOrder(Node localRoot) {
            if (localRoot != null) {
                inOrder(localRoot.leftChild);
                localRoot.displayNode();
                inOrder(localRoot.rightChild);
            }
        }

        private void postOrder(Node localRoot) {
            if (localRoot != null) {
                postOrder(localRoot.leftChild);
                postOrder(localRoot.rightChild);
                localRoot.displayNode();
            }
        }
    }

    public static void main(String args[]) throws IOException {
        String ch = "y";
        Scanner input = new Scanner(System.in);
        while (ch.equals("y")) {
            Tree t1 = new Tree();
            System.out.println("Enter the Expression");
            String a = input.nextLine();
            t1.insert(a);
            t1.traverse(1);
            System.out.println("");
            t1.traverse(2);
            System.out.println("");
            t1.traverse(3);
            System.out.println("");
            System.out.print("Enter y to continue ");
            ch = input.nextLine();
        }
        input.close();
    }

}
