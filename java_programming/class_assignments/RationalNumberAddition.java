public class RationalNumberAddition 
{
    public static void main(String[] args) {
        RationalNumber num = new RationalNumber(66, 33);
        num.printReducedRational();
    }
}

class ZeroDenominatorException extends Exception
{
    ZeroDenominatorException() {
        System.out.println("Zero cannot be the denominator of a rational number.");
    }
}

class RationalNumber
{
    private int p, q;
    
    RationalNumber() {
        p = 0;
        q = 1;
    }

    RationalNumber(int p, int q) {
        setP(p);
        setQ(q);
    }

    void setP(int newP) {
        p = newP;
    }

    void setQ(int newQ) throws ZeroDenominatorException {
        if (newQ == 0) throw new ZeroDenominatorException();
        q = newQ;
    }

    void reduce() {
        /** reduces the original p and q values */
        int dividend = p, divisor = q, remainder = p % q;
        while (remainder != 0) {
            dividend = divisor;
            divisor = remainder;
            remainder = dividend % divisor;
        }
        // divisor is now GCD
        p /= divisor;
        q /= divisor;
    }

    void printReducedRational() {
        int dividend = p, divisor = q, remainder = p % q;
        while (remainder != 0) {
            dividend = divisor;
            divisor = remainder;
            remainder = dividend % divisor;
        }
        // divisor is now GCD
        System.out.println(p/divisor + "/" + q/divisor);
    }
}
