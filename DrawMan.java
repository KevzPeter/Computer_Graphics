import java.awt.*;
import javax.swing.*;

class ManCanvas extends JComponent {

    public void paint(Graphics g) {
        // hair
        g.fillRect(101, 90, 49, 40);
        // head
        g.setColor(Color.pink);
        g.fillRect(120, 150, 10, 35);
        g.fillOval(100, 100, 50, 50);
        g.setColor(Color.black);
        g.fillOval(112, 115, 5, 5);
        g.fillOval(132, 115, 5, 5);
        g.drawArc(120, 130, 10, 10, 180, 180);
        g.drawOval(100, 100, 50, 50);
        // neck
        g.drawLine(120, 150, 120, 165);// outline
        g.drawLine(130, 150, 130, 165);// outline
        // shirt
        g.setColor(Color.blue);
        g.fillRect(75, 165, 100, 100);
        // pants
        g.setColor(Color.red);
        int x1[] = { 75, 70, 105, 125, 145, 180, 175 };
        int y1[] = { 265, 390, 390, 295, 390, 390, 265 };
        g.fillPolygon(x1, y1, 7);
         // belt
         g.setColor(new Color(102,51,0));
         g.fillRect(75, 265, 100, 5);
        // right-shoe
        g.setColor(Color.black);
        int x4[] = { 70, 62, 105, 105 };
        int y4[] = { 390, 395, 395, 390 };
        g.fillPolygon(x4, y4, 4);
        // left-shoe
        int x5[] = { 145, 145, 188, 180 };
        int y5[] = { 390, 395, 395, 390 };
        g.fillPolygon(x5, y5, 4);
        // left arm
        g.setColor(Color.pink);
        int x2[] = { 75, 45, 75, 75, 60, 75 };
        int y2[] = { 165, 215, 265, 245, 215, 185 };
        g.fillPolygon(x2, y2, 6);
        // right arm
        int x3[] = { 175, 205, 175, 175, 190, 175 };
        int y3[] = { 165, 215, 265, 245, 215, 185 };
        g.fillPolygon(x3, y3, 6);
    }
}

public class DrawMan {
    public static void main(String[] a) {
        JFrame window = new JFrame();
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setBounds(0, 0, 500, 500);
        window.getContentPane().add(new ManCanvas());
        window.setVisible(true);
    }
}
