import java.util.Scanner;

public class SumOfNumbers {
    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        // System.out.print("Number of elements in array: ");
        // int numElements = scanner.nextInt();
        // int numArray[] = new int[numElements];
        // int sumArray = 0;
        // for (int i = 0; i < numElements; i++) {
        //     System.out.print("Element " + (i+1) + ": ");
        //     numArray[i] = scanner.nextInt();
        //     sumArray += numArray[i];
        // }
        int sumElements = 0;
        System.out.print("Elements: ");
        while (true) {
            sumElements += scanner.nextInt();
            if (scanner.next("%c") != " ") break;
        }
        scanner.close();
        System.out.println("Sum of elements = " + sumElements);
    }
}
