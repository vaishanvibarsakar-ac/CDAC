
public class ArraySum {

	public static void main(String[] args) {
		 System.out.print("Enter the size of array: ");
	        int n = ConsoleInput.getInt();

	        int[] arr = new int[n];

	        int sum = 0;

	        System.out.println("Enter " + n + " elements:");

	        for (int i = 0; i < n; i++) {
	            arr[i] = ConsoleInput.getInt();
	        }

	        for (int i = 0; i < n; i++) {
	            sum = sum + arr[i];
	        }

	        System.out.println("Sum of array elements = " + sum);
	    }
}