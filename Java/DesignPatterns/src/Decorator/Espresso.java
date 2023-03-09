package Decorator;

/**
 * Kind of Coffee
 */
public class Espresso extends Coffee {
    public double getCost() {
        return 1.25;
    }

    public String getIngredients() {
        return "Strong Coffee";
    }
}

