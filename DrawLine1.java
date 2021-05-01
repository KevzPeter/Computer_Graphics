import java.awt.*;
import javax.swing.*;

class MyCanvas extends JComponent {
    public void paint(Graphics g) {
        g.drawLine(100, 100, 200, 200);
    }
}

public class DrawLine1 {
    public static void main(String[] a) {
        JFrame window = new JFrame();
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setBounds(30, 30, 200, 200);
        window.getContentPane().add(new MyCanvas());
        window.setVisible(true);
    }
}