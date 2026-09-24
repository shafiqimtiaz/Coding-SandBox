public class LongestCommonSubtring {

    public static void main(String[] args) {

        String[] str = {"house", "mouse", "trouser"};

        // Function call
        String subStr = lcs(str);
        System.out.println(subStr);

    }

    // function to find the stem (longest common
    // substring) from the string array
    public static String lcs(String[] arr) {
        // Determine size of the array
        int n = arr.length;

        // Take first word from array as reference
        String s = arr[0];
        int len = s.length();

        String res = "";

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j <= len; j++) {

                // generating all possible substrings
                // of our reference string arr[0] i.e s
                String stem = s.substring(i, j);
                int k = 1;
                for (k = 1; k < n; k++) {
                    // Check if the generated stem is
                    // common to all words
                    if (!arr[k].contains(stem)) {
                        break;
                    }

                }

                // If current substring is present in
                // all strings and its length is greater
                // than current result
                if (k == n && res.length() < stem.length()) {
                    res = stem;
                }
            }
        }
        return res;
    }

}
