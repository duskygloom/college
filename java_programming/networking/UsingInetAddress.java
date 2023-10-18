import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;

public class UsingInetAddress
{
    public static void main(String[] args) throws Exception{
        System.out.println(InetAddress.getLocalHost());
        for (InetAddress a : InetAddress.getAllByName("google.com"))
            System.out.println(a);
        Socket socket = new Socket("internic.net", 43);
        // something wrong with the website
        InputStream in = socket.getInputStream();
        OutputStream out = socket.getOutputStream();
        out.write("google.com".getBytes());
        int c;
        while ((c = in.read()) != -1)
            System.out.print((char)c);
        socket.close();
        System.out.println();
    }
}