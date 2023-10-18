import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CharacterInput 
{
    public static void main(String[] args) {
        var stdinBuffer = new BufferedReader(new InputStreamReader(System.in));
        boolean keepReading = true;
        String input = "";
        char ch;
        while (keepReading) {
            try {
                if ((ch = (char)stdinBuffer.read()) == 'q') keepReading = false;
                else input += ch;
            } catch (IOException e) {
                System.out.println("Something went wrong while reading from buffer.");
            }
        }
        System.out.println("Input: " + input);
        try {
            System.out.println("Still in buffer: " + stdinBuffer.readLine());
        } catch (IOException e) {
            System.out.println("Something went wrong while reading from buffer.");
        }
    }
}
