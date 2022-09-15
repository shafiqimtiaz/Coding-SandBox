package datastructures.BruteForceSearch;

import java.util.*;

public class bruteForceSearch {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.print("Enter Text: ");
        String text = input.nextLine();
        System.out.print("Enter Pattern: ");
        String pattern = input.nextLine();

        input.close();

        int match = BFA(text, pattern);
        System.out.print("Match at index " + match);
    }

    public static int BFA(String text, String pattern) {

        int lengthOfText = text.length();
        int lengthOfPattern = pattern.length();

        for (int i = 0; i < lengthOfText - lengthOfPattern; i++) {
            int j;

            for (j = 0; j < lengthOfPattern; j++) {

                if (text.charAt(i + j) != pattern.charAt(j)) {
                    break;
                }
            }

            if (j == lengthOfPattern) {
                return i;
            }
        }

        return lengthOfText;
    }
}
