import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {
    public static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        int len = nums.length;

        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && (nums[i] == nums[i - 1])) continue;
            int l = i + 1, r = len - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) l++;
                else if (sum > 0) r--;
                else {
                    List<Integer> temp = Arrays.asList(nums[i], nums[l], nums[r]);
                    res.add(temp);
                    while (l + 1 < r && nums[l] == nums[l + 1]) l++;
                    while (l < r - 1 && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] arr1 = new int[]{-1, 0, 1, 2, -1, -4};
        int[] arr2 = new int[]{1, 2, 3, 4};
        int[] arr3 = new int[]{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
        int[] arr4 = new int[]{-2, 0, 0, 2, 2};

        System.out.println(threeSum(arr1));
        System.out.println(threeSum(arr2));
        System.out.println(threeSum(arr3));
        System.out.println(threeSum(arr4));
    }
}
