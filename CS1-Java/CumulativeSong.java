/* 
Student Name: Matthew Henderson
Assignment #1:
Assignment Description: cumulative song
Issue Date: 8/28/18
Due Date: 9/11/2018
Course: COSC 1336-013
Instructor: Frank Yang
*/
public class CumulativeSong {
   public static void main(String[] args) {
      swallow();
      System.out.println("fly,");
      fly();
     
      swallow();
      System.out.println("spider,"); 
      System.out.println("That wriggled and iggled and jiggled inside her.");
      spider();
      
      swallow();
      System.out.println("bird,");
      System.out.println("How absurd to swallow a bird.");
      bird();
      
      swallow();
      System.out.println("cat,"); 
      System.out.println("Imagine that to swallow a cat.");
      cat();
     
      swallow();
      System.out.println("dog,"); 
      System.out.println("What a hog to swallow a dog.");
      dog();
     
      swallow();
      System.out.println("man,"); 
      System.out.println("Quite a plan to swallow a man.");
      man(); 
     
      System.out.println("There was an old woman who swallowed a horse,"); 
      System.out.println("She died of course.");
        
   }
      public static void fly() {
      System.out.println("I don't know why she swallowed that fly,\nPerhaps she'll die.");
      System.out.println();
      
      }
      public static void spider() {
      System.out.println("She swallowed the spider to catch the fly,");
      fly();
      }
      public static void bird() {
      System.out.println("She swallowed the bird to catch the spider,");
      spider();
      }
      public static void cat() {
      System.out.println("She swallowed the cat to catch the bird,");
      bird();
      }
      public static void dog() {
      System.out.println("She swallowed the dog to catch the cat,");
      cat();
      }
      public static void man() {
      System.out.println("She swallowed the man to catch the dog");
      dog();
      }
      public static void swallow() {
      System.out.print("There was an old woman who swallowed a ");
      }
   
}