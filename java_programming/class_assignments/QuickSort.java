import java.util.Scanner;
import java.util.Arrays;

public class QuickSort
{
    public static void main(String[] args) {
        System.out.print("Number of elements, n: ");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int array[] = new int[n];
        System.out.print(n + " elements: ");
        for (int i = 0; i < n; i++)
            array[i] = scanner.nextInt();
        scanner.close();
        // sorting the array
        
        // printing the array
        System.out.println("Sorted array: " + Arrays.toString(array));
    }
}
