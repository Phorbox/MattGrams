import java.awt.*;
public class Smiley {
    public static void main(String[] args) {
        DrawingPanel panel = new DrawingPanel(520, 180);
        Graphics g = panel.getGraphics();
        for(int we = 0; we < 5; we++){
         drawFace(g,we*100,0);
        }
       
   }
   public static void drawFace(Graphics g, int a, int b) {
       g.setColor(Color.BLACK);

       g.drawOval(a + 10, b + 30, 100, 100);
       g.setColor(Color.RED);
   
       g.drawLine(a + 40, b + 100, a + 80, b + 100);
        
        
       g.setColor(Color.BLUE);
   
       for(int eye = 0; eye <=1; eye++){
        
       g.fillOval(a + (30 + (eye*40)), b + 60, 20, 20);
        
       }
   }
    
}