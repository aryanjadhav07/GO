package pack;

public class Addition{

double a, b;

    public Addition(double a, double b){
        this.a = a;
        this.b = b;
    }


    public void add(){
        double result = a + b;
        System.out.println("Additon of " + a + " and " + b + " is " + result);
    }

}
