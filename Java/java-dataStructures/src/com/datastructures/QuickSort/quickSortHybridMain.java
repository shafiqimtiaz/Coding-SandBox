package datastructures.QuickSort;

public class quickSortHybridMain {

    private static void insertionSort(int a[], int low, int high) {
        for (int i = low + 1; i <= high; i++) {
            for (int j = i - 1; j >= low; j--) {
                if (a[j] > a[j + 1]) {
                    // Swap
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                } else
                    break;
            }
        }
    }

    private static int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low;
        int j = low;

        while (i <= high) {
            if (arr[i] > pivot)
                i++;
            else {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j++;
            }
        }
        return j - 1;
    }

    public static void hybridQuickSort(int arr[], int low, int high) {
        while (low < high) {
            // Check if array size on which we will be working is less than 10
            if (high - low < (int) Math.pow(2, 4)) {
                insertionSort(arr, low, high);
                break;
            } else {
                int pivot = partition(arr, low, high);

                // We will do recursion on small size
                // subarray So we can check pivot - low and
                // pivot - high

                if (pivot - low < pivot - high) {
                    hybridQuickSort(arr, low, pivot - 1);
                    low = pivot + 1;
                } else {
                    hybridQuickSort(arr, pivot + 1, high);
                    high = pivot - 1;
                }
            }
        }
    }

    public static int[] makeRandomArray(int length) {

        int[] randomArray = new int[length];

        for (int i = 0; i < length; i++) {

            randomArray[i] = (int) (Math.random() * length);

            for (int j = 0; j < i; j++) {
                if (randomArray[i] == randomArray[j]) {
                    randomArray[j] = (int) (Math.random() * length);
                }
            }
        }
        return randomArray;
    }

    // Driver code
    public static void main(String[] args) {

        System.out.println("Generating list of 2^10 random integers...........");
        int length = (int) Math.pow(2, 10);

        // custom generated array
        int[] arr = makeRandomArray(length);
        System.out.println("\nRandom list:\t\tElement Count:" + arr.length);

        for (int i : arr) {
            System.out.print(i + " ");
        }

        System.out.println("\n\nSorted list:\t\tElement Count:" + arr.length);
        hybridQuickSort(arr, 0, arr.length - 1);
        for (int i : arr)
            System.out.print(i + " ");
    }

}
