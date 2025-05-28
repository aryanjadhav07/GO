import java.io.FileInputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class udpsender {

	public static void main(String[] args) throws Exception {
	
        int Port = 5000;
		InetAddress Address = InetAddress.getByName("127.0.0.1");
		DatagramSocket Socket = new DatagramSocket();   
		FileInputStream fis = new FileInputStream("Text.txt");
		byte[] Buffer = new byte[1024];
		int ByteSize;
		
		System.out.println("Sending File...");
		
		while((ByteSize = fis.read(Buffer)) != -1){
			DatagramPacket Packet = new DatagramPacket(Buffer, ByteSize, Address, Port);
            Socket.send(Packet);
		}

        Socket.send(new DatagramPacket(new byte[0], 0, Address, Port));

        System.out.println("File Sent");

        fis.close();
        Socket.close();
	
	}
}