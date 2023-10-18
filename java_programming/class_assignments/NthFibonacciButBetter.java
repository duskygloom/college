// import java.util.Scanner;

public class NthFibonacciButBetter
{
	public static void main(String args[]) {
		// Scanner sc = new Scanner(System.in);
		// int n = sc.nextInt();
		// sc.close();
		for (int n = 0; n <= 20; ++n)
			System.out.printf("%d:\t%f\t%f\n", n, nthFibonacci(n), nthFibonacciMy(n));
	}

	static private long combination(int n, int r) {
		if (n-r > r) r = n-r;
		long result = 1;
		for (int i = n; i >= r+1; --i) result *= i;
		for (int i = n-r; i >= 2; --i) result /= i;
		// System.out.println(result);
		return result;
	}

	static private double nthFibonacciMy(int n) {
		double result = 0;
		for (int i = 1; i <= n; i+=2) result += combination(n, i) * Math.pow(5, ((i-1)/2));
		result /= Math.pow(2, n-1);
		return result;
	}

	static private double nthFibonacci(int n) {
		double result = (Math.pow((1.0+Math.sqrt(5)), n));
		result -= (Math.pow((1.0-Math.sqrt(5)), n));
		result /= Math.sqrt(5);
		result /= Math.pow(2, n);
		return result;
	}
}

