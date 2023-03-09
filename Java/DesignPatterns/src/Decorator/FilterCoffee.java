package Decorator;

public class FilterCoffee extends Coffee {
    public double getCost() {
        return 1;
    }

    public String getIngredients() {
        return "Filter Coffee";
    }
}
