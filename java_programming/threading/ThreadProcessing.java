import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class ThreadProcessing 
{
    public static void main(String[] args) {
        var apFile = new File("ArithmeticProgression.java");
        var cnFile = new File("ComplexNumbers.java");
        var apThread = new ReadFileThread("Arithmetic progression", apFile);
        var cnThread = new ReadFileThread("Complex number", cnFile);
        System.out.println("Arithmetic thread priority: " + apThread.getPriority());
        System.out.println("Complex thread priority: " + cnThread.getPriority());
        apThread.start();
        cnThread.start();
    }
}

class ReadFileThread extends Thread
{
    File file;

    ReadFileThread(String threadName, File fileObj) {
        super(threadName);
        file = fileObj;
    }

    @Override
    public void run() {
        try {
            var scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                System.out.println(this.getName() + " > " + scanner.nextLine());
                Thread.sleep(200);
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found: " + file);
        } catch (InterruptedException e) {
            System.out.println(this.getName() + ": Thread interrupted.");
        }
    }
}
