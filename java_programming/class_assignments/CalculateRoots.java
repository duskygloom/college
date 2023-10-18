import java.util.Scanner;

public class CalculateRoots 
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Degree, highest power of x: ");
        int degree = sc.nextInt(), i;
        Polynomial userEquation = new Polynomial(degree);
        System.out.print((degree+1) + " coefficients: ");
        for (i = degree; i >= 0; --i)
            userEquation.setCoefficient(sc.nextDouble(), i);
        System.out.print("Equation: ");
        userEquation.printEquation();
        System.out.print("Range: ");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        sc.close();
        try {
            System.out.println("Root: " + userEquation.findRoot(a, b));
        } catch (IncorrectRangeException e) {
            System.out.println("Select a better range :(");
        }
    }
}

class IncorrectRangeException extends Exception
{
    IncorrectRangeException(double a, double b) {
        System.out.println("Incorrect range specified: " + a + " and " + b);
    }
}

class Polynomial
{
    private int degree;
    private double coefficients[];

    private final double zeroValueError = 0.0000001;

    Polynomial(int degree) {
        this.degree = degree;
        coefficients = new double[degree+1];
    }

    void setCoefficient(double coefficient, int pos) {
        /// similar to adding coefficient * x^(pos) to equation
        coefficients[pos] = coefficient;
    }

    double solveFor(double x) {
        /// returns the solution of the equation for given x
        double solution = 0.0;
        for (int i = 0; i <= degree; ++i)
            solution += coefficients[i] * Math.pow(x, i);
        return solution;
    }

    void printEquation() {
        /// neat way to display equation
        int i;
        double coefficient;
        System.out.print(coefficients[degree] + "x^" + degree);
        for (i = degree-1; i > 0; --i) {
            coefficient = coefficients[i];
            if (coefficient < 0)
                System.out.print(" - " + -coefficient + "x^" + i);
            else
                System.out.print(" + " + coefficient + "x^" + i);
        }
        coefficient = coefficients[0];
        if (coefficient < 0)
            System.out.println(" - " + -coefficient);
        else
            System.out.println(" + " + coefficient);
    }

    double findRoot(double a, double b) throws IncorrectRangeException {
        /** 
         * finds and returns a root between a and b using
         * Bisection method
         * raises an error if incorrect a and b
         */
        double solutionA = solveFor(a), solutionB = solveFor(b), solutionRoot = zeroValueError + 1;
        if (solutionA == 0.0) return a;
        if (solutionB == 0.0) return b;
        if (solutionA * solutionB > 0.0) throw new IncorrectRangeException(a, b);
        // below is the part where root exists
        double root;
        root = (a + b) / 2;
        solutionRoot = solveFor(root);
        while (solutionRoot > zeroValueError || solutionRoot < -zeroValueError) {
            // System.out.println("Root: " + root + ", Solution: " + solutionRoot);
            if (solutionA * solutionRoot > 0.0) {
                a = root;
                solutionA = solutionRoot;
            }
            else {
                b = root;
                solutionB = solutionRoot;
            }
            root = (a + b) / 2;
            solutionRoot = solveFor(root);
        }
        return root;
    }
}
