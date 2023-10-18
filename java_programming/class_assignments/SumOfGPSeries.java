import java.util.Scanner;

public class SumOfGPSeries
{
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		System.out.print("First element, A: ");
		double a = scan.nextDouble();
		System.out.print("Common ratio, r: ");
		double r = scan.nextDouble();
		System.out.print("Number of elements, n: ");
		int n = scan.nextInt();
		scan.close();
		System.out.print("Sum of the series: ");
		System.out.println(sumGP(a, r, n));
	}

	private static double sumGP(double a, double r, int n) {
		if (n < 1) return 0.0;
		else if (n == 1) return a;
		else if (r == 1) return a*n;
		else {
			double sum = a;
			sum *= (1.0 - Math.pow(r, n));
			sum /= (1.0 - r);
			return sum;
		}
	}
}

