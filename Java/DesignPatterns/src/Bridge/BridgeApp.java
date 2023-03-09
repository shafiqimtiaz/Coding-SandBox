package Bridge;


public class BridgeApp {
    public static void main(String[] args) {
        Shape bigCircle = new Circle(100, 100, 300, 300, new BigCircle());
        Shape smallCircle = new Circle(50, 50, 150, 150, new SmallCircle());
        bigCircle.draw();
        smallCircle.draw();
    }
}