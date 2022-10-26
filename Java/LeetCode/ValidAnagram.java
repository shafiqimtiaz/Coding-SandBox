import java.util.*;

public class ValidAnagram {
    /**
     * isAnagram using Hashmap
     */
    public static boolean isAnagramMap(String s, String t) {
        if (s.length() != t.length()) return false;

        char[] sAraay = s.toCharArray();
        char[] tAraay = t.toCharArray();

        Map<Character, Integer> sMap = new HashMap<>();
        Map<Character, Integer> tMap = new HashMap<>();

        int i = 0;
        while (i < s.length()) {
            if (sMap.containsKey(sAraay[i])) sMap.put(sAraay[i], sMap.get(sAraay[i]) + 1);
            else sMap.put(sAraay[i], 1);
            i++;
        }

        i = 0;
        while (i < t.length()) {
            if (tMap.containsKey(tAraay[i])) tMap.put(tAraay[i], tMap.get(tAraay[i]) + 1);
            else tMap.put(tAraay[i], 1);
            i++;
        }

        return sMap.equals(tMap);
    }

    /**
     * isAnagram using Arrays
     */
    public static boolean isAnagramArray(String s, String t) {
        if (s.length() != t.length()) return false;

        char[] sAraay = s.toCharArray();
        char[] tAraay = t.toCharArray();

        Arrays.sort(sAraay);
        Arrays.sort(tAraay);

        for (int i = 0; i < s.length(); i++) {
            if (sAraay[i] != tAraay[i]) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        String s1 = "anagram", t1 = "nagaram";
        String s2 = "rat", t2 = "car";

        System.out.println(isAnagramMap(s1, t1));
        System.out.println(isAnagramMap(s2, t2));

        System.out.println(isAnagramArray(s1, t1));
        System.out.println(isAnagramArray(s2, t2));
    }
}
