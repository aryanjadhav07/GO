class myName{

    String name;
    int age;
    
    myName(String name, int age){
    
        this.name = name;
        this.age = age;
    }
    
    static myName createInstance(String name, int age){
        return new myName(name, age);
    }
    
    public void display(){
    
    System.out.println("Name : " + name);
    System.out.println("Age : " + age);
    
    }
    
    
    }
    
    public class Assignment_2{
    
    public static void main(String[] args) {
        myName p1 = myName.createInstance("Aryan", 23);
        myName p2 = myName.createInstance("Raj", 19);
    
        p1.display();
        p2.display();
    }
    
    }
