import  java.io.*;

import  java.util.*;
public  class  Personality  {
      
     
      public  static  void  main(String[]  args)
                   throws FileNotFoundException {
            
            Scanner  console  =  new  Scanner(System.in);
            String[] fNames = new String[2];
            String[] peeps = new String[2];
            int[] abScore = new int[8];
            prompter(console,fNames);
            
            Scanner  fInput  =  new  Scanner(new  File(fNames[0]));
            
            
            
           
            crafter(fInput, peeps); 
            totaler(peeps,abScore);
            System.out.println(peeps[0] + abScore.toString());
            
            
           
     }
     public  static  String[]  prompter(Scanner  console,String[] fNames)  {
        System.out.println("This program processes a file of answers to the");
        System.out.println("Keirsey Temperament Sorter. It converts the");
        System.out.println("various A and B answers for each person into");
        System.out.println("a sequence of B-percentages and then into a");
        System.out.println("four-letter personality type.");
        System.out.println("");
        System.out.print("input file name?");
        fNames[0] =  console.next();
        System.out.print("output file name?");
        fNames[1]  =  console.next();
        return  fNames;
     }
     public static String[] crafter(Scanner fInput, String[] peeps){
        for(int i = 0; i <= 1; i++){
           if(fInput.hasNext()){
            peeps[i] = fInput.nextLine();
            
           }
        }
        return peeps;
     }
     public static int[] totaler(String[] peeps , int abScore[]){
      for(int i = 0; i <= 69; i++){
         if(peeps[2].toLowerCase().charAt((i+1)) == 'b'){
            abScore[((i+1)%8)/2]++;
         } else if(peeps[2].toLowerCase().charAt((i+1)) == 'a'){
            abScore[(((i+1)%8)/2)+4]++;
         }
            
      }
     
      
      return abScore;
     } 
      
      


}