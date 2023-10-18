import java.util.Scanner;

public class ImaginaryAndComplex
{
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		System.out.print("Imaginary number\nimag: ");
		Imaginary imag = new Imaginary(scan.nextDouble());
		System.out.print("Complex number\nreal imag: ");
		Complex comp = new Complex(scan.nextDouble(), scan.nextDouble());
		scan.close();
		System.out.println("\nImaginary number: " + imag + "\nComplex number: " + comp);
	}
}

class Imaginary
{
	public double imag;

	public Imaginary() {
		imag = 0.0;
	}

	public Imaginary(double imag) {
		this.imag = imag;
	}

	@Override
	public String toString() {
		return String.valueOf(imag) + "i";
	}
}

class Complex extends Imaginary
{
	public double real;

	public Complex() {
		super(0.0);
		real = 0.0;
	}

	public Complex(double real, double imag) {
		super(imag);
		this.real = real;
	}

	@Override
	public String toString() {
		if (imag < 0) {
			return String.valueOf(real) + String.valueOf(imag) + "i";
		} else {
			return String.valueOf(real) + "+" + String.valueOf(imag) + "i";
		}
	}
}

