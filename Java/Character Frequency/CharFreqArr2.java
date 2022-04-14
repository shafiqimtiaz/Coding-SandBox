public class CharFreqArr2 {

    public static void main(String[] args) {

        String str = "Lorem ipsum dolor sit amet Sed tempore";

        // Scanner input = new Scanner(System.in);
        // String str = input.nextLine();

        String[] words = str.split(" ");

        boolean repeat;

        for (String w : words) {
            
            w.toLowerCase();

            int n = w.length();
            char[] chars = w.toCharArray();
            int[] count = new int[n];

            for (char c : chars) {
                for (int i = 0; i < n; i++) {
                    if (w.charAt(i) == c) {
                        count[i]++;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                repeat = false;
                for (int j = i + 1; j < n; j++) {
                    if (w.charAt(i) == w.charAt(j)) {
                        repeat = true;
                        break;
                    }
                }

                if (!repeat) {
                    System.out.print(w.charAt(i) + "(" + count[i] + ") ");
                }

            }
            System.out.println();
        }
    }

    
}
