import java.util.Scanner;

public class ComplexNumber
{
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		System.out.print("Complex number A\nreal imag: ");
		Complex a = new Complex();
		a.real = scan.nextDouble();
		a.imag = scan.nextDouble();
		System.out.print("Complex number B\nreal imag: ");
		Complex b = new Complex();
		b.real = scan.nextDouble();
		b.imag = scan.nextDouble();
		System.out.println();
		System.out.println("A: " + a);
		System.out.println("B: " + b);
		System.out.println("A*B: " + Complex.mult(a, b));
		scan.close();
	}
}

class Complex
{
	public double real, imag;

	public Complex() {
		// constructor with no arguments
		real = imag = 0.0;
	}

	@Override
	public String toString() {
		// now can be printed using System.out.print
		if (imag < 0.0) {
			return String.valueOf(real) + "-" + String.valueOf(-imag) + "i";
		} else {
			return String.valueOf(real) + "+" + String.valueOf(imag) + "i";
		}
	}

	public static Complex mult(Complex a, Complex b) {
		// static function which takes two Complex and returns the product as a Complex
		Complex cprod = new Complex();
		cprod.real = a.real*b.real - a.imag*b.imag;
		cprod.imag = a.real*b.imag + a.imag*b.real;
		return cprod;
	}
}
