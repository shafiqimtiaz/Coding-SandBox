public class isPalindrome {

    public static void main(String[] args) {
        int[] arr1 = new int[]{121, 234, 67676, 987789};
        for (int i : arr1) {
            System.out.println(i + " - " + isPalindromeNum(i));
        }

        String[] arr2 = new String[]{"hoobla", "magic", "adda", "nun"};
        for (String s : arr2) {
            System.out.println(s + " - " + isPalindromeStr(s));
        }
    }

    public static boolean isPalindromeNum(int x) {
        int rem = 0, rev = 0;
        int num = x;
        while (x > 0) {
            rem = x % 10;
            rev = (rev * 10) + rem;
            x /= 10;
        }
        return num == rev;
    }

    public static boolean isPalindromeStr(String s) {

        int i = 0, j = s.length() - 1;
        String str = s.toLowerCase();

        while (i < j) {
            if (str.charAt(i) != str.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }
}
