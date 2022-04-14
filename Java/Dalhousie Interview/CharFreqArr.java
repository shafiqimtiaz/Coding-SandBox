public class CharFreqArr {

    public static void main(String[] args) {

        String str = "Do you know how to program in Java?";

        // Scanner input = new Scanner(System.in);
        // String str = input.nextLine();

        String[] words = str.split(" ");

        for (String w : words) {
            
            // Convert the given string into character array
            char[] ch = w.toCharArray();
            int[] freq = new int[w.length()];

            for (int i = 0; i < w.length(); i++) {

                // Counts the characters and their corresponding frequency
                freq[i] = 1;
                for (int j = i + 1; j < w.length(); j++) {
                    if (ch[i] == ch[j]) {
                        freq[i]++;
                        // Set ch[j] to 0 to avoid printing visited character
                        ch[j] = '0';
                    }
                }

                // Displays the characters and their corresponding frequency
                if (ch[i] != ' ' && ch[i] != '0') {
                    System.out.print(ch[i] + "(" + freq[i] + ") ");
                }
            }

            System.out.println();
        }
    }

}
