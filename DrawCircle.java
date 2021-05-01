import java.awt.*;


public class DrawCircle extends Frame {

  public void paint(Graphics g) {
     g.drawRect(100,100,200,200);
  }
              
  public static void main(String args[]) 
  {
      DrawCircle frame = new DrawCircle();       
      frame.setSize(480, 200);
      frame.setVisible(true);
   }
}