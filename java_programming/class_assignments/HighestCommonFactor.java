import java.util.Scanner;

public class HighestCommonFactor
{
    static int getHCF(int a, int b) {
        /** returns -1 if GCD is undefined */
        if (a == 0 || b == 0) return -1;
        int remainder = a % b;
        while (remainder != 0) {
            a = b;
            b = remainder;
            remainder = a % b;
        }
        return b;
    }

    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        System.out.print("Enter two numbers: ");
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int gcd = getHCF(a, b);
        if (gcd == -1)
            System.out.printf("HCF of %d and %d is undefined.\n", a, b);
        else
            System.out.printf("HCF of %d and %d is %d.\n", a, b, getHCF(a, b));
        scanner.close();
    }
}
