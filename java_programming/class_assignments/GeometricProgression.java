import java.util.Scanner;

public class GeometricProgression 
{
    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        System.out.print("First element, a: ");
        float a = scanner.nextFloat();
        System.out.print("Common ratio, r: ");
        float r = scanner.nextFloat();
        System.out.print("Number of terms, n: ");
        int n = scanner.nextInt();
        scanner.close();
        double term = a;
        double sumTerms = term;
        for (int i = 1; i < n; i++) {
            term *= r;
            sumTerms += term;
        }
        System.out.println("nth element: " + term + "\nSum of elements: " + sumTerms);
    }
}
