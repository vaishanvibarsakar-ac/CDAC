
public class RplaceString {

	public static void main(String[] args) {
		
		String str ="The Quick brown fox jumps over the lazy dog.";
		
		System.out.println("Orignal Steing" + str);
		
		String newString = str.replaceAll("fox", "cat");
		
		System.out.println("New String" + newString);
		
	}

}
