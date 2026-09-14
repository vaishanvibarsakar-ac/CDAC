
public class MinMaxArray {

	public static void main(String[] args) {
		 System.out.print("Enter the size of array: ");
	        int n = ConsoleInput.getInt();

	        int[] arr = new int[n];

	        System.out.println("Enter " + n + " elements:");

	        for (int i = 0; i < n; i++) {
	            arr[i] = ConsoleInput.getInt();
	        }

	        int max = arr[0];
	        int min = arr[0];

	        for (int i = 1; i < n; i++) {

	            if (arr[i] > max) {
	                max = arr[i];
	            }

	            if (arr[i] < min) {
	                min = arr[i];
	            }
	        }

	        System.out.println("Maximum value = " + max);
	        System.out.println("Minimum value = " + min);
	    }
	}
