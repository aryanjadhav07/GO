import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public class dns {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("DNS Lookup Tool");
        System.out.println("1. URL to IP");
        System.out.println("2. IP to URL");
        System.out.print("Enter your choice (1 or 2): ");
        int choice = scanner.nextInt();
        scanner.nextLine(); // consume leftover newline

        try {
            if (choice == 1) {
                System.out.print("Enter URL (e.g., www.google.com): ");
                String url = scanner.nextLine();
                InetAddress address = InetAddress.getByName(url);
                System.out.println("IP Address of " + url + " is: " + address.getHostAddress());
            } else if (choice == 2) {
                System.out.print("Enter IP address (e.g., 142.250.183.100): ");
                String ip = scanner.nextLine();
                InetAddress address = InetAddress.getByName(ip);
                System.out.println("Host name for IP " + ip + " is: " + address.getHostName());
            } else {
                System.out.println("Invalid choice.");
            }
        } catch (UnknownHostException e) {
            System.out.println("DNS lookup failed: " + e.getMessage());
        }

        scanner.close();
    }
}
