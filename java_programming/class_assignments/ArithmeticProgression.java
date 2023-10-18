import java.util.Scanner;

public class ArithmeticProgression
{
    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        System.out.print("First element, A: ");
        float a = scanner.nextFloat();
        System.out.print("Common difference, d: ");
        float d = scanner.nextFloat();
        System.out.print("Number of elements, n: ");
        float n = scanner.nextFloat();
        double nTerm = a + (n - 1) * d;
        double sumSeries = n / 2 * (a + nTerm);
        System.out.println("nth term: " + nTerm + "\nSum of n terms: " + sumSeries);
        scanner.close();
    }
}
