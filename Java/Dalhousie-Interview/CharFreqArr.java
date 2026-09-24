public class CharFreqArr {

    public static void main(String[] args) {

        String str = "Do you know how to program in Java?";

        // Scanner input = new Scanner(System.in);
        // String str = input.nextLine();

        String[] words = str.split(" ");

        for (String w : words) {

            // Convert the given string into character array
            int len = w.length();
            int[] freq = new int[len];
            char[] ch = w.toCharArray();

            for (int i = 0; i < len; i++) {

                // Counts the characters and their corresponding frequency
                freq[i] = 1;
                for (int j = i + 1; j < len; j++) {
                    if (ch[i] == ch[j]) {
                        freq[i]++;
                        ch[j] = ' '; // Set ch[j] to ' ' to avoid printing visited character
                    }
                }

                // Displays the characters and their corresponding frequency
                if (ch[i] != ' ') {
                    System.out.print(ch[i] + "(" + freq[i] + ") ");
                }

            }

            System.out.println();
        }
    }

}
