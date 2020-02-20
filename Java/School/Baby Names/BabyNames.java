import  java.io.*;
import  java.awt.*;
import  java.util.*;
public  class  BabyNames  {
      public  static  final  String fileName = "names.txt";   //file  name;
      public  static  final  int  sYear  =  1900;
      public  static  final  int  nDecade  =  11;
      public  static  final  int  wDecade  =  50;
      public  static  void  main(String[]  args)  
                   throws FileNotFoundException {
            Scanner  input  =  new  Scanner(new  File(fileName));
            Scanner  console  =  new  Scanner(System.in);
            
            
            String  pName  =  prompter(console);
            
            
            
            
            drawGraph(sYear,nDecade,wDecade,pName,input);
            
            
            
           
     }
     public  static  void  drawChart(Graphics  g,  int  sYear,int  nDecade,int  wDecade,String  pName)  {
           for(int  i  =  0;  i  <  2;  i++){  //yellow
               g.setColor(Color.YELLOW);
               g.fillRect(0,i*530,(nDecade)*wDecade,30);
           }
           g.setColor(Color.BLACK);
           g.drawString(  "Ranking  of  name  \""+pName+"\":",  0,  12);
         for(int  i  =  0;  i  <  11;  i++){  //horizontal  
              g.setColor(Color.LIGHT_GRAY);   
              g.drawLine(0,  i  *  50  +30,(nDecade)*wDecade  ,  i  *  50  +30);
           }
           for(int  i  =  0;  i  <  nDecade;  i++){  //vertical  
              g.setColor(Color.LIGHT_GRAY);   
              g.drawLine(i  *  50,  30,  i  *  50,  530);
           }
           for(int  i  =  0;  i  <  nDecade;  i++){  //scale
              g.setColor(Color.BLACK);
              g.drawString(  Integer.toString(sYear  +i  *  10)  ,  i  *  50,  542);
           }
     }
     public  static  String  prompter(Scanner  console)  {
        System.out.println("This  program  graphs  the  popularity  of  a  name");
        System.out.println("in  Social  Security  baby  name  statistics");
        System.out.println("recorded  since  the  year  1900.");
        System.out.println();
        System.out.print("Type  a  name:  ");
        String  pName  =  console.next();
        return  pName;
     }
     public  static  void  drawGraph(  int  sYear,int  nDecade,int  wDecade,String  pName,  Scanner  input)  {
     int  counter  =  0   ;  
     
        while(counter  <  1){
            if(input.hasNextLine()){
                 String  alpha  =  input.nextLine();
                 Scanner lineScan = new Scanner(alpha);
                 String name = lineScan.next();
                 
                 if(name.contains(pName)){
                     DrawingPanel  panel  =  new  DrawingPanel((nDecade)*wDecade,  560);
                     Graphics  g  =  panel.getGraphics();
                     drawChart(g,sYear,nDecade,wDecade,pName);
                     int lStat = 0; //left point in line
                     int lStatDraw = 1000;
                     int rStat = lineScan.nextInt();// right point in line
                     int rStatDraw = rStat;
                     if(rStatDraw == 0){
                        rStatDraw = 1000;
                     }
                     
                     
                     for(int i = 0; i < nDecade; i++){
                        g.setColor(Color.RED);
                        g.drawLine((i-1)  *  50,  30 + lStatDraw/2,  i  *  50,  30+ rStatDraw/2);
                        g.setColor(Color.BLACK);
                        g.drawString(  Integer.toString(rStat),  (i ) *  50,  rStatDraw/2 + 25);       
                        lStatDraw = rStatDraw;
                        lStat = rStat;
                        if(lineScan.hasNext()){
                           rStat = lineScan.nextInt();
                           rStatDraw = rStat;
                        }
                        if(rStatDraw == 0){
                        rStatDraw = 1000;
                        }
                        
                     }
                     counter++;
                     
                 }  
                 }else  {
                     System.out.println("\""+pName+"\" not found.");
                     counter++;
                 }
        
   
        }
     }
      
}