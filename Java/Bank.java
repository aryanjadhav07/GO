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

    public void deposit(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the amount to be deposited: ");
        double amount = sc.nextDouble();
        if(amount > 0){
            balance += amount;
            System.out.println("Amount " + amount + " deposited successfully! \n");
        }
        else{
            System.out.println("Invalid deposit amount! \n");
        }
    }

    public void withdraw(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the amount to be withdrawn: ");
        double amount = sc.nextDouble();
        if(amount > 0  && amount <= balance){
            balance -= amount;
            System.out.println("Withdrawal successfull! \n");
        }
        else{
            System.out.println("Insufficient balance or invalid amount! \n");
        }
    }
        
    }


public class Bank{
    public static void main(String[] args) {
        bankAcc b = new bankAcc();
        b.createAcc();
        b.deposit();
        b.displaydetails();
        b.withdraw();
        b.displaydetails();
    }
}