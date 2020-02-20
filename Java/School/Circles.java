/* 
Student Name: Matthew Henderson
Assignment #3:
Assignment Description: Circles and simpleFigure
Due Date: 10/2/18
Course: COSC 1336-008
Instructor: Frank Yang
*/


import java.awt.*;
public class Circles {
    public static void main(String[] args) {
        DrawingPanel panel = new DrawingPanel(425, 400);
        
        Graphics g = panel.getGraphics();
        panel.setBackground(Color.CYAN);
        
        drawSomething(g,0,0,100,1,10);
        drawSomething(g,18,175,24,6,4);
        drawSomething(g,180,25,40,5,5);
        drawSomething(g,180,250,36,4,6);
  
    }
                                             //g, start x, start y, side length, number of squares per side, concentric circle number (it isnt and cant be a function)
      public static void drawSomething(Graphics g, int x, int y, int s, int n, int c) {
         for(int h = 0; h < n; h++){          //this is he height and uses the 
            for(int w = 0; w < n; w++){
                  
                  int hori = w*s;  // here wanted to simplify the increments for everything, this is the horizontal increment, w = the number for for horizontal for loop,
                  int verti = h*s; //   h = the number for the height for loop)
                  
                  g.setColor(Color.GREEN);
                  g.fillRect(x + hori, y + verti, s, s);
                  
                  g.setColor(Color.BLACK);
                  g.drawRect(x + hori, y + verti, s, s);
                  
                  g.setColor(Color.YELLOW);
                  g.fillOval(x + hori, y + verti, s, s);
                  straightLines(g,x,y,w,h,s);
                  concentricCircles(g,x,y,w,h,n,s,c);
               }
               
            
            }
         }
                                                // g, start x, start y , Horizontal increment, vertical increment, side length) 
         public static void straightLines(Graphics g, int x, int y, int w, int h, int s) {
            int hori = w*s;  
            int verti = h*s;
            int half = s/2;  //because some of the lines went half way down or accross the square, I divided side by half to make the variables easier to use
            
            g.setColor(Color.BLACK);
            g.drawLine(x + hori,          y + verti,        x + s + hori,     y + s + verti);
            g.drawLine(x + s + hori ,     y + verti,        x + hori,         y + s + verti);
            g.drawLine(x + hori + half,   y + verti,        x + hori + half,  y + s + verti); 
            g.drawLine(x + hori,          y + verti + half, x + s + hori,     y + verti + half);
         }
         
         public static void concentricCircles(Graphics g, int x, int y, int w, int h, int n, int s, int c) {
            int hori = w*s;
            int verti = h*s;
            int half = s/2; 
            int many = half/c; /*this is the tricky variable to get right for the circles, since they need  
                              to move over in very specific increments over dependting on the number of concentric circles, 
                              also i didnt have to create a half increment for this one, isntead just including it in "many"
                              */
                              
                               
            for(int i = 0; i < c ; i++){
                g.setColor(Color.BLACK);
                
                //                                                             s-2*s/2/c*i    ==      s(1-i/c)
                g.drawOval(x + hori + (many * i) ,  y + verti + (many * i),    s - 2 * (many * i),    s - 2 *(many * i));  
            
            
            
            }
            
            
          
         }

       
         
}    
