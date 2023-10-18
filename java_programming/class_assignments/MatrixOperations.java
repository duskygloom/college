import java.util.Scanner;

public class MatrixOperations
{
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		System.out.print("Dimensions of A: ");
		Matrix a = new Matrix(scan.nextInt(), scan.nextInt());
		a.fillMatrix(scan);
		System.out.print("Dimensions of B: ");
		Matrix b = new Matrix(scan.nextInt(), scan.nextInt());
		b.fillMatrix(scan);
		scan.close();
		try {
			System.out.println("\nA+B");
			System.out.println(Matrix.add(a, b));
			System.out.println("A*B");
			System.out.println(Matrix.multiply(a, b));
		}
		catch (Matrix.IncompatibleDimensionException e) {
			System.out.println("Cannot complete the operations.");
		}
	}
}

class Matrix
{
	public int rows, cols;
	public int matrix[][];
	
	public Matrix(int rows, int cols) {
		this.rows = rows;
		this.cols = cols;
		matrix = new int[rows][cols];
	}

	public static class IncompatibleDimensionException extends Exception {
		public IncompatibleDimensionException(String message) {
			System.out.println("Incompatible dimension: " + message);
		}
	}

	@Override
	public String toString() {
		String matrixOut = "";
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j)
				matrixOut += String.valueOf(matrix[i][j]) + " ";
			matrixOut += "\n";
		}
		return matrixOut;
	}

	public void fillMatrix(Scanner scanner) {
		System.out.println("Enter " + rows + "x" + cols + " matrix");
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				matrix[i][j] = scanner.nextInt();
	}

	public static Matrix add(Matrix a, Matrix b) throws IncompatibleDimensionException {
		if (a.rows == b.rows && a.cols == b.cols) {
			Matrix msum = new Matrix(a.rows, a.cols);
			for (int i = 0; i < msum.rows; ++i)
				for (int j = 0; j < msum.cols; ++j)
					msum.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
			return msum;
		}
		else {
			throw new IncompatibleDimensionException("Dimension must be same for matrix addition.");
		}
	}

	public static Matrix multiply(Matrix a, Matrix b) throws IncompatibleDimensionException {
		if (a.cols == b.rows) {
			Matrix mprod = new Matrix(a.rows, b.cols);
			for (int i = 0; i < mprod.rows; ++i)
				for (int j = 0; j < mprod.cols; ++j)
					for (int k = 0; k < a.cols; ++k)
						mprod.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
			return mprod;
		}
		else {
			throw new IncompatibleDimensionException("a.cols must be the same as b.rows for matrix multiplication.");
		}
	}
}

