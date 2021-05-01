import java.awt.*;

public class DrawRectangle extends Frame {
    public void paint(Graphics g) {
        g.drawRect(30, 50, 420, 120);
    }

 public static void main(String args[])
 {
 DrawCircle frame = new DrawRectangle();
 frame.setSize(480, 200);
 frame.setVisible(true);
 }