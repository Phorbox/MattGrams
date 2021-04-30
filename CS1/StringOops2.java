import java.util.*;

public class StringOops 
{
    public static void main(String[] args) 
    {
        Scanner console = new Scanner(System.in);
        System.out.print("Type your name: ");
        String name = console.next();
        process(name);
    }
    public static void process(String name) 
    {
            name = name.replace("a", "e");
            name = name.toUpperCase();
            
            name = name.substring(0, 3);
        System.out.println(name + " has " + name.length() + " letters");
    }
}