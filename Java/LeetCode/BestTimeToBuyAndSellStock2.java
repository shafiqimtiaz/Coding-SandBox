public class BestTimeToBuyAndSellStock2 {
    public static int maxProfit(int[] prices) {

        int max = 0;

        for (int i = 1; i < prices.length; i++) {
            int profit = prices[i] - prices[i - 1];
            if (profit > 0) max += profit;
        }

        return max;
    }

    public static void main(String[] args) {
        int[] arr1 = new int[]{-1, 0, 1, 2, -1, -4};
        int[] arr2 = new int[]{1, 2, 3, 4};
        int[] arr3 = new int[]{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
        int[] arr4 = new int[]{-2, 0, 0, 2, 2};

        System.out.println(maxProfit(arr1));
        System.out.println(maxProfit(arr2));
        System.out.println(maxProfit(arr3));
        System.out.println(maxProfit(arr4));
    }
}
