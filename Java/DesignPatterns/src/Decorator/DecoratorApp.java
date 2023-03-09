package Decorator;

public class DecoratorApp {
    public static void main(String[] args) {
        Coffee c = new FilterCoffee();
        System.out.println("Cost: " + c.getCost() + "; Ingredients: " + c.getIngredients());
        c = new Milk(c);
        System.out.println("Cost: " + c.getCost() + "; Ingredients: " + c.getIngredients());
        c = new Sprinkles(c);
        System.out.println("Cost: " + c.getCost() + "; Ingredients: " + c.getIngredients());
        c = new Whip(c);
        System.out.println("Cost: " + c.getCost() + "; Ingredients: " + c.getIngredients());
        // Note that you can also stack more than one decorator of the same type
        c = new Sprinkles(c);
        System.out.println("Cost: " + c.getCost() + "; Ingredients: " + c.getIngredients());
        c = new Espresso();
        System.out.println("Cost: " + c.getCost() + "; Ingredients: " + c.getIngredients());
        c = new Milk(c);
        System.out.println("Cost: " + c.getCost() + "; Ingredients: " + c.getIngredients());
    }
}
