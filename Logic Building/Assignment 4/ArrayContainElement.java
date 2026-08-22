import java.util.Scanner;
import java.util.Arrays;

class ArrayContainElement {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int size = sc.nextInt();

        int[] Elements = new int[size];

        System.out.println("Enter " + size + " elements:");

        for (int i = 0; i < Elements.length; i++) {
            Elements[i] = sc.nextInt();
        }
System.out.println("Enter the Element to search :");
int search = sc.nextInt();


Arrays.sort(Elements);

int result = Arrays.binarySearch(Elements ,search);

if (result >=0 ){
System.out.println("Found");

}else {

System.out.println("NotFound");
}
}
}


