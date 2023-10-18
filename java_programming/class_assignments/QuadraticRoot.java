import java.util.Scanner;

public class QuadraticRoot
{
    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        System.out.print("A B C: ");
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double c = scanner.nextDouble();
        double d = b*b - 4*a*c;
        if (d < 0) {
            d = Math.sqrt(-d);
            double rootA = (-b + d) / (2 * a);
            double rootB = (-b - d) / (2 * a);
            System.out.printf("There are two roots: %.2fi and %.2fi\n", rootA, rootB);
        }
        else if (d == 0) {
            double root = -b / (2 * a);
            System.out.printf("There is one root: %.2f\n", root);
        }
        else {
            d = Math.sqrt(d);
            double rootA = (-b + d) / (2 * a);
            double rootB = (-b - d) / (2 * a);
            System.out.printf("There are two roots: %.2f and %.2f\n", rootA, rootB); 
        }
        scanner.close();
    }
}
