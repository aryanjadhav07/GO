package pack;

public class Substraction {

    double a, b;

    public Substraction(double a, double b){
        this.a = a;
        this.b = b;
    }

    public void sub(){
        double result = a - b;
        System.out.println("Substraction of " + a + " and " + b + " is: " + result);
    }
}