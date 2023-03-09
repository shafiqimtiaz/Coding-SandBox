package Flyweight;

import java.util.HashMap;

public class ShapeFactory {

    private static final HashMap<String, Circle> circleMap = new HashMap<>();

    public static Shape getCircle(String colorName) {
        Circle circle = circleMap.get(colorName);

        if (circle == null) {
            circle = new Circle(colorName);
            circleMap.put(colorName, circle);
            System.out.println("~ ~ ~ ~ ~ Creating circle of color : " + colorName);
        }
        return circle;
    }
}
