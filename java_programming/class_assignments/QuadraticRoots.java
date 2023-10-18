import java.util.Scanner;


public class QuadraticRoots
{
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("A B C: ");
		double a = sc.nextDouble();
		double b = sc.nextDouble();
		double c = sc.nextDouble();
		sc.close();
		printRoots(a, b, c);
	}

	private static void printRoots(double a, double b, double c) {
		double d = b*b - 4*a*c;
		if (d > 0) {
			// two real roots
			double sqrtD = Math.sqrt(d);
			double rootA = (-b + sqrtD) / (2*a);
			double rootB = (-b - sqrtD) / (2*a);
			System.out.println("Roots: " + rootA + ", " + rootB);
		}
		else if (d == 0) {
			// one real root
			double rootA = -b / (2*a);
			System.out.println("Root: " + rootA);
		}
		else {
			// two imaginary roots
			double sqrtD = Math.sqrt(-d);
			double rootReal = -b / (2*a);
			String rootA = complexString(rootReal, sqrtD / (2*a));
			String rootB = complexString(rootReal, -sqrtD / (2*a));
			System.out.println("Roots: " + rootA + ", " + rootB);
		}
	}

	private static String complexString(double real, double imag) {
		String complex = String.valueOf(real);
		if (imag < 0) complex += String.valueOf(imag) + "i";
		else complex += "+" + String.valueOf(imag) + "i";
		return complex;
	}
}

