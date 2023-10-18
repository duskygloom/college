import java.util.Scanner;

public class SortingIntegers
{
	public static void main(String args[]) {
		System.out.print("Number of integers: ");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int array[] = new int[n];
		System.out.print(n + " integers: ");
		for (int i = 0; i < n; ++i) array[i] = sc.nextInt();
		System.out.println("Array: " + arrayToString(array));
		sortArray(array);
		System.out.println("Sorted array: " + arrayToString(array));
		sc.close();
	}

	private static void sortArray(int array[]) {
		for (int i = 1; i < array.length; ++i) {
			for (int j = i-1; j >= 0; --j) {
				if (array[i] < array[j]) {
					int temp = array[i];
					array[i] = array[j];
					array[j] = temp;
					--i;
				}
			}
		}
	}

	private static String arrayToString(int array[]) {
		if (array.length >= 1) {
			String arrayString = "[" + String.valueOf(array[0]);
			for (int i = 1; i < array.length; ++i) arrayString += ", " + String.valueOf(array[i]);
			arrayString += "]";
			return arrayString;
		}
		else return "[]";
		
	}
}