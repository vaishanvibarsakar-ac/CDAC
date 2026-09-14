
public class ReverseArray {

	public static void main(String[] args) {
		System.out.print("Enter the size of array: ");
        int n = ConsoleInput.getInt();

        int[] arr = new int[n];

        System.out.println("Enter " + n + " elements:");

        for (int i = 0; i < n; i++) {
            arr[i] = ConsoleInput.getInt();
        }

        System.out.println("Original array:");

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }

        System.out.println();

        System.out.println("Reversed array:");

        for (int i = n - 1; i >= 0; i--) {
            System.out.print(arr[i] + " ");
        }
    }
}
