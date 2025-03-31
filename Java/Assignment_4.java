abstract class shape{

    double width, height;
    
        shape(double width, double height){
    
            this.width = width;
            this.height = height;
    
        }
    
        abstract double area();
    }
    
    class reactangle extends shape{
    
        reactangle(double width, double height){
            super(width, height);
        }
    
        @Override
    
        double area(){
            return width * height;
        }
    }
    
    class triangle extends shape{
    
        triangle(double width, double height){
            super(width, height);
        }
    
        @Override
        double area(){
            return width * height * 0.5;
        }
    }
    
    public class Assignment_4{
    
        public static void main(String[] args) {
            
            shape rect = new reactangle(5,10);
            shape tri = new triangle(5,10);
    
            System.out.println("Area of reactangle : " + rect.area());
            System.out.println("Area of triangle : " + tri.area());
    
        }
    }
    