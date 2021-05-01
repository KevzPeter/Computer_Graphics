import java.awt.*; 
import javax.swing.*; 

class HouseCanvas extends JComponent { 

    public void paint(Graphics g) 
    { 
        g.setColor(Color.yellow);
        g.fillRect(100,100,100,100);
        g.fillRect(200,100,200,100);
        g.setColor(Color.black);
        g.drawRect(100,100,100,100); // wall outline
        g.drawRect(200,100,200,100); // wall outline
        g.setColor(new Color(163, 97, 31));
        int x1[]={100,150,200};
        int y1[]={100,50,100};
        g.fillPolygon(x1,y1,3); // top triangle
        g.setColor(new Color(102,51,0));
        int x2[]={150,350,400,200};
        int y2[]={50,50,100,100};
        g.fillPolygon(x2,y2,4); // right trapezium
        int x3[]={100,200,180,80};
        int y3[]={125,125,140,140};
        g.fillPolygon(x3,y3,4); // trapezium over pillars
        g.fillRect(125,160,35,40);//door
        g.fillRect(235,125,30,30);//window1
        g.fillRect(335,125,30,30);//window2
        g.setColor(Color.black);
        g.fillOval(130, 185, 4,4);//doorknob
        g.fillRect(80,140,5,60);//pillar1
        g.fillRect(175,140,5,60);//pillar2
        g.drawLine(250,125,250,154);//window bars
        g.drawLine(235,140,264,140);//window bars
        g.drawLine(350,125,350,154);//window bars
        g.drawLine(335,140,364,140);//window bars
    } 
} 

public class DrawHouse { 
    public static void main(String[] a) 
    { 
        JFrame window = new JFrame();  
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
        window.setBounds(0, 0, 500, 500); 
        window.getContentPane().add(new HouseCanvas()); 
        window.setVisible(true); 
    } 
} 
