import java.util.*;

class invaliduserexception extends Exception{
    public invaliduserexception(String message){
        super(message);
    }
}

public class Assignment9{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        try{

            System.out.println("Enter your age : ");
            int age = sc.nextInt();

            System.out.println("Enter your Income : ");
            double income = sc.nextDouble();
            sc.nextLine();

            System.out.println("Enter your city : ");
            String city = sc.nextLine();

            System.out.println("Do you have 4-Wheeler ? Yes or No : ");
            String vehical = sc.nextLine();

            if(age < 18 || age > 55){
                throw new invaliduserexception("Age should be between 18 and 55.");
            }

            if(income < 50000 || income > 100000){
                throw new invaliduserexception("Income should be between 50000 to 100000.");
            }

            List<String> Cities = Arrays.asList("Pune", "Mumbai", "Banglore", "Chennai");
            if(!Cities.contains(city)){
                throw new invaliduserexception("Cities should be Pune or Mumbai or Banglore or Chennai.");
            }

            if(!vehical.equalsIgnoreCase("Yes")){
                throw new invaliduserexception("Should have four wheeler.");
            }
            
            System.out.println("User meets all eligibility criteria");
        }

        catch(invaliduserexception e){
            System.out.println("Invalid user : " + e.getMessage());
        }
        catch(Exception e){
            System.out.println("Error : " + e.getMessage());
        }
        finally{
            sc.close();
        }

    }
}