class CharFreq {
    public static void main(String[] args) {

        String str = "Do you know how to program in Java?";

        // Scanner input = new Scanner(System.in);
        // String str = input.nextLine();

        // Convert the given string into character array
        int len = str.length();
        int[] freq = new int[len];
        char[] ch = str.toCharArray();

        for (int i = 0; i < len; i++) {

            freq[i] = 1;

            for (int j = i + 1; j < len; j++) {
                if (ch[i] == ch[j]) {
                    freq[i]++;
                    ch[j] = ' '; // Set ch[j] to ' ' to avoid printing visited character
                }
            }

            if (ch[i] != ' ') {
                System.out.print(ch[i] + "(" + freq[i] + ") ");
            }

        }
    }
}