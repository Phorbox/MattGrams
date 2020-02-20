import java.awt.*;
public class SimpleFigure 
{
   public static void main(String[] args) 
   {
        DrawingPanel panel = new DrawingPanel(250, 200);
        
        Graphics g = panel.getGraphics();
        panel.setBackground(Color.YELLOW);
        g.setColor(Color.GREEN);
        g.fillRect(10, 20, 200, 160);
        
        for(int o = 0; o < 2; o++)
        {
           g.setColor(Color.RED);
           g.fillOval((o * 100) + 10, (o * 80) + 20, 100 , 80);
           g.setColor(Color.BLACK);
           g.drawLine((o*100)+10 ,  (o*80)+60 , (o*100)+110 , (o*80)+60);
           g.drawLine((o*100)+60 ,  (o*80)+20 , (o*100)+60 , (o*80)+100);


        }

        
   }
    
}