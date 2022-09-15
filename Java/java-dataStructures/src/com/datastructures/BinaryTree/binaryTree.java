package datastructures.BinaryTree;

public class binaryTree {

    public static void main(String[] args) {

    }

    public static class Tree {

        private TreeNode root;

    }

    public static class TreeNode {

        private int data;
        private TreeNode leftChild;
        private TreeNode rightChild;

        public void insert(int value) {

        }

        public TreeNode(int data) {
            this.data = data;
        }

        public int getData() {
            return data;
        }

        public void setData(int data) {
            this.data = data;
        }

        public TreeNode getLeftChild() {
            return leftChild;
        }

        public void setLeftChild(TreeNode leftChild) {
            this.leftChild = leftChild;
        }

        public TreeNode getRightChild() {
            return rightChild;
        }

        public void setRightChild(TreeNode rightChild) {
            this.rightChild = rightChild;
        }
    }
}
