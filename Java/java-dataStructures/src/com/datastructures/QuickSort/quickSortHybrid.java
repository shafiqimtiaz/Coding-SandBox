package datastructures.QuickSort;

import java.util.*;

public class quickSortHybrid {

    // Total number of elements to be sorted
    private static final int N = 10000;

    // Total number of sorting runs
    private static final int NUM = 10;

    // Function to perform insertion sort on `arr[]`
    public static void insertionSort(int[] arr, int low, int n) {
        // Start from the second element (the element at index 0
        // is already sorted)
        for (int i = low + 1; i <= n; i++) {
            int value = arr[i];
            int j = i;

            // find index `j` within the sorted subset `arr[0…i-1]`
            // where element `arr[i]` belongs
            while (j > low && arr[j - 1] > value) {
                arr[j] = arr[j - 1];
                j--;
            }

            // note that subarray `arr[j…i-1]` is shifted to
            // the right by one position, i.e., `arr[j+1…i]`

            arr[j] = value;
        }
    }

    public static int partition(int[] a, int low, int high) {
        // Pick the rightmost element as a pivot from the array
        int pivot = a[high];

        // elements less than the pivot will be pushed to the left of `pIndex`
        // elements more than the pivot will be pushed to the right of `pIndex`
        // equal elements can go either way
        int pIndex = low;

        // each time we find an element less than or equal to the pivot,
        // `pIndex` is incremented, and that element would be placed
        // before the pivot.
        for (int i = low; i < high; i++) {
            if (a[i] <= pivot) {
                int temp = a[i];
                a[i] = a[pIndex];
                a[pIndex] = temp;

                pIndex++;
            }
        }

        // swap `pIndex` with pivot
        int temp = a[high];
        a[high] = a[pIndex];
        a[pIndex] = temp;

        // return `pIndex` (index of the pivot element)
        return pIndex;
    }

    public static void quicksort(int[] a, int low, int high) {
        // base condition
        if (low >= high) {
            return;
        }

        // rearrange elements across pivot
        int pivot = partition(a, low, high);

        // recur on subarray containing elements less than the pivot
        quicksort(a, low, pivot - 1);

        // recur on subarray containing elements more than the pivot
        quicksort(a, pivot + 1, high);
    }

    public static void optimizedQuicksort(int[] A, int low, int high) {
        while (low < high) {
            // switch to insertion sort if the size is 10 or smaller
            if (high - low < 10) {
                insertionSort(A, low, high);
                break;
            } else {
                int pivot = partition(A, low, high);

                // tail call optimizations – recur on the smaller subarray
                if (pivot - low < high - pivot) {
                    optimizedQuicksort(A, low, pivot - 1);
                    low = pivot + 1;
                } else {
                    optimizedQuicksort(A, pivot + 1, high);
                    high = pivot - 1;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[N];

        // to measure the time taken by optimized and non-optimized Quicksort
        long begin, end;
        long t1 = 0, t2 = 0;

        // perform Quicksort NUM times and take an average
        for (int i = 0; i < NUM; i++) {
            // generate random input
            Arrays.fill(arr, new Random().nextInt());
            int[] dup = Arrays.copyOf(arr, N);

            // Perform non-optimized Quicksort on the array

            begin = System.nanoTime();
            quicksort(arr, 0, N - 1);
            end = System.nanoTime();

            // calculate the time taken by non-optimized Quicksort
            t1 += (end - begin);

            // Perform optimized Quicksort on the duplicate array
            begin = System.nanoTime();
            optimizedQuicksort(dup, 0, N - 1);
            end = System.nanoTime();

            // calculate the time taken by optimized Quicksort
            t2 += (end - begin);
        }

        System.out.println("The average time taken by the non-optimized Quicksort: " + t1 / NUM + "ns");
        System.out.println("The average time taken by the optimized Quicksort: " + t2 / NUM + "ns");
    }

}
