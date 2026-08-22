import java.util.Scanner;
import java.util.Arrays;

class IndexOfElement {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int size = sc.nextInt();

        int[] Elements = new int[size];

        System.out.println("Enter " + size + " elements:");

        for (int i = 0; i < Elements.length; i++) {
            Elements[i] = sc.nextInt();
        }

        System.out.print("Enter the element to search: ");
        int search = sc.nextInt();

     
        Arrays.sort(Elements);

       
        int index = Arrays.binarySearch(Elements, search);

        if (index >= 0) {
            System.out.println("Element found at index: " + index);
        } else {
            System.out.println("Element not found.");
        }

       
    }
}