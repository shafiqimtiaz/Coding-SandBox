package Strategy;

public class StrategyApp {
    public static void main(String[] args) {
        Context context = new Context(new OperationAddition());
        System.out.println("10 + 5 = " + context.executeStrategy(10, 5));

        context = new Context(new OperationSubstract());
        System.out.println("10 - 5 = " + context.executeStrategy(10, 5));

        context = new Context(new OperationMultiply());
        System.out.println("10 * 5 = " + context.executeStrategy(10, 5));

        context = new Context(new OperationDivide());
        System.out.println("10 / 5 = " + context.executeStrategy(10, 5));
    }
}
