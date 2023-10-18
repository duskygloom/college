import java.io.IOException;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;

public class DownloadAlert 
{
    public static void main(String[] args) {
        String url = "http://kaomoji.ru/en";
        try {
        Document websoup = Jsoup.connect(url).get();
        System.out.println(websoup.body());
        } catch (IOException e) {
            System.out.println("Encountered IOException while getting the html of " + url);
        }
    }
}
