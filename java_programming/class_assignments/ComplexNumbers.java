import java.util.Scanner;

public class ComplexNumbers 
{
    public static void main(String[] args) {
        double real, imag;
        Scanner scanner = new Scanner(System.in);
        System.out.print("A, Real Imag: ");
        real = scanner.nextDouble();
        imag = scanner.nextDouble();
        Complex aComplex = new Complex(real, imag);
        System.out.print("B, Real Imag: ");
        real = scanner.nextDouble();
        imag = scanner.nextDouble();
        Complex bComplex = new Complex(real, imag);
        scanner.close();
        Complex productComplex = Complex.MULT(aComplex, bComplex);
        System.out.print("Product: ");
        productComplex.display();
        System.out.println("Mod of product: " + productComplex.MOD());
    }
}


class IMG 
{
    double imag;

    IMG() {
        imag = 0.0;
    }

    IMG(double value) {
        this.imag = value;
    }

    void setRealValue(double newValue) {
        this.imag = newValue;
    }

    void display() {
        System.out.println(imag + "i");
    }
}


class Complex extends IMG
{
    double real;

    Complex() {
        imag = real = 0.0;
    }

    Complex(double real, double imag) {
        super(imag);
        this.real = real;
    }

    void setImagValue(double newValue) {
        this.imag = newValue;
    }

    @Override
    void display() {
        if (imag < 0)
            System.out.println(real + " - " + (-imag) + "i");
        else
            System.out.println(real + " + " + imag + "i");
    }

    static Complex MULT(Complex aComplex, Complex bComplex) {
        Complex prod = new Complex();
        prod.real = aComplex.real * bComplex.real - aComplex.imag * bComplex.imag;
        prod.imag = aComplex.real * bComplex.imag + bComplex.real * aComplex.imag;
        return prod;
    }

    double MOD() {
        double mod;
        mod = Math.sqrt(real*real + imag*imag);
        return mod;
    }
}
