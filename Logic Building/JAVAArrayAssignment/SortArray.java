
import java.util.Arrays;


public class SortArray {

	public static void main(String[] args) {
		int [] arr = {5 , 2,9,1,6};
		Arrays.sort(arr);
		
		
		System.out.println("Sorted Array:");
		for(int num :arr) {
			System.out.println(""+num);
		}
		
	}

}
