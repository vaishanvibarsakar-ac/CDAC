
public class ReverseString {

	public static void main(String[] args) {

		String str = "The quick brown fox jumps";
		
		System.out.println("The given string is: " + str);
		
		StringBuffer buffer = new StringBuffer(str);
		
		buffer.reverse();
		
		System.out.println("The string in reverse order is:" + buffer);
		
	
	}
}