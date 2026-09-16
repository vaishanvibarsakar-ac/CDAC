
public class StringCompare {

	public static void main(String[] args) {
		
		String str1 = "This is Exercise 1";
		String str2 = "This is Exercise 2";
		
		int result = str1.compareTo(str2);
		
		// unicode value for the 1 and 2 are 49 and 50 so 49-50= -1
		
		if(result == 0) {
			System.out.println(" "+ str1 +" " + "is equal to" + " " + str2 + " ");
		}
		else if (result < 0) {
			System.out.println(" "+ str1 +" " + "is less than " + " " + str2 + " ");
		}
		else {
			System.out.println(" "+ str1 +" " + "is Greater than" + " " + str2 + " ");
		}
		
	}

}
