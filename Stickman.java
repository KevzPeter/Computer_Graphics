import java.awt.*; 
import javax.swing.*; 

class MyCanvas3 extends JComponent { 

    public void paint(Graphics g) 
    { 
        g.drawRect(5,5,190,190);
        g.drawOval(90,60,20,20);
        g.drawLine(100,80,100,120);
        g.drawLine(100,100,80,100);
        g.drawLine(100,100,120,75);
        g.drawLine(100,120,85,135);
        g.drawLine(100,120,115,135);
    } 
} 

public class Stickman { 
    public static void main(String[] a) 
    { 
        JFrame window = new JFrame();  
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
        window.setBounds(0, 0, 200, 200); 
        window.getContentPane().add(new MyCanvas3()); 
        window.setVisible(true); 
    } 
} 
