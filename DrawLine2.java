import java.awt.*; 
import javax.swing.*; 
import java.awt.geom.Line2D; 

class MyCanvas extends JComponent { 

    public void paint(Graphics g) 
    { 
        g.drawLine(100, 200, 200, 100); 
    } 
} 

public class DrawLine2 { 
    public static void main(String[] a) 
    { 
        JFrame window = new JFrame();  
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
        window.setBounds(0, 0, 200, 200); 
        window.getContentPane().add(new MyCanvas()); 
        window.setVisible(true); 
    } 
} 
