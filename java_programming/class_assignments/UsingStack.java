import java.util.Stack;

class EmptyStackError extends Exception {
    EmptyStackError() {
        System.out.println("The stack is empty.");
    }
}

class ArrayStack
{
    private int array[], top;

    ArrayStack() {
        array = new int[0];
        top = 0;
    }

    ArrayStack(int initialSize) {
        array = new int[initialSize];
        top = 0;
    }

    void push(int element) {
        int exArray[] = array, i;
        array = new int[array.length + 1];
        for (i = 0; i < exArray.length; ++i)
            array[i] = exArray[i];
        array[i] = element;
        top = element;
    }

    int pop() throws EmptyStackError {
        if (array.length < 1) throw new EmptyStackError();
        int exArray[] = array, i;
        array = new int[array.length - 1];
        for (i = 0; i < array.length; ++i)
            array[i] = exArray[i];
        top = exArray[i];
        return top; 
    }

    int peek() throws EmptyStackError {
        if (array.length > 0) return top;
        throw new EmptyStackError();
    }

    void print() {
        System.out.print("Stack:");
        for (int i = 0; i < array.length; ++i)
            System.out.print(" " + array[i]);
        System.out.println();
    }
}

public class UsingStack 
{
    public static void main(String[] args) {
        var newStack = new Stack<Integer>();
        newStack.push(21);
        System.out.println(newStack.toString());
        System.out.println(newStack.pop());
        System.out.println(newStack.toString());
        
        var myStack = new ArrayStack();
        myStack.print();
        try {
            System.out.println(myStack.peek());
        } catch EmptyStackError() {

        }
    }
}
