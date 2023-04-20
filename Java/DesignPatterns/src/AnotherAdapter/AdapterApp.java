package AnotherAdapter;

public class AdapterApp {
    public static void main(String[] args) {
        CalculatorAdapter cal = new CalculatorAdapter();
        Triangle t = new Triangle(20, 10);
        System.out.println("Area " + cal.getArea(t));
    }
}
