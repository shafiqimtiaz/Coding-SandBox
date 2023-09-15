package example;

import java.util.*;

public class Collections {
    public static void main(String[] args) {
//        testList();
//        testMap();
//        testRegex();
//        stringToList();
        testSubstring();
    }

    public static void testSubstring() {
        System.out.println("*** TEST SUBSTRING ***");
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = sc.nextLine();
        System.out.print("Enter the value of k: ");
        int k = sc.nextInt();

        if (k <= 0 || k > str.length()) {
            System.out.println("Invalid value of k");
            return;
        }

        String smallest = str.substring(0, k);
        String largest = str.substring(str.length() - k);

        String resSL = str.replace(smallest, largest);
        String resLS = str.replace(largest, smallest);

        System.out.println(resSL + "\n" + resSL);
    }

    public static void stringToList() {
        System.out.println("*** STR to LIST ***");
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter string");
        String[] strArr = sc.nextLine().split("\\s+");
        List<Integer> strList = strArrToList(strArr);

        System.out.println(strList);
    }

    public static List<Integer> strArrToList(String[] strArr) {
        List<String> strList = Arrays.asList(strArr);
        return strList.stream().map(Integer::parseInt).toList();
    }

    public static int[] strArrToInt(String[] strArr) {
        return Arrays.stream(strArr).mapToInt(Integer::parseInt).toArray();
    }

    public static void testRegex() {
        System.out.println("*** TEST REGEX ***");
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();

        String[] strArr = str.split("\\s+");
        int[] intArr = strArrToInt(strArr);

        System.out.println(Arrays.toString(intArr));
        sc.close();
    }

    public static void testMap() {
        System.out.println("Map\n-------------");

        // character frequency counter
        String str = "Fuzzy Wuzzy was a bear. Fuzzy Wuzzy had no hair. Fuzzy Wuzzy wasn’t fuzzy, was he?".toLowerCase();
        String noSpaceStr = str.replaceAll("[^a-zA-Z]", "");
        Map<Character, Integer> charMap = new HashMap<>();
        for (Character c : noSpaceStr.toCharArray()) {
            if (charMap.containsKey(c)) charMap.put(c, charMap.get(c) + 1);
            else charMap.put(c, 1);
        }
        System.out.println(charMap);

//        charMap.clear();
        System.out.println("is charMap empty? " + charMap.isEmpty());

        System.out.println("-------------");

        // REGEX for capturing everything which are not alphanumeric and whitespace - [^a-zA-Z\s]
        String[] words = str.replaceAll("[^a-zA-Z\\s]+", "").split(" ");
//        System.out.println(Arrays.asList(words));
        Map<String, Integer> wordMap = new HashMap<>();
        for (String elem : words) {
            if (wordMap.containsKey(elem)) wordMap.put(elem, wordMap.get(elem) + 1);
            else wordMap.put(elem, 1);
        }
        System.out.println("Size of wordMap = " + wordMap.size());
        System.out.println(wordMap);

        System.out.println("-------------");

        String str2 = "jon snow knows nothing".toLowerCase();
        Map<Character, Integer> charCount = new HashMap<>();
        for (String elem : str2.replaceAll("[^a-zA-Z ]", "").split(" ")) {
            for (Character c : elem.toCharArray()) {
                if (charCount.containsKey(c)) charCount.put(c, charCount.get(c) + 1);
                else charCount.put(c, 1);
            }
        }
        System.out.println("Before (" + charMap.size() + ") : " + charMap);
        charMap.putAll(charCount); // merging an old map with new one
        System.out.println("After (" + charMap.size() + ") : " + charMap);

        System.out.println("-------------");

        // using iterator and keyset
        Iterator<String> it1 = wordMap.keySet().iterator();

        while (it1.hasNext()) {
            String key = it1.next();
            System.out.println(key + " -> " + wordMap.get(key));
        }

        System.out.println("-------------");

        // using Collection values
        Collection<Integer> wordCount = wordMap.values();
        Iterator<String> it2 = wordMap.keySet().iterator();
        for (Integer val : wordCount) {
            System.out.println(it2.next() + " x" + val);
        }

        System.out.println("-------------");

        // using iterator and entryset
        Set<Map.Entry<String, Integer>> entries = wordMap.entrySet();
        for (Map.Entry<String, Integer> entry : entries) {
            System.out.println(entry.getKey() + " repeats " + entry.getValue() + " times");
        }

        System.out.println("-------------");

        wordMap.remove("fuzzy");
        System.out.println("After removal of fuzzy: " + wordMap);
    }

    public static void testList() {
        System.out.println("ArrayList\n-------------");

        List<String> animals = new ArrayList<>(); // creates a new list
        animals.add("cat"); // add elem at end of list
        animals.add("dog");
        animals.add("horse");

        System.out.println(animals.size());
        if (animals.contains("dog"))
            System.out.println(animals.indexOf("tiger"));

        System.out.println("-------------");

        animals.remove("cat"); // removes existing elem from list
        animals.add("zebra");
        animals.add(1, "rabbit");

        List<String> carnivores = new ArrayList<>();
        carnivores.add("tiger");
        carnivores.add("lion");
        animals.addAll(carnivores);

        String temp = carnivores.get(1); // gets elem at index
        System.out.println(temp);

        animals.set(2, "human"); // sets elem at index

        System.out.println(animals);

        System.out.println("-------------");

        java.util.Collections.sort(animals); // sort

        for (String elem : animals)
            System.out.println(elem);

        System.out.println("-------------");

        java.util.Collections.reverse(animals);

        Iterator<String> it = animals.iterator();
        while (it.hasNext())
            System.out.println(it.next());

        System.out.println("-------------");

        java.util.Collections.shuffle(animals);

        animals.forEach(System.out::println);

        System.out.println("-------------");

        String[] animalsArr = animals.toArray(new String[0]);
        for (String elem : animalsArr) System.out.println(elem);

        animals.clear(); // clears the list

        System.out.println("-------------");

        List<String> listNames = Arrays.asList("Tom", "John", "Mary", "Peter", "David", "Alice");
        System.out.println("Original list: " + listNames);
        List<String> subList = listNames.subList(2, 5);
        System.out.println("Sub list: " + subList);

        System.out.println("-------------");
    }
}


