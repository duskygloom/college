import java.util.Scanner;

public class Combination
{
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("n r: ");
		int n = sc.nextInt();
		int r = sc.nextInt();
		sc.close();
		System.out.println("nCr: " + ncr(n, r));
	}

	private static long ncr(int n, int r) {
		long result = 1;
		int i;
		if (n-r > r) r = n-r;
		for (i = n; i >= r+1; --i) result *= i;
		for (i = n-r; i >= 2; --i) result /= i;
		return result;
	}
}