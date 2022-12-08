import java.util.*;  // for Scanner
public class processName {
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print(Please enter your full name: );
        String name = console.nextLine();
        String lastName = name.substring(name.indexOf(" ") + 1);
        String firstInitial = name.substring(0,name.indexOf(" "));
        String allName = lastName + ", " + firstInitial ;
        
        
        System.out.println("Your name in reverse order is " + allName);
    }
}