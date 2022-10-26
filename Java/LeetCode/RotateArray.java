import java.util.Arrays;

public class RotateArray {

    public static int[] rotateArray(int[] nums, int k) {
        k = k % nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
        return nums;
    }

    public static void reverse(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    public static void main(String[] args) {
        int[] arr1 = new int[]{-1, 0, 1, 2, -1, -4};
        int[] arr2 = new int[]{1, 2, 3, 4};
        int[] arr3 = new int[]{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
        int[] arr4 = new int[]{-2, 0, 0, 2, 2};

        System.out.println(Arrays.toString(rotateArray(arr1, 3)));
        System.out.println(Arrays.toString(rotateArray(arr2, 2)));
        System.out.println(Arrays.toString(rotateArray(arr3, 3)));
        System.out.println(Arrays.toString(rotateArray(arr4, 2)));
    }
}
