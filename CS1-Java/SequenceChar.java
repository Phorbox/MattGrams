public class SequenceChar 
{
   public static void main(String[] args) 
   {


      for(int i = 1; i < 7; i++)
      {    
         for(int l = 5 + (i * 3); l > 0; l--)
         {
            System.out.print("*");
         }
         System.out.println();
      }
   }
}