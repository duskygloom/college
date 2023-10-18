import java.util.Scanner;

public class RationalNumber
{
	public static void main(String args[]) {
		Rational a;
		Scanner scan = new Scanner(System.in);
		System.out.print("p q: ");
		try {
			a = new Rational(scan.nextInt(), scan.nextInt());
			System.out.println("Reduced form: " + Rational.reduced(a));
		} catch (Rational.ZeroDenominatorException e) {
			System.exit(0);
		}
		scan.close();
	}
}

class Rational
{
	private int p, q;

	public Rational() {
		// empty constructor
		p = 0;
		q = 1;	// anything non-zero so why not 1
	}

	public Rational(int p, int q) throws ZeroDenominatorException {
		// both p and q can be provided
		if (q == 0) throw new ZeroDenominatorException();
		this.p = p;
		this.q = q;
	}

	@Override
	public String toString() {
		if (q < 0) {
			// making sure there's no negative sign in the denominator
			// not necessary but i like it like this
			return String.valueOf(-p) + "/" + String.valueOf(-q);
		} else {
			return String.valueOf(p) + "/" + String.valueOf(q);
		}
	}

	public static class ZeroDenominatorException extends Exception {
		// creating an exception for when q is 0
		// not really necessary but it's a neat way to force the 'where q != 0'
		// definition of rational numbers
		public ZeroDenominatorException() {
			System.out.println("Denominator cannot be zero.");
		}
	}

	public static Rational reduced(Rational r) throws ZeroDenominatorException {
		// static function which returns the reduced form of r
		// returns cuz changing modifying the original r is risky
		// to reduce we simply have to divide both p and q with their gcd
		int gcd = r.q, p = r.p, temp;
		// can't use r.p and r.q or orignal Rational will be changed
		while (p % gcd != 0) {
			temp = gcd;
			gcd = p % gcd;
			p = temp;
		}
		return new Rational(r.p/gcd, r.q/gcd);
	}
}
