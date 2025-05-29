import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.io.FileOutputStream;


public class udpreceiver{
    public static void main(String[] args) throws Exception{

        int port = 5000;
        DatagramSocket socket = new DatagramSocket(port);
        FileOutputStream fos = new FileOutputStream("received.txt");
        byte[] buffer = new byte[1024];
        DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

        System.out.println("Waiting for the file....");

        while(true){
            socket.receive(packet);
            if(packet.getLength() == 0){
                break;
            }
            fos.write(packet.getData(), 0, packet.getLength());
        }

        System.out.println("File received successfully");

        fos.close();
        socket.close();
    }
}