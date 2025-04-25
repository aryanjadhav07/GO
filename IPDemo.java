import java.net.*;
import java.util.*;
public class IPDemo {
public static void main(String[] args) {
String host;
Scanner ch = new Scanner(System.in);
System.out.println("1. Enter the Host Name \n2. Enter IP address \nChoice:");
int choice = ch.nextInt();
ch.nextLine(); // Consume newline after int input
if (choice == 1) {
System.out.println("\nEnter the Host Name:");
host = ch.nextLine();
try {
InetAddress address = InetAddress.getByName(host);
System.out.println("IP Address: " + address.getHostAddress());
System.out.println("Host Name: " + address.getHostName());
System.out.println("Host Name and IP Address: " + address.toString());
} catch (UnknownHostException ex) {
System.out.println("Could not find: " + host);
}
} else {
System.out.println("Enter IP Address:");
host = ch.nextLine();
try {
InetAddress address = InetAddress.getByName(host);
System.out.println("Host Name: " + address.getHostName());
System.out.println("IP Address: " + address.getHostAddress());
System.out.println("Host Name and IP Address: " + address.toString());
} catch (UnknownHostException ex) {
System.out.println("Could not find: " + host);
}
}
}
}