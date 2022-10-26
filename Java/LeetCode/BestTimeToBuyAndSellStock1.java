public class BestTimeToBuyAndSellStock1 {
    public static int maxProfit(int[] prices) {
        if (prices == null || prices.length <= 1) return 0;

        int min = prices[0];
        int max = 0;

        for (int i : prices) {
            int profit = i - min;
            if (profit > max) max = profit;
            if (i < min) min = i;
        }

        return max;
    }

    public static void main(String[] args) {
        int[] arr1 = new int[]{7, 1, 5, 3, 6, 4};
        int[] arr2 = new int[]{7, 6, 4, 3, 1};
        int[] arr3 = new int[]{6, 7, 2, 9, 6, 3, 7, 1, 9};
        int[] arr4 = new int[]{0, 7, -1, -3, -9, 0, 0, 1};

        System.out.println(maxProfit(arr1));
        System.out.println(maxProfit(arr2));
        System.out.println(maxProfit(arr3));
        System.out.println(maxProfit(arr4));
    }
}
