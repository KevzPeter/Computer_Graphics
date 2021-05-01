import java.awt.*;
import java.util.*;

public class DDA extends Frame {
    
  public static void main(String args[]){
    DDA frame = new DDA();    
    frame.setSize(300,300);   
    frame.setVisible(true);
  }
    public void paint(Graphics g) {
        double dx, dy, x, y,steps;
        int k;
        Scanner in =new Scanner(System.in);
        System.out.println("Enter coordinates of 1st point");
        double x1=in.nextDouble();
        double y1=in.nextDouble();
        System.out.println("Enter coordinates of 2nd point");
        double x2=in.nextDouble();
        double y2=in.nextDouble();
        dx = x2 - x1;
        dy = y2 - y1;

        if (Math.abs(dy)<=Math.abs(dx)) {
           steps=Math.abs(dx);
        } else {
           steps=Math.abs(dy);
        }
        dx = dx/steps;  
        dy = dy/steps;  
        x = x1;
        y = y1;
        k=1;
        g.fillOval((int)x1,(int)y1,5,5);
        while(k<=steps) {
            x += dx;
            y += dy;
            k++;
            g.fillOval((int)x,(int)y,5,5);
        }
        
    }
}