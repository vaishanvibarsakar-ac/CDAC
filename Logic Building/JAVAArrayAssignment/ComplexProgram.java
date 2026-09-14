
public class ComplexProgram {

	public static void main(String[] args) {
	      ComplexNumber[] arr = new ComplexNumber[5];

	        for (int i = 0; i < 5; i++) {

	            arr[i] = new ComplexNumber();

	            System.out.println("Enter number1 for object " + (i + 1) + ":");
	            int n1 = ConsoleInput.getInt();

	            System.out.println("Enter number2 for object " + (i + 1) + ":");
	            int n2 = ConsoleInput.getInt();

	            arr[i].setNumber1(n1);
	            arr[i].setNumber2(n2);
	        }

	        System.out.println("\nResults:");

	        for (int i = 0; i < 5; i++) {

	            int result = arr[i].computeComplexNumber();

	            System.out.println(
	                "Object " + (i + 1) +
	                " : " + arr[i].getNumber1() +
	                " * " + arr[i].getNumber2() +
	                " = " + result
	            );
	        }
	    }
	}
