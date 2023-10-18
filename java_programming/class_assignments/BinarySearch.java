import java.util.Scanner;

public class BinarySearch
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Number of elements: ");
        int nElements = sc.nextInt(), i;
        int array[] = new int[nElements];
        System.out.print(nElements + " elements: ");
        for (i = 0; i < nElements; ++i)
            array[i] = sc.nextInt();
        System.out.print("Element to search: ");
        int elementToSearch = sc.nextInt();
        sc.close();
        int indexFound = searchElement(elementToSearch, array, 0, nElements);
        if (indexFound == -1)
            System.out.println("Element not found.");
        else
            System.out.printf("%d found at %d.", elementToSearch, indexFound);
    }

    static int searchElement(int element, int[] array, int start, int end) {
        /** 
         * returns the index at which the element is found 
         * if not found, returns -1
         * searches from start to end-1 index
         */
        if (end <= start) return -1;
        int midIndex = start + (end - start) / 2;
        int midElement = array[midIndex];
        if (element < midElement)
            return searchElement(element, array, 0, midIndex);
        else if (element > midElement)
            return searchElement(element, array, midIndex+1, end);
        else 
            return midIndex;
    }
}
