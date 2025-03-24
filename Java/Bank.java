import java.util.*;

class bankAcc{
    private String customerName, contactNo, address;
    private long accNo;
    private double balance, interestRate;

    public void createAcc(){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Customer Name: ");
        customerName = sc.nextLine();
        System.out.print("Enter contact number: ");
        contactNo = sc.nextLine();
        System.out.print("Enter address: ");
        address = sc.nextLine();
        System.out.print("Enter account number: ");
        accNo = sc.nextLong();
        System.out.print("Enter your initial balance: ");
        balance = sc.nextDouble();
        System.out.print("Enter rate of interest: ");
        interestRate = sc.nextDouble();
        System.out.println("Account created successfully! \n");

    }

    public void displaydetails(){
        System.out.println("<<<< Bank Holder Details >>>>\n");
        System.out.println("Customer Name : " + customerName);
        System.out.println("Contact Number : " + contactNo);
        System.out.println("Address : " + address);
        System.out.println("Acount Number : " + accNo);
        System.out.println("Rate of interest : " + interestRate);
        System.out.println("Balance : " + balance);

    }
}

public class Bank{
    public static void main(String[] args) {
        bankAcc b = new bankAcc();
        b.createAcc();
        b.displaydetails();
    }
}