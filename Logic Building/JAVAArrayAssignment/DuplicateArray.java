
public class DuplicateArray {

	public static void main(String[] args) {
		System.out.print("Enter the size of array: ");
        int n = ConsoleInput.getInt();

        int[] arr = new int[n];

        System.out.println("Enter " + n + " elements:");

        for (int i = 0; i < n; i++) {
            arr[i] = ConsoleInput.getInt();
        }

        System.out.println("Duplicate values:");

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (arr[i] == arr[j]) {
                    System.out.println(arr[i]);
                    break;
                }
            }
        }
    }
}