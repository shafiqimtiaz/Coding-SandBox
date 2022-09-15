import java.util.*;

public class Main {
    public static void main(String[] args) {
        System.out.println("Practice Collections\n-------------");
        testList();
        testMap();
    }


    public static void testMap(){
        System.out.println("Map\n-------------");
        Map<Integer, String> map = new HashMap<>();
    }

    public static void testList(){
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
        for(String elem: animalsArr) System.out.println(elem);

        animals.clear(); // clears the list

        System.out.println("-------------");

        List<String> listNames = Arrays.asList("Tom", "John", "Mary", "Peter", "David", "Alice");
        System.out.println("Original list: " + listNames);
        List<String> subList = listNames.subList(2, 5);
        System.out.println("Sub list: " + subList);

        System.out.println("-------------");
    }
}