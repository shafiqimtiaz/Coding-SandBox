public class containsDuplicate {

    public static void containsDuplicate(int[] nums) {
        for (int i : nums) {
            System.out.print(i + " ");
        }

    }
    public static void main(String[] args) {
        int[] arr = new int[]{1,2,3,4,5,6};
        containsDuplicate(arr);
    }
}
