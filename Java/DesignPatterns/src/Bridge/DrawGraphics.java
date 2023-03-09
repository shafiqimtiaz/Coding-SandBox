package Bridge;

import javax.swing.*;
import java.awt.*;

public class DrawGraphics extends JFrame {
    private final int xTopLeft;
    private final int yTopLeft;
    private final int width;
    private final int height;

    public DrawGraphics(int xTopLeft, int yTopLeft, int width, int height, String label) {
        super(label);
        this.xTopLeft = xTopLeft;
        this.yTopLeft = yTopLeft;
        this.width = width;
        this.height = height;
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 500);
        setVisible(true);
    }

    public void paint(Graphics gh) {
        super.paint(gh);
        gh.drawOval(xTopLeft, yTopLeft, width, height);
    }
}
