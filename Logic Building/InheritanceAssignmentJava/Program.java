
public class Program {

	public static void main(String[] args) {
		
		// Question 1
	
        Parent p = new Parent();
        
        Child c = new Child();
        
        p.parentMethod();
        c.childMethod();
        c.parentMethod();
        
        
        
        //Question2 
        
       
        PrimeMember pm = new PrimeMember();

       
        System.out.print("Enter Name: ");
        pm.setName(ConsoleInput.getString());

        System.out.print("Enter Age: ");
        pm.setAge(ConsoleInput.getInt());

        System.out.print("Enter Phone Number: ");
        pm.setPhoneNumber(ConsoleInput.getString());

        System.out.print("Enter Address: ");
        pm.setAddress(ConsoleInput.getString());

        System.out.print("Enter Salary: ");
        pm.setSalary(ConsoleInput.getFloat());

        System.out.print("Enter Joining Year: ");
        pm.setJoiningYear(ConsoleInput.getInt());

        System.out.print("Enter Joining Fees: ");
        pm.setJoiningFees(ConsoleInput.getFloat());

        System.out.print("Is Active (true/false): ");
        pm.setIsActive(Boolean.parseBoolean(ConsoleInput.getString()));

        // Display details
        System.out.println("\n----- Member Details -----");

        pm.display();

        // Print salary
        System.out.println("\n----- Salary -----");

        pm.printSalary();
        
        
        
        
        // Question 3
        
       
        System.out.print("Enter length of Rectangle: ");
        float length = ConsoleInput.getFloat();

        System.out.print("Enter breadth of Rectangle: ");
        float breadth = ConsoleInput.getFloat();

        
        Rectangle r = new Rectangle(length, breadth);

        System.out.println("\n--- Rectangle ---");

        r.area();
        r.perimeter();


        System.out.print("\nEnter side of Square: ");
        float side = ConsoleInput.getFloat();

      
        Square s = new Square(side);

        System.out.println("\n--- Square ---");

        s.area();
        s.perimeter();
        
        
        
        // Question 4
        
        
        Square1 sq = new Square1();
        
        sq.displayShape();

        sq.displayRectangle();

        sq.displaySquare();

	}

}
