import java.util.Scanner;

public class LowestCommonMultiple
{
	public static void main(String args[]) {
		System.out.print("Two positive numbers: ");
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		int hcf = gcd(a, b);
		System.out.println("LCM: " + (a*b) / hcf);
	}

	private static int gcd(int a, int b) {
		int remainder = a % b;
		while (remainder != 0) {
			a = b;
			b = remainder;
			remainder = a % b;
		}
		return b;
	}
}