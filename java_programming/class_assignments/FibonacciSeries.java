import java.util.Scanner;

public class FibonacciSeries
{
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("n: ");
		int n = sc.nextInt();
		sc.close();
		System.out.println("nth Fibonacci: " + getNthFibonacci(n));
	}

	private static long getNthFibonacci(int n) {
		n -= 1;
		double rootFive = Math.sqrt(5);
		double nterm = Math.pow(1+rootFive, n);
		nterm -= Math.pow(1-rootFive, n);
		nterm /= Math.pow(2, n) * rootFive;
		return (long)nterm;
	}
}
