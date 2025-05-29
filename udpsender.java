import java.io.FileInputStream;
import java.net.InetAddress;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class udpsender{
    
    public static void main(String[] args) throws Exception{


        int port = 5000;
        InetAddress add = InetAddress.getByName("127.0.0.1");
        DatagramSocket socket = new DatagramSocket();
        FileInputStream fis = new FileInputStream("Text.txt");
        byte[] buffer = new byte[1024];
        int bytesize;

        System.out.println("Sending file.....");

        while((bytesize = fis.read(buffer)) != -1){
            DatagramPacket packet = new DatagramPacket(buffer, bytesize, add, port);
            socket.send(packet);
        }

        socket.send(new DatagramPacket(new byte[0], 0, add, port));
        System.out.println("File set successfully.");
        fis.close();
        socket.close();
    }

}