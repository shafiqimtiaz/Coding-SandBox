package datastructures.ExpressionTree;

public class binTree1 {

    // Data structure to store a binary tree node
    public static class Node {
        String val;
        Node left, right;

        Node(String val) {
            this.val = val;
            this.left = this.right = null;
        }
    }

    public static class binaryTree {
        // Utility function to check if a given node is a leaf node
        public static boolean isLeaf(Node node) {
            return node.left == null && node.right == null;
        }

        // Function to apply an operator `op` to values `x` and `y` and return the
        // result
        public static double process(String op, double x, double y) {
            if (op == "+") {
                return x + y;
            }
            if (op == "-") {
                return x - y;
            }
            if (op == "×") {
                return x * y;
            }
            if (op == "/") {
                return x / y;
            }

            return 0;
        }

        // Recursive function to evaluate a binary expression tree
        public static double evaluate(Node root) {
            // base case: invalid input
            if (root == null) {
                return 0;
            }
            // the leaves of a binary expression tree are operands
            if (isLeaf(root)) {
                return Integer.valueOf(root.val);
            }

            // recursively evaluate the left and right subtree
            double x = evaluate(root.left);
            double y = evaluate(root.right);

            // apply the operator at the root to the values obtained in the previous step
            return process(root.val, x, y);
        }

        public static void main(String[] args) {

            Node root = new Node("-");
            root.left = new Node("×");
            root.right = new Node("x");
            root.left.left = new Node("7");
            root.left.right = new Node("+");
            root.left.right.left = new Node("4");
            root.left.right.right = new Node("/");
            root.left.right.right.left = new Node("12");
            root.left.right.right.right = new Node("4");
            root.right.left = new Node("2");
            root.right.right = new Node("5");

            System.out.println("The value of the expression tree is " + evaluate(root));
        }
    }

}
