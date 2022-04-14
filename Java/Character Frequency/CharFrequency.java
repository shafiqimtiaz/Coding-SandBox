class CharFrequency {
    public static void main(String[] args) {

        String str = "Lorem ipsum dolor sit amet Sed tempore";

        // Scanner input = new Scanner(System.in);
        // String str = input.nextLine();

        int[] freq = new int[str.length()];

        // Convert the given string into character array
        char str1[] = str.toCharArray();
        for (int i = 0; i < str.length(); i++) {
            freq[i] = 1;
            for (int j = i + 1; j < str.length(); j++) {

                if (str1[i] == str1[j]) {
                    freq[i]++;
                    // Set str1[j] to 0 to avoid printing visited character
                    str1[j] = '0';
                }
            }
        }

        // Displays the characters and their corresponding frequency
        for (int i = 0; i < freq.length; i++) {
            if (str1[i] != ' ' && str1[i] != '0') {
                System.out.print(str1[i] + "(" + freq[i] + ") ");
            }
        }
    }
}