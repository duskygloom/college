import java.util.Scanner;
import java.util.Arrays;

public class InsertionSort
{
    public static void main(String[] args) {
        // creating the array
        System.out.print("Number of elements: ");
        var scanner = new Scanner(System.in);
        int i, j, n = scanner.nextInt();
        int array[] = new int[n];
        System.out.print(n + " elements: ");
        for (i = 0; i < n; i++)
            array[i] = scanner.nextInt();
        scanner.close();
        // sorting the array using insertion sort
        for (i = 2; i < n; i++) {
            j = i - 1;
            int key = array[i];
            while (key < array[j] && j > 0) {
                array[j+1] = array[j];
                j -= 1;
            }
            array[j] = key;
        }
        // printing the array
        System.out.println(Arrays.toString(array));
    }
}
