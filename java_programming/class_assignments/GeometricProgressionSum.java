import java.util.Scanner;

public class GeometricProgressionSum
{
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("a r n: ");
		int a = sc.nextInt();
		int r = sc.nextInt();
		int n = sc.nextInt();
		sc.close();
		System.out.println("Sum of series: " + gpsum(a, r, n));
	}

	private static long gpsum(int a, int r, int n) {
		if (r == 1) return a * n;
		long sum = 1;
		sum = a * (1 - (long)Math.pow(r, n));
		sum /= 1 - r;
		return sum;
	}
}