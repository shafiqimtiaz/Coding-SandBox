package datastructures.ExpressionTree;

public class binTreeMain {

    public static class Node {
        String data;
        Node left, right;

        Node(String d) {
            data = d;
            left = null;
            right = null;
        }
    }

    private static int toInt(String s) {
        int num = 0;

        // Check if the integral value is negative or not
        // If it is not negative, generate the number normally
        if (s.charAt(0) != '-')
            for (int i = 0; i < s.length(); i++)
                num = num * 10 + ((int) s.charAt(i) - 48);

        // If it is negative, calculate the +ve number
        // first ignoring the sign and invert the
        // sign at the end
        else
            for (int i = 1; i < s.length(); i++) {
                num = num * 10 + ((int) (s.charAt(i)) - 48);
                num = num * -1;
            }
        return num;
    }

    // This function receives a node of the syntax
    // tree and recursively evaluate it
    public static double evalTree(Node root) {

        // Empty tree
        if (root == null)
            return 0;

        // Leaf node i.e, an integer
        if (root.left == null && root.right == null)
            return toInt(root.data);

        // Evaluate left subtree
        double leftEval = evalTree(root.left);

        // Evaluate right subtree
        double rightEval = evalTree(root.right);

        // Check which operator to apply
        if (root.data.equals("+"))
            return leftEval + rightEval;

        if (root.data.equals("-"))
            return leftEval - rightEval;

        if (root.data.equals("*"))
            return leftEval * rightEval;

        return leftEval / rightEval;
    }

    // Driver code
    public static void main(String[] args) {

        // tree 1
        System.out.println("Tree 1:\t7 * ( 4 + 12 / 4 ) - 2 * 5");

        Node root = new Node("-");
        root.left = new Node("*");
        root.left.left = new Node("7");
        root.left.right = new Node("+");
        root.left.right.left = new Node("4");
        root.left.right.right = new Node("/");
        root.left.right.right.left = new Node("12");
        root.left.right.right.right = new Node("4");
        root.right = new Node("*");
        root.right.left = new Node("2");
        root.right.right = new Node("5");

        System.out.println("Value of expression:\t" + evalTree(root));

        root = null;

        // tree 2
        System.out.println("Tree 2:\t7 * 4 + 12 / 4 - 2 * 5");

        root = new Node("-");
        root.left = new Node("+");
        root.left.left = new Node("*");
        root.left.left.left = new Node("7");
        root.left.left.right = new Node("4");
        root.left.right = new Node("/");
        root.left.right.left = new Node("12");
        root.left.right.right = new Node("4");
        root.right = new Node("*");
        root.right.left = new Node("2");
        root.right.right = new Node("5");

        System.out.println("Value of expression:\t" + evalTree(root));

        // tree 3
        System.out.println("Tree 3:\t7 * 4 + 12 / ( 4 - 2 ) * 84");

        root = new Node("+");
        root.left = new Node("*");
        root.left.left = new Node("7");
        root.left.right = new Node("4");
        root.right = new Node("/");
        root.right.left = new Node("*");
        root.right.left.left = new Node("12");
        root.right.left.right = new Node("84");
        root.right.right = new Node("-");
        root.right.right.left = new Node("4");
        root.right.right.right = new Node("2");

        System.out.println("Value of expression:\t" + evalTree(root));
    }

}
