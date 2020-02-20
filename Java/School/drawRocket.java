public class drawRocket {
   public static final int size = 50;
   public static void main(String[] args) 
   {
      cone();
      line();
      top();
      bot();
      line();
      bot();
      top();
      line();
      cone();

   }
   public static void cone() 
   {
      for(int row=1;row < size; row++)
      {
         for(int s = size - row;s > 0; s--)
         {
            System.out.print(" ");
         }
         for(int s = row;s > 0; s--)
         {
            System.out.print("/");
         }
         System.out.print("**");
         for(int s = row;s > 0; s--)
         {
            System.out.print("\\");
         }
       
      System.out.println();   
      }
   }
   public static void line() 
   {
      System.out.print("+");
      for(int s = size ;s > 0; s--)
      {
         System.out.print("=*");
      }
      System.out.println("+");   
   }
   public static void top() 
   {
      
      for(int row= (size + 1) / 2 ;row > 0; row--)
      {
         System.out.print("|");
         for(int s = row - 1;s > 0; s--)
         {
            System.out.print(".");
         }
         for(int s = ((size + 1) / 2) + 1 - row;s > 0; s--)
         {
            System.out.print("/\\");
         }
         for(int s = row - 1;s > 0; s--)
         {
            System.out.print(".");
         }
         for(int s = row - 1;s > 0; s--)
         {
            System.out.print(".");
         }
         for(int s = ((size + 1) / 2) + 1 - row;s > 0; s--)
         {
            System.out.print("/\\");
         }
         for(int s = row - 1;s > 0; s--)
         {
            System.out.print(".");
         }
         System.out.println("|");
      }
   }
   public static void bot() 
   {
      for(int row= (size + 1) / 2 ;row > 0; row--)
      {
            System.out.print("|");
            for(int s = ((size + 1) / 2) - row;s > 0; s--)
            {
               System.out.print(".");
            }
            for(int s = row;s > 0; s--){
               System.out.print("\\/");
            }
            for(int s = ((size + 1) / 2) - row;s > 0; s--)
            {
               System.out.print(".");
            }
            for(int s = ((size + 1) / 2) - row;s > 0; s--)
            {
               System.out.print(".");
            }
            for(int s = row;s > 0; s--){
               System.out.print("\\/");
            }
            for(int s = ((size + 1) / 2) - row;s > 0; s--)
            {
               System.out.print(".");
            }
            System.out.println("|");
      }
   
   }


}