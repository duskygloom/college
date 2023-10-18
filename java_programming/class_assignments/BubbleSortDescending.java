import java.util.Arrays;
import java.util.Scanner;

public class BubbleSortDescending 
{
    public static void main(String[] args) {
        // getting the array
        int n, i, j, temp;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Number of elements: ");
        n = scanner.nextInt();
        int array[] = new int[n];
        System.out.print(n + " elements: ");
        for (i = 0; i < n; i++)
            array[i] = scanner.nextInt();
        scanner.close();
        // sorting array
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-i-1; j++) {
                if (array[j+1] > array[j]) {
                    temp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
            }
        }
        // printing array
        System.out.println("Sorted array: " + Arrays.toString(array));
        // median
        double median;
        if (n % 2 == 0)
            median = (array[n/2] + array[n/2 - 1]) / 2.0;
        else
            median = array[n/2];
        System.out.println("Median: " + median);
    }
}
