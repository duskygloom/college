import java.util.Scanner;
import java.util.Arrays;

public class BubbleSort
{
    public static void main(String[] args) {
        // creating the array
        System.out.print("Number of elements: ");
        var scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int array[] = new int[n];
        System.out.print(n + " elements: ");
        for (int i = 0; i < n; i++)
            array[i] = scanner.nextInt();
        scanner.close();
        // sorting the array using bubble sort
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (array[j] > array[j+1]) {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
        // printing the array
        System.out.println(Arrays.toString(array));
    }
}
