import javax.swing.JFrame;

public class ComplexNumber 
{
    public static void main(String[] args) {
        System.out.println(new Complex(1, 2));
    }
}

class Frame extends JFrame
{
    Frame(String title) {
        super(title);
        
    }
}

class Complex
{
    double real, imag;

    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(double real, double imag) {
        this.real = real;
        this.imag = imag;
    }

    @Override
    public String toString() {
        if (imag < 0) return String.valueOf(real) + " - " + String.valueOf(-imag) + "i";
        else return String.valueOf(real) + " + " + String.valueOf(imag) + "i";
    }
}
