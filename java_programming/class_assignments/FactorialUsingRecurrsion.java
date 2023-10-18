import java.util.Scanner;

public class FactoriallUsingRecurrsion
{
	public static void main(String args[]) {
		System.out.print("Number: ");
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		sc.close();
		// recurrsion from the same class
		System.out.println("Factorial: " + factorial(num));
		// recurrsion from different class
		AnotherClass obj = new AnotherClass();
		System.out.println("Factorial: " + obj.factorial(num));
		// recurrsion from different class using static method
		System.out.println("Factorial: " + AnotherStaticClass.factorial(num));
		
	}

	private static long factorial(int n) {
		if (n <= 1) return 1;
		else return n * factorial(n-1);
	}
}

class AnotherClass
{
	public long factorial(int n) {
		if (n <= 1) return 1;
		else return n * factorial(n-1);
	}
}

class AnotherStaticClass
{
	public static long factorial(int n) {
	 	if (n <= 1) return 1;
		else return n * factorial(n-1);
	}
}