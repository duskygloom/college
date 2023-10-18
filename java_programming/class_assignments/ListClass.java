public class ListClass
{
    public static void main(String[] args) {
        List newList = new List(5);
        System.out.println(newList);
    }
}


class List
{
    int[] array;

    List(int length) {
        array = new int[length];
    }

    @Override
    public String toString() {
        String elements = "";
        for (int element : array)
            elements += Integer.toString(element) + " ";
        return elements;
    }
}
