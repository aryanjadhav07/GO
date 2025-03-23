import java.util.*;
import java.io.*;

class basicJava{
    int num;
    String name;

    basicJava(String names, int number){
        this.num = number;
        this.name = names;
    }

    void check_Even_Odd(){
        if(num % 2 == 0){
            System.out.println("Number is even");
        }
        else{
            System.out.println("Number is odd");
        }
    }

    static int add(int a, int b){
        return a + b;
    }

    void printNo(){
        System.out.print("Printing numbers from 1 to " + num);
        for(int i = 1; i <= num; i++){
            System.out.println(i + " ");
        }
    }

    void checkGrade(char grade){
        switch(grade){
            case 'A':
                System.out.println("Excellent");
                break;
            case 'B':
                System.out.println("Good");
                break;
            case 'C':
                System.out.println("Average");
                break;
            case 'D':
                System.out.println("Poor");
                break;
            default:
                System.out.println("Invalid grade");
        }
    }
}

public class javaBasics{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter your name: ");
        String name = sc.nextLine();
        System.out.println("Enter a number");
        int num = sc.nextInt();

        basicJava obj = new basicJava(name, num);

        System.out.println("Hello " + obj.name + "How are you ? ");
        obj.check_Even_Odd();
        obj.printNo();

        System.out.print("Enter two numbers to add : ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("Sum of two numbers is : " + basicJava.add(a, b)); 


        System.out.print("Enter a grade (A, B, C, D) : ");
        char grade = sc.next().charAt(0);
        obj.checkGrade(grade);
    }
}