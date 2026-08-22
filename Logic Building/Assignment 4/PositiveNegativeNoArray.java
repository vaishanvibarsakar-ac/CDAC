import java.util.Scanner;

class PositiveNegativeNoArray {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int size = sc.nextInt();

        int[] Elements = new int[size];

        System.out.println("Enter " + size + " elements:");

        for (int i = 0; i < Elements.length; i++) {
            Elements[i] = sc.nextInt();
        }

        int positive = 0;
        int negative = 0;
        int zero = 0;

        // Count positive, negative and zero
        for (int num : Elements) {

            if (num > 0) {
                positive++  ;
            } 
            else if (num < 0) {
                negative++ ;
            } 
            else {
                zero++ ;
            }
        }

        System.out.println("Positive numbers = " + positive);
        System.out.println("Negative numbers = " + negative);
        System.out.println("Zeros = " + zero);

       
    }
}