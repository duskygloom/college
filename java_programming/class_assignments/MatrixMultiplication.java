import java.util.Scanner;

public class MatrixMultiplication
{
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Dimension of matrix A: ");
		int rows = sc.nextInt();
		int cols = sc.nextInt();
		Matrix a = new Matrix(rows, cols);
		a.getMatrixFromUser(sc, "Matrix A:");
		System.out.print("Dimension of matrix B: ");
		rows = sc.nextInt();
		cols = sc.nextInt();
		Matrix b = new Matrix(rows, cols);
		b.getMatrixFromUser(sc, "Matrix B:");
		sc.close();
		System.out.println("Product:");
		System.out.print(Matrix.multiply(a, b));
	}
}

class Matrix
{
	private int rows, cols;
	private int array[][];

	Matrix() {
		this.rows = 0;
		this.cols = 0;
		array = new int[0][0];
	}

	Matrix(int rows, int cols) {
		this.rows = rows;
		this.cols = cols;
		array = new int[rows][cols];
	}

	public void getMatrixFromUser(Scanner sc, String prompt) {
		System.out.println(prompt);
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				array[i][j] = sc.nextInt();
	}

	public static Matrix multiply(Matrix a, Matrix b) {
		if (a.cols == b.rows) {
			Matrix productMatrix = new Matrix(a.rows, b.cols);
			for (int i = 0; i < a.rows; ++i)
				for (int j = 0; j < b.cols; ++j) {
					productMatrix.array[i][j] = 0;
					for (int k = 0; k < a.cols; ++k)
						productMatrix.array[i][j] += a.array[i][k] * b.array[k][j];
				}
			return productMatrix;
		} else {
			System.out.println("Matrices cannot be multiplied.");
			return new Matrix();
		}
	}

	@Override
	public String toString() {
		String matrixString = "";
		for (int i = 0; i < rows; ++i) {
			if (cols >= 1) {
				matrixString += "[" + array[i][0];
				for (int j = 1; j < cols; ++j) matrixString += ", " + array[i][j];
				matrixString += "]\n";
			}
			else matrixString += "[]\n";
		}
		return matrixString;
	}
}