package com.datastructures.KnuthMorrisPrattSearch;

import java.util.*;

public class KMP {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.print("Enter Text: ");
        String text = input.nextLine();
        System.out.print("Enter Pattern: ");
        String pattern = input.nextLine();

        int match = KnuthMorrisPratt(text, pattern);
        System.out.print("Match at index " + match);
        // int result = KMP(search, target);
        // if (result == -1) {
        // System.out.println("NO");
        // } else {
        // System.out.println("YES");
        // }

        input.close();

    }

    public static int KnuthMorrisPratt(String search, String target) {
        int[] failureTable = failureTable(target);

        int targetPointer = 0; // current char in target string
        int searchPointer = 0; // current char in search string

        while (searchPointer < search.length()) { // while there is more to search with, keep searching
            if (search.charAt(searchPointer) == target.charAt(targetPointer)) { // case 1
                // found current char in targetPointer in search string
                targetPointer++;
                if (targetPointer == target.length()) { // found all characters
                    int x = target.length() + 1;
                    return searchPointer - x; // return starting index of found target inside searched string
                }
                searchPointer++; // move forward if not found target string
            } else if (targetPointer > 0) { // case 2
                // use failureTable to use pointer pointed at nearest location of usable string
                // prefix
                targetPointer = failureTable[targetPointer];
            } else { // case 3
                // targetPointer is pointing at state 0, so restart search with current
                // searchPointer index
                searchPointer++;
            }
        }
        return -1;
    }

    /**
     * Returns an int[] that points to last valid string prefix, given target string
     */
    public static int[] failureTable(String target) {
        int[] table = new int[target.length() + 1];
        // state 0 and 1 are guarenteed be the prior
        table[0] = -1;
        table[1] = 0;

        // the pointers pointing at last failure and current satte
        int left = 0;
        int right = 2;

        while (right < table.length) { // RIGHT NEVER MOVES RIGHT UNTIL ASSIGNED A VALID POINTER
            if (target.charAt(right - 1) == target.charAt(left)) { // when both chars before left and right are equal,
                                                                   // link both and move both forward
                left++;
                table[right] = left;
                right++;
            } else if (left > 0) { // if left isn't at the very beginning, then send left backward
                                   // by following the already set pointer to where it is pointing to
                left = table[left];
            } else { // left has fallen all the way back to the beginning
                table[right] = left;
                right++;
            }
        }
        return table;
    }

}
