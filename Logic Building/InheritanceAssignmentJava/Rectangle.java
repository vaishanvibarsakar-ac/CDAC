
public class Rectangle {

	

	    private float length;
	    private float breadth;

	   
	    public Rectangle(float length, float breadth) {

	        this.length = length;
	        this.breadth = breadth;
	    }

	    
	    public void area() {

	        float result = length * breadth;

	        System.out.println("Area of Rectangle: " + result);
	    }

	   
	    public void perimeter() {

	        float result = 2 * (length + breadth);

	        System.out.println("Perimeter of Rectangle: " + result);
	    }
	}

	class Square extends Rectangle {

	    public Square(float side) {
	    	
	        super(side, side);
	    }
	}