package AnotherAdapter;

public class CalculatorAdapter extends Calculator {
    Calculator calculator;
    Triangle triangle;

    public int getArea(Triangle t) {
        calculator = new Calculator();
        triangle = t;
        Rectangle r = new Rectangle();
        r.l = triangle.b;
        r.w = (int) (triangle.h * 0.5);
        return calculator.getArea(r);
    }
}
