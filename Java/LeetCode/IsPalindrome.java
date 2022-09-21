public class IsPalindrome {

    public static void main(String[] args) {
        int[] arr1 = new int[]{121, 234, 67676, 987789};
        for (int i : arr1) {
            System.out.println(i + " - " + isPalindromeNum(i));
        }

        String[] arr2 = new String[]{"hoobla", "magic", "adda", "nun"};
        for (String s : arr2) {
            System.out.println(s + " - " + isPalindromeStr(s));
        }
        String str = "A man, a plan, a canal: Panama";
        System.out.println(str + " - " + isPalindromeStr(str));
        System.out.println(str + " - " + isPalindromeStr2(str));
    }

    public static boolean isPalindromeNum(int x) {
        if (x == 0) return true;
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
        if (s.isEmpty()) return true;
        s = s.toLowerCase();

        int left = 0, right = s.length() - 1;

        while (left < right) {
            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) right--;
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) left++;

            if (s.charAt(left++) != s.charAt(right--)) return false;
        }
        return true;
    }

    public static boolean isPalindromeStr2(String s) {
        if (s.isEmpty()) return true;
        s = s.toLowerCase().replace("[^a-zA-Z]", "");
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) return false;
            right--;
            left++;
        }
        return true;
    }
}
