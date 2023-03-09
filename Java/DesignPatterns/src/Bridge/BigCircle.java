package Bridge;

public class BigCircle implements DrawShape {
    @Override
    public void drawCircle(int x, int y, int w, int h) {
        new DrawGraphics(x, y, w, h, "Big Circle");
    }
}
