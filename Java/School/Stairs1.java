import java.awt.*;
public class Stairs1 
{
    public static void main(String[] args) 
    {
        DrawingPanel panel = new DrawingPanel(110, 110);
        Graphics g = panel.getGraphics();
        for (int i = 0; i < 10; i++) 
        {
            g.drawRect(5, 5 + ((9-i) * 10), 10 * ((i) + 1), 10);
        }
    }
    public static void drawStuff(Graphics g, int a, int b, int c) 
    {
        g.drawLine(a, 45, b, c);
    }
}