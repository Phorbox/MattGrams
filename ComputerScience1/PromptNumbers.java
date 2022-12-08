import java.util.*; // to use Arrays

public class PromptNumbers 
{
    public static void main(String[] args)
    {
        System.out.print("How many numbers will you enter? ");
        Scanner console = new Scanner (System.in); 
        int count = console.nextInt();
        int[] a = new int[count];
        
        for( int z = 0 ; z < count; z++)
        {
           System.out.print("Type a number: "); 
           a[z] =  console.nextInt();
        }

        System.out.println();
        System.out.println("Your numbers in forward order:");
        printForward(a);
        System.out.println();
        
        System.out.println("Your numbers in backward order:");
        printBackward(a);
    }

    // Prints the elements of the given array in forward order.
    public static void printForward(int[] a) 
    {
        for (int i = 0; i < a.length; i++) 
        {
            System.out.println(a[i]);
        }
    }
    // Prints the elements of the given array in backward order.
    public static void printBackward(int[] a) 
    {
        for (int i = a.length - 1; i >= 0; i--) 
        {
            System.out.println(a[i]);
        }
    }
}