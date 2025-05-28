import java.io.FileOutputStream;
import java.net.DatagramSocket;
import java.net.DatagramPacket;

public class udpreceiver {

    public static void main(String[] args) throws Exception {

        int Port = 5000;
        DatagramSocket Socket = new DatagramSocket(Port);
        FileOutputStream fos = new FileOutputStream("Received.txt");
        byte[] Buffer = new byte[1024];
        DatagramPacket Packet = new DatagramPacket(Buffer, Buffer.length);

        System.out.println("Waiting for file...");

        while(true){
            Socket.receive(Packet);
            if(Packet.getLength() == 0) break;
            fos.write(Packet.getData(), 0, Packet.getLength());
        }

        System.out.println("File Received");

        fos.close();
        Socket.close();

    }

}