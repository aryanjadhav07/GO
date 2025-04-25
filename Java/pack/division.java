package pack;
public class division{
double a, b;
    public division(double a, double b){

        this.a = a;
        this.b = b;
    }

    public void div(){
        double result = a / b;
        System.out.println("Division of " + a + " and " + b + " is " + result);
    }

}