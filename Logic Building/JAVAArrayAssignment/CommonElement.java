
public class CommonElement {

	public static void main(String[] args) {
		 System.out.print("Enter size of first array: ");
	        int n1 = ConsoleInput.getInt();

	        int[] arr1 = new int[n1];

	        System.out.println("Enter elements of first array:");

	        for (int i = 0; i < n1; i++) {
	            arr1[i] = ConsoleInput.getInt();
	        }


	        System.out.print("Enter size of second array: ");
	        int n2 = ConsoleInput.getInt();

	        int[] arr2 = new int[n2];

	        System.out.println("Enter elements of second array:");

	        for (int i = 0; i < n2; i++) {
	            arr2[i] = ConsoleInput.getInt();
	        }


	        System.out.println("Common elements:");

	        for (int i = 0; i < n1; i++) {

	            for (int j = 0; j < n2; j++) {

	                if (arr1[i] == arr2[j]) {

	                    System.out.println(arr1[i]);

	                    break;
	                }
	            }
	        }
	    }
	}