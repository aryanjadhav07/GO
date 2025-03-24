import java.util.Scanner;

class BankAccount {
    private String customerName, contactNumber, address;
    private long accountNumber;
    private double balance, interestRate;

    // Method to create an account
    public void createAccount() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Customer Name: ");
        customerName = sc.nextLine();
        System.out.print("Enter Account Number: ");
        accountNumber = sc.nextLong();
        System.out.print("Enter Initial Balance: ");
        balance = sc.nextDouble();
        System.out.print("Enter Rate of Interest (in %): ");
        interestRate = sc.nextDouble();
        sc.nextLine(); // Consume newline
        System.out.print("Enter Contact Number: ");
        contactNumber = sc.nextLine();
        System.out.print("Enter Address: ");
        address = sc.nextLine();
        
        System.out.println("Account created successfully!\n");
    }

    // Method to deposit money
    public void deposit() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter deposit amount: ");
        double amount = sc.nextDouble();
        if (amount > 0) {
            balance += amount;
            System.out.println("Amount deposited successfully!\n");
        } else {
            System.out.println("Invalid deposit amount!\n");
        }
    }

    // Method to withdraw money
    public void withdraw() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter withdrawal amount: ");
        double amount = sc.nextDouble();
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawal successful!\n");
        } else {
            System.out.println("Insufficient balance or invalid amount!\n");
        }
    }

    // Method to compute interest
    public void computeInterest() {
        double interest = (balance * interestRate) / 100;
        balance += interest;
        System.out.println("Interest earned: " + interest);
        System.out.println("Updated balance after adding interest: " + balance + "\n");
    }

    // Method to display account details
    public void displayBalance() {
        System.out.println("\nAccount Details:");
        System.out.println("Customer Name: " + customerName);
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Balance: " + balance);
        System.out.println("Rate of Interest: " + interestRate + "%");
        System.out.println("Contact Number: " + contactNumber);
        System.out.println("Address: " + address + "\n");
    }
}

public class BankingSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BankAccount account = new BankAccount();
        int choice;

        while (true) {
            System.out.println("======= Banking System =======");
            System.out.println("1. Create Account");
            System.out.println("2. Deposit");
            System.out.println("3. Withdraw");
            System.out.println("4. Compute Interest");
            System.out.println("5. Display Balance");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    account.createAccount();
                    break;
                case 2:
                    account.deposit();
                    break;
                case 3:
                    account.withdraw();
                    break;
                case 4:
                    account.computeInterest();
                    break;
                case 5:
                    account.displayBalance();
                    break;
                case 6:
                    System.out.println("Exiting... Thank you!");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice! Please try again.\n");
            }
        }
    }
}
