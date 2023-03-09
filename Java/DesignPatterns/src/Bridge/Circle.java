package Bridge;

public class Circle extends Shape {
    private final int x;
    private final int y;
    private final int w;
    private final int h;

    public Circle(int x, int y, int w, int h, DrawShape drawShape) {
        super(drawShape);
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
    }

    public void draw() {
        drawShape.drawCircle(x, y, w, h);
    }
}
