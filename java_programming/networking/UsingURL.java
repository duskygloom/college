import java.io.FileOutputStream;
import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;

public class UsingURL 
{
    public static void main(String[] args) throws Exception {
        URL url = new URL("http://kaomoji.ru/en");
        System.out.println("Port: " + url.getPort());
        System.out.println("File: " + url.getFile());
        URLConnection connection = url.openConnection();
        System.out.println("Content type: " + connection.getContentType());
        System.out.println("Content length: " + connection.getContentLength());
        InputStream in = connection.getInputStream();
        int c;
        FileOutputStream fout = new FileOutputStream("url.html", false);
        while ((c = in.read()) != -1) {
            fout.write(c);
            // if ((char)c == '>') System.out.println();
        }
        fout.close();
    }
}
