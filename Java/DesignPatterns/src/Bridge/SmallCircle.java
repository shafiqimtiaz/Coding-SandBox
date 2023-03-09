package Bridge;

public class SmallCircle implements DrawShape {
    @Override
    public void drawCircle(int x, int y, int w, int h) {
        new DrawGraphics(x, y, w, h, "Small Circle");
    }
}
