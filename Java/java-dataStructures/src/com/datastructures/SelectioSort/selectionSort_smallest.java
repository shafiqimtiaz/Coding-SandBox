package datastructures.SelectioSort;

public class selectionSort_smallest {

    public static void main(String[] args) {
        int[] intArray = { 20, 35, -15, 7, 55, 1, -22 };

        for (int furstUnsortedIndex = 0; furstUnsortedIndex < intArray.length - 1; furstUnsortedIndex++) {

            int smallest = furstUnsortedIndex;

            for (int i = intArray.length - 1; i > furstUnsortedIndex; i--) {
                if (intArray[i] < intArray[smallest]) {
                    smallest = i;
                }
            }

            swap(intArray, smallest, furstUnsortedIndex);
        }

        for (int i = 0; i < intArray.length; i++) {
            System.out.println(intArray[i]);
        }

    }

    public static void swap(int[] array, int i, int j) {

        if (i == j) {
            return;
        }
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

}
