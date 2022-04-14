import java.util.Map;
import java.util.HashMap;

public class CharFreqMap {

    public static void main(String[] args) {

        String str = "Lorem ipsum dolor sit amet Sed tempore";

        // Scanner input = new Scanner(System.in);
        // String str = input.nextLine();

        String[] words = str.split(" ");

        for (String w : words) {
            Map<Character, Integer> map = new HashMap<Character, Integer>();

            for (int i = 0; i < w.length(); i++) {
                char c = w.charAt(i);
                Integer val = map.get(c);
                if (val != null) {
                    map.put(c, Integer.valueOf(val + 1));
                } else {
                    map.put(c, 1);
                }
            }

            for (int i = 0; i < w.length(); i++) {
                if (map.get(w.charAt(i)) != 0) {
                    System.out.print(w.charAt(i) + "(" + map.get(w.charAt(i)) + ") ");
                    map.put(w.charAt(i), 0);
                }
            }

            System.out.println();
        }

    }

}
