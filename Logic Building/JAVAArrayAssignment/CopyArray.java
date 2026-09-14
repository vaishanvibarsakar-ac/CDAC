
public class CopyArray {

	public static void main(String[] args) {
		   System.out.print("Enter the size of array: ");
	        int n = ConsoleInput.getInt();

	        int[] arr = new int[n];
	        int[] copy = new int[n];

	        System.out.println("Enter " + n + " elements:");

	        // Read original array
	        for (int i = 0; i < n; i++) {
	            arr[i] = ConsoleInput.getInt();
	        }

	        // Copy array by iterating
	        for (int i = 0; i < n; i++) {
	            copy[i] = arr[i];
	        }

	        System.out.println("Original array:");

	        for (int i = 0; i < n; i++) {
	            System.out.print(arr[i] + " ");
	        }

	        System.out.println();

	        System.out.println("Copied array:");

	        for (int i = 0; i < n; i++) {
	            System.out.print(copy[i] + " ");
	        }
	    }
	}