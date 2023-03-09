package Decorator;

/**
 * Decorator that mixes Milk with coffee.
 * It is a subclass of CoffeeDecorator, and thus a subclass of Coffee.
 */
class Milk extends CoffeeDecorator {
    /**
     * When creating a decorated Coffee, pass a Coffee to be decorated
     * as a parameter. Note that this can be an already-decorated Coffee.
     */
    public Milk(Coffee decoratedCoffee) {
        super(decoratedCoffee);
    }

    /**
     * Overriding methods defined in the abstract superclass.
     * Enables to provide different behavior for decorated Coffee methods
     */
    public double getCost() {
        return super.getCost() + 0.5;
    }

    public String getIngredients() {
        return super.getIngredients() + ", Milk";
    }
}
