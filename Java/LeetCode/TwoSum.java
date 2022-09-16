import java.util.*;

public class TwoSum {
    public static int[] twoSumArray(int[] nums, int target) {
        int[] res = new int[2];

        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] + nums[j] == target) {
                    res[0] = i;
                    res[1] = j;
                }
            }
        }
        return res;
    }

    public static int[] twoSumMap(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int comp = target - nums[i];

            if (map.containsKey(comp)) {
                return new int[]{map.get(comp), i};
            }

            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("Not found");
    }

    public static void main(String[] args) {
        int[] nums1 = {2, 7, 11, 15};
        int target1 = 9;

        int[] nums2 = {3, 2, 4};
        int target2 = 6;

        int[] nums3 = {3, 3};
        int target3 = 6;

        System.out.println(Arrays.toString(twoSumArray(nums1, target1)));
        System.out.println(Arrays.toString(twoSumArray(nums2, target3)));
        System.out.println(Arrays.toString(twoSumArray(nums3, target3)));
        System.out.println();
        System.out.println(Arrays.toString(twoSumMap(nums1, target1)));
        System.out.println(Arrays.toString(twoSumMap(nums2, target3)));
        System.out.println(Arrays.toString(twoSumMap(nums3, target3)));
    }
}
