import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.util.ArrayList;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class BasicUsage 
{
    public static void main(String[] args) {
        var kaomojiList = new ArrayList<String>();
        int f = Kaomoji.fetchKaomojis(kaomojiList);
        System.out.println("Fetched " + f + " kaomojis.");
        try {
            FileWriter writer = new FileWriter("kaomojis.txt", 
                Charset.forName("UTF-8"), false);
            for (String s : kaomojiList) writer.write(s+"\n");
            writer.close();
        } catch (IOException e) {
            System.out.println("Could not do IO operation.");
        }
    }
}

class Kaomoji
{
    final private static String baseurl = "http://kaomoji.ru";
    final private static String ensiteurl = baseurl + "/en";

    public static Document getSoup() {
        /**
         * returns null if something went wrong
         * else returns the soup of the ensite
         */
        try {
            Document soup = Jsoup.connect(ensiteurl).get();
            soup.outputSettings().charset("UTF-8");
            return soup;
        } catch (IOException e) {
            System.out.println("Something went wrong while reading " + ensiteurl);
        }
        return null;
    }

    public static int fetchKaomojis(ArrayList<String> kaomojiList) {
        int fetched = 0;
        Document doc = Kaomoji.getSoup();
        Elements kaomojiTables = doc.getElementsByClass("table_kaomoji");
        for (Element e : kaomojiTables) {
            for (Element span : e.getElementsByTag("span")) {
                if (span.text() != "") {
                    kaomojiList.add(span.text());
                    ++fetched;
                }
            }
        }
        return fetched;
    }
}
