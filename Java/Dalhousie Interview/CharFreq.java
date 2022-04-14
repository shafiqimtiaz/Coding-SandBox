class CharFreq {
    public static void main(String[] args) {

        String str = "Lorem ipsum dolor sit amet Sed tempore";

        // Scanner input = new Scanner(System.in);
        // String str = input.nextLine();

        int[] freq = new int[str.length()];

        // Convert the given string into character array
        char ch[] = str.toCharArray();
        for (int i = 0; i < str.length(); i++) {
            freq[i] = 1;
            for (int j = i + 1; j < str.length(); j++) {

                if (ch[i] == ch[j]) {
                    freq[i]++;
                    // Set ch[j] to 0 to avoid printing visited character
                    ch[j] = '0';
                }
            }
        }

        // Displays the characters and their corresponding frequency
        for (int i = 0; i < freq.length; i++) {
            if (ch[i] != ' ' && ch[i] != '0') {
                System.out.print(ch[i] + "(" + freq[i] + ") ");
            }
        }
    }
}