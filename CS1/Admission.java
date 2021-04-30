/* 
Student Name: Matthew Henderson
Assignment #4:
Assignment Description: Admission
Issue Date: 10/2/18
Due Date: 10/16/2018
Course: COSC 1336-013
Instructor: Frank Yang
*/

import java.util.*;
public class Admission 
{
   public static void main(String[] args) 
   {
      Scanner console = new Scanner(System.in);
      System.out.println("This program compares two applicants to");
      System.out.println("determine which one seems like the stronger");
      System.out.println("applicant. For each candidate I will need");
      System.out.println("either SAT or ACT scores plus a weighted GPA.");
      stuff(console);
   }
   
   public static void stuff(Scanner console) 
   {
      
      double a = 0;
      double b = 0;
      
      a = stuff(console , 1);
      a = Math.round(a * 10) / 10.0;
   
      b = stuff(console , 2);
      b = Math.round(b * 10) / 10.0;

      System.out.println("First applicant overall score = " + a);
      System.out.println("Second applicant overall score = " + b);

      if(a > b)
      {
      System.out.println("The first applicant seems to be better");
      }
      else if(b > a)
      {
      System.out.println("The second applicant seems to be better");
      }
      else if(b == a)
      {
      System.out.println("Neither applicant seems to be better");
      }
      
   }

   public static double stuff(Scanner console, int n)
   {
      System.out.println("Information for applicant #" + n +":");
      double too = 0;
      too = exam(console) + gpa(console);
      return too;
   
   }
   public static double testchecker(Scanner console){
      int test = kind(console);
      double tester = 0.0;
      
      if(test == 1){
         tester = sat(console);
         
          
      }else if(test == 2){
         tester = act(console);
         
         
      }else {
         System.out.print("n/a");
         
      }
      return tester;
   
   
   
   }
   public static double act(Scanner console){
      double a = eng(console);
      double b = amath(console);
      double c = aread(console);
      double d = science(console);
      double score = ((a+b+c+d)/4)/36*100;
      score = Math.round(score * 10) / 10.0;
      return score;
   
   }
   public static double sat(Scanner console){
      double a = math(console);
      double b = read(console);
      double c = write(console);
      double score = ((((b + c)/2)+ a)/2)/8;
      score = Math.round(score * 10) / 10.0;
      return score ;
   
   }
   
   public static int kind(Scanner console){
      System.out.print("   do you have 1) SAT scores or 2) ACT scores? "); 
      int kind = console.nextInt(); 
      System.out.println(); 
      return kind; 
   }
   
   public static double math(Scanner console){
      System.out.print("   SAT math? "); 
      double math = console.nextDouble(); 
      System.out.println(); 
      return math; 
   }
   
   public static double read(Scanner console){
      System.out.print("   SAT critical reading? "); 
      double read = console.nextDouble(); 
      System.out.println(); 
      return read; 
   }
   
   public static double write(Scanner console){
      System.out.print("   SAT writing? "); 
      double write = console.nextDouble(); 
      System.out.println(); 
      return write; 
   }
   
   public static double all(Scanner console){
      System.out.print("   overall GPA? "); 
      double all = console.nextDouble(); 
      System.out.println(); 
      return all; 
   }
   
   public static double max(Scanner console){
      System.out.print("   max GPA? "); 
      double max = console.nextDouble(); 
      System.out.println(); 
      return max; 
   }
   
   public static double script(Scanner console){
      System.out.print("   Transcript Multiplier? "); 
      double script = console.nextDouble(); 
      System.out.println(); 
      return script; 
   }
   
   
   public static double gpa(Scanner console){
      double a = all(console);
      double b = max(console);
      double c = script(console);
      double result = a/b*100*c;
      result = Math.round(result * 10) / 10.0;
      System.out.print("   GPA score = " + result); 
     
      System.out.println(); 
      System.out.println(); 
      return result;
   }
   
   public static double exam(Scanner console){
      double exam = testchecker(console); 
      System.out.print("   Exam score = " + exam); 
      System.out.println(); 
      System.out.println(); 
      return exam;
   }
   
   public static double eng(Scanner console){
      System.out.print("   ACT English? "); 
      double eng = console.nextDouble(); 
      System.out.println(); 
      return eng; 
   }
   
   public static double amath(Scanner console){
      System.out.print("   ACT math? "); 
      double amath = console.nextDouble(); 
      System.out.println(); 
      return amath; 
   }
   
   public static double aread(Scanner console){
      System.out.print("   ACT reading? "); 
      double aread = console.nextDouble(); 
      System.out.println(); 
      return aread; 
   }
   
   public static double science(Scanner console){
      System.out.print("   ACT science? "); 
      double science = console.nextDouble(); 
      System.out.println(); 
      return science; 
   }
}