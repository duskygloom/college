import java.util.Scanner;

public class CoordinateSystemConversion
{
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		System.out.print("Cartesian, x y: ");
		var c = new CartesianCoordinate(scan.nextDouble(), scan.nextDouble());
		System.out.print("Polar, r theta: ");
		var p = new PolarCoordinate(scan.nextDouble(), scan.nextDouble());
		scan.close();
		System.out.println(c + " -> " + new PolarCoordinate(c));
		System.out.println(p + " -> " + new CartesianCoordinate(p));
	}

	public static double roundTwoDecimalPlaces(double d) {
		double rounded = (double)Math.round(d*100) / 100;
		return rounded;
	}
}

class CartesianCoordinate
{
	double x, y;

	CartesianCoordinate(double x, double y) {
		this.x = x;
		this.y = y;
	}

	CartesianCoordinate(PolarCoordinate p) {
		y = p.r * Math.sin(Math.toRadians(p.theta));
		x = p.r * Math.cos(Math.toRadians(p.theta));
	}

	@Override
	public String toString() {
		return "(" + CoordinateSystemConversion.roundTwoDecimalPlaces(x) + ", " + CoordinateSystemConversion.roundTwoDecimalPlaces(y) + ")";
	}
}

class PolarCoordinate
{
	double r, theta;

	PolarCoordinate(double r, double theta) {
		this.r = r;
		this.theta = theta;
	}

	PolarCoordinate(CartesianCoordinate c) {
		r = Math.sqrt(c.x*c.x + c.y*c.y);
		if (c.x == 0) theta = 90;
		else theta = Math.toDegrees(Math.atan(c.y/c.x));
	}

	@Override
	public String toString() {
		return "(" + CoordinateSystemConversion.roundTwoDecimalPlaces(r) + ", " + CoordinateSystemConversion.roundTwoDecimalPlaces(theta) + "°)";
	}
}