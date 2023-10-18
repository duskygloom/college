import java.util.Scanner;

public class factorial
{
	static int get_factorial(int n) {
		int factorial = 1;
		for (int i = 2; i <= n; i++)
			factorial *= i;
		return factorial;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Number: ");
		int n = scanner.nextInt();
		scanner.close();
		System.out.printf("%d! = %d\n", n, get_factorial(n));
	}
}
