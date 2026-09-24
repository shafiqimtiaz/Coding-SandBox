import java.util.*;

class MinMaxMap {
    public static void main(String[] args) {

        Map<String, Integer> map = new HashMap<String, Integer>();

        String[] type = { "sorting", "confirmation", "Transportation", "ordering", "Transportation", "sorting" };
        Integer[] value = { 1, 7, 3, 4, 5, 6 };

        for (int i = 0; i < type.length; i++) {
            map.put(type[i], value[i]);
        }

        int min = Collections.min(map.values());
        int max = Collections.max(map.values());

        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            if (entry.getValue() == min) {
                System.out.println("MINIMUM : " + entry.getKey() + " " + map.get(entry.getKey()));
            }
            if (entry.getValue() == max) {
                System.out.println("MAXIMUM : " + entry.getKey() + " " + map.get(entry.getKey()));
            }
        }
    }
}