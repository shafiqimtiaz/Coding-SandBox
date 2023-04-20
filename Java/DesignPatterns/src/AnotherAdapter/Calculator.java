package AnotherAdapter;

public class Calculator {
    Rectangle rect;

    public int getArea(Rectangle r) {
        rect = r;
        return rect.l * rect.w;
    }
}
