/* 
Student Name: Matthew Henderson
Assignment #5:
Assignment Description: Admission
Issue Date: 10/23/18
Due Date: 11/6/2018
Course: COSC 1336-013
Instructor: Frank Yang
*/

import java.util.*;
public class Guessing {
   public static final int range = 100; //range from 1 to this number
      public static void main(String[] args)
      {
         Scanner console = new Scanner(System.in);
         int gameRE = 0;
         
         ruleOfLaw();
         gameRE = game(console,gameRE);
         results(gameRE);
      }

   public static int game(Scanner console, int gameRE)
   {
      Random rand = new Random();
      int gameTotal = 0; //1
      int guessTotal = 0; // 2
      int guessMax = 0; // 3
      int guessNumber = 0; //temp
      int gameO = 0; // ditto
      
      while(gameO < 1)
      {
         int guessO = 0; //whether or not loop will end
         
         gameTotal++;
         System.out.println("I'm thinking of a number...");
         int guessRandom = rand.nextInt(range)+1;
         
         
         while(guessO < 1)
         { 
            System.out.print("Your guess? ");
            
            int guessUser = console.nextInt();
            guessNumber++;
            
            if(guessUser > guessRandom)
            {
               System.out.println("lower");
            }
            else if(guessRandom > guessUser)
            {
               System.out.println("higher");
            
            
            }else if( guessRandom == guessUser){
               System.out.println("you got it right in " + guessNumber + " guesses");
               guessO++;
               if(guessNumber > guessMax)
               {
                  guessMax = guessNumber;
               }   
               guessTotal = guessTotal + guessNumber;
               guessNumber = 0;
               
            
            }
         
        }
            System.out.print("Do you want to play again?");
            String gameR = console.next();
            while(!gameR.startsWith("n") && !gameR.startsWith("N") && !gameR.startsWith("y") && !gameR.startsWith("Y"))
            {
               System.out.print("Do you want to play again?");
               gameR = console.next();
            }
            if( gameR.startsWith("n") || gameR.startsWith("N"))
            {
               gameO++;  
            }
            
            
      }
         gameTotal = gameTotal * 1000000; //1000000
         guessTotal = guessTotal * 1000; // 1000
         guessMax = guessMax * 1; // 1
         
         
         gameRE = gameTotal+guessTotal+guessMax;
         
         System.out.println(gameRE);
         return gameRE;
   }
   
   public static void results(int gameRE)
   {
      int tGames = gameRE  / 1000000;
      System.out.println(tGames);
      int tGuess = (gameRE % 1000000) / 1000;
      System.out.println(tGuess);
      int mGuess = (gameRE % 1000);
      System.out.println(mGuess);
      
      System.out.println("Overall results:");
      System.out.println("   total games   = "+ tGames);
      System.out.println("   total guesses = "+ tGuess);
      double guessGame = 0.0;
      guessGame = tGuess/tGames;
      System.out.println("   guesses/game  = "+ guessGame);
      System.out.println("   max guesses   = "+ mGuess);
       
   }
   
   public static void ruleOfLaw()
   {
      System.out.println("This program allows you to play a guessing game.");
      System.out.println("I will think of a number between 1 and " + (range));
      System.out.println("and will allow you to guess until you get it.");
      System.out.println("For each guess, I will tell you whether the");
      System.out.println("right answer is higher or lower than your guess.");
   }


}