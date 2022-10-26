public class RemoveDuplicates {

    public static int removeDuplicates(int[] nums) {

        int l = 1;

        for (int r = 1; r < nums.length; r++) {
            if (nums[r] != nums[r - 1]) {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }

    public static void main(String[] args) {
        int[] arr1 = new int[]{1, 1, 2};
        int[] arr2 = new int[]{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int[] arr3 = new int[]{1, 1, 1, 3, 3, 4, 5, 6, 6, 6};
        int[] arr4 = new int[]{-10, -5, 1, 2, 2};

        System.out.println(removeDuplicates(arr1));
        System.out.println(removeDuplicates(arr2));
        System.out.println(removeDuplicates(arr3));
        System.out.println(removeDuplicates(arr4));
    }
}
