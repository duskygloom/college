import java.util.Scanner;

public class StackUsingArray
{
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Maximum size of stack: ");
		int maxLength = sc.nextInt();
		Stack s = new Stack(maxLength);
		boolean keepRunning = true;
		while (keepRunning) {
			showMenu();
			System.out.print("Response: ");
			int response = sc.nextInt();
			int value;
			switch (response) {
				case 1: 
					System.out.print("Value: ");
					value = sc.nextInt();
					s.push(value);
					break;
				case 2:
					value = s.pop();
					System.out.println("Popped value: " + value);
					break;
				case 3:
					System.out.print("Stack: ");
					s.displayStack();
					break;
				case 0:
					keepRunning = false;
					break;
				default:
					System.out.println("Invalid choice.");
					break;
			}
			System.out.println();
		}
		sc.close();
	}

	private static void showMenu() {
		System.out.println("1. Push");
		System.out.println("2. Pop");
		System.out.println("3. View");
		System.out.println("0. Quit");
	}

}

class Stack
{
	private int array[];
	private int length;

	Stack(int maxLength) {
		array = new int[maxLength];
		length = 0;
	}

	public void push(int value) {
		if (array.length > length) array[length++] = value;
		else System.out.println("Stack is full.");
	}

	public int pop() {
		if (length > 1) {
			int toPop = array[--length];
			return toPop;
		}
		else if (length == 1) {
			int toPop = array[--length];
			return toPop;
		}
		else System.out.println("Stack is empty.");
		return -1;
	}

	public void displayStack() {
		if (length > 0) {
			System.out.print("[" + String.valueOf(array[0]));
			for (int i = 1; i < length; ++i) System.out.print(", " + array[i]);
			System.out.println("]");
		}
		else System.out.println("[]");
	}
}