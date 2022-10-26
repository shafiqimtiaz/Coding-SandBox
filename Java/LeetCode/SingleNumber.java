import java.util.*;

public class SingleNumber {
    // Using HashMap ==> TC = O(n) SC=O(n)
    public static int singleNumberMap(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
            if (!map.containsKey(i)) map.put(i, 1);
            else map.put(i, map.get(i) + 1);
        }

        for (int i : nums) {
            if (map.get(i) == 1) return i;
        }
        return -1;
    }

    // Using HashSet ==> TC = O(n) SC=O(n)
    public static int singleNumberSet(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int i : nums) {
            if (set.contains(i)) set.remove(i);
            else set.add(i);
        }
        for (Integer i : set) return i;
        return -1;
    }

    // Using Sorting ==> TC: O(NlogN) SC: O(1)
    public static int singleNumberSorting(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i += 2) {
            if (nums[i] != nums[i - 1])
                return nums[i - 1];
        }
        return nums[nums.length - 1];
    }

    //Using XOR ==> TC: O(N) SC: O(1)
    public static int singleNumberBit(int[] nums) {
        int value = 0;
        for (int i : nums) {
            value ^= i;
        }
        return value;
    }

    public static void main(String[] args) {
        int[] arr1 = new int[]{7, 7, 1, 1, 5, 5, 3, 3, 6, 4, 4};
        int[] arr2 = new int[]{7, 7, 6, 6, 4, 3, 3, 1, 1};
        int[] arr3 = new int[]{0, 0, 1};
        int[] arr4 = new int[]{-2, -2, 0, 1, 0};

        System.out.println(singleNumberMap(arr1));
        System.out.println(singleNumberSet(arr2));
        System.out.println(singleNumberSorting(arr3));
        System.out.println(singleNumberBit(arr4));
    }
}
