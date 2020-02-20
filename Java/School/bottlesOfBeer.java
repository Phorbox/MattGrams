public class bottlesOfBeer {
   public static void main(String[] args) {

      for(int q = 1; q < 5; q++)
      {   // rows
         for(int i = 9; i >= 0; i--)
         {  //descending 
            for(int v = i; v > 0; v--)
            {   //number
               System.out.print(i);
            }
         }
         System.out.println();

      }
   }
}