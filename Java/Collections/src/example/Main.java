package example;

import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
    public static void main(String[] args) {
//        testList();
//        testMap();
//        testGenerics();
//        testThreads();
        testSynchronization();
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

        Collections.sort(animals); // sort

        for (String elem : animals)
            System.out.println(elem);

        System.out.println("-------------");

        Collections.reverse(animals);

        Iterator<String> it = animals.iterator();
        while (it.hasNext())
            System.out.println(it.next());

        System.out.println("-------------");

        Collections.shuffle(animals);

        animals.forEach(elem -> System.out.println(elem));

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

    public static void testGenerics() {
        // Create Integer arrays m1, m2
        Integer[][] m1 = new Integer[][]{{1, 2, 3}, {4, 5, 6}, {1, 1, 1}};
        Integer[][] m2 = new Integer[][]{{1, 1, 1}, {2, 2, 2}, {0, 0, 0}};

        // Create an instance of IntegerMatrix
        IntegerMatrix integerMatrix = new IntegerMatrix();

        System.out.println("\nm1 + m2 is ");
        GenericMatrix.printResult(
                m1, m2, integerMatrix.addMatrix(m1, m2), '+');

        System.out.println("\nm1 * m2 is ");
        GenericMatrix.printResult(
                m1, m2, integerMatrix.multiplyMatrix(m1, m2), '*');
    }

    public static void testThreads() {
        // Create tasks
        Runnable printA = new PrintChar('a', 100);
        Runnable printB = new PrintChar('b', 100);
        Runnable print100 = new PrintNum(100);

        // Create threads
//        Thread thread1 = new Thread(printA);
//        Thread thread2 = new Thread(printB);
//        Thread thread3 = new Thread(print100);

//        thread2.setPriority(Thread.MAX_PRIORITY);
//        thread3.setPriority(Thread.MIN_PRIORITY);

        // Start threads
//        thread1.start();
//        thread2.start();
//        thread3.start();

        // Create a fixed thread pool with maximum three threads
        ExecutorService executor1 = Executors.newFixedThreadPool(1);
        ExecutorService executor2 = Executors.newCachedThreadPool();

        // Submit runnable tasks to the executor
        executor1.execute(printA);
        executor1.execute(printB);
        executor1.execute(print100);

        //executor2.execute(print100);

        // Shut down the executor
        executor1.shutdown();
        executor2.shutdown();
    }

    public static void testSynchronization() {
        AccountWithoutSync account1 = new AccountWithoutSync();
//        account1.test();

        AccountWithSyncUsingLock account2 = new AccountWithSyncUsingLock();
//        account2.test();

        ThreadCooperation threadCooperation = new ThreadCooperation();
        threadCooperation.test();
    }
}


