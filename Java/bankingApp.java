
public class Banking{

    private String customerName, accountNo, contactNo, address;
    private double balance, interstRate;

    public void createAcc(Scanner sc){

        System.out.println("Enter Customer name: ");
        customerName = sc.nextLine();

        System.out.println("Enter Account number:");
        accountNo = sc.nextLine();

        System.out.println("Enter Initial balance:");
        balance = sc.nextDouble();

        System.out.println("Enter Contact number: ");
        contactNo = sc.nextLine();

        System.out.println("Enter Address: ");
        address = sc.nextLine();

    }

}

public class bankingApp{

    
}

