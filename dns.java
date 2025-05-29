import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public class dns{

    public static void main(String[] args){

       Scanner sc = new Scanner(System.in);

       System.out.println("DNS lookup tool");
       System.out.println("1. URL TO IP ");
       System.out.println("2. IP TO URL");
       System.out.print("Enter your choice : ");
       int choice = sc.nextInt();
       sc.nextLine();

       try{
        if(choice == 1){
            System.out.print("Enter the url(e.g www.google.com) : ");
            String url = sc.nextLine();
            InetAddress add = InetAddress.getByName(url);
            System.out.println("IP address of " + url + " is : " + add.getHostAddress());
        }
        else if(choice == 2){
            System.out.print("Enter the IP address (e.g 142.250.183.100) : ");;
            String ip = sc.nextLine();
            InetAddress add = InetAddress.getByName(ip);
            System.out.println("URL of " + ip + " is : " + add.getHostName());
        }
        else{
            System.out.println("Invalid choice. Please select 1 or 2.");
        }
       }
       catch(UnknownHostException e){
        System.out.println("Error : " + e.getMessage());
       }
           sc.close();
    }

}