import java.util.Scanner;

public class MagicNumber
{
    static boolean isMagicNumber(int number) {
        int sumDigits;
        do {
            sumDigits = 0;
            while (number > 0) {
                sumDigits += number % 10;
                number = number / 10;
            }
            number = sumDigits;
        } while (sumDigits >= 10);
        if (sumDigits == 1) return true;
        return false;
    }

    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        System.out.print("Number of elements: ");
        int arraySize = scanner.nextInt();
        System.out.printf("%d numbers: ", arraySize);
        for (int i = 0; i < arraySize; i++) {
            int num = scanner.nextInt();
            if (isMagicNumber(num)) System.out.printf("%d is a magic number.\n", num);
            else System.out.printf("%d is not a magic number.\n", num);
        }
        scanner.close();
    }
}
