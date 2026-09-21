package vaishnavi.org;

import java.util.TreeSet;

public class Treeset {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		  TreeSet<String> Colour = new TreeSet<>();
	        
	        Colour.add("Red");
	        Colour.add("Blue");
	        Colour.add("Green");
	        Colour.add("Yellow");
	        Colour.add("Pink");
	        
	        System.out.println("TreeSet:"+Colour);
	        
	        
	        // Reverse 
	        System.out.println("Orignal TreeSet:"+Colour);
	        
	        TreeSet<String> reverseColour = (TreeSet<String>)Colour.descendingSet();
	        
	        System.out.println("After TreeSet:"+reverseColour);
	        
	        // Get First And Last Element
	        
	        
	        System.out.println("TreeSet:"+Colour);
	        
	        System.out.println("First Element of TreeSet:"+Colour.first());
	        
	        System.out.println("Last Element of TreeSet:"+Colour.last());

	        
	        
	        // Greater than or equal to
	        
	        TreeSet<Integer> Number = new TreeSet<>();
	        
	        Number.add(10);
	        Number.add(60);
	        Number.add(40);
	        Number.add(30);
	        Number.add(100);
	        
	        System.out.println("TreeSet:"+Number);
	        
	        int givenNumber = 25;
	        
	        Integer result = Number.ceiling(givenNumber);
	        
	        System.out.println("Given Number:"+givenNumber);
	        
	        System.out.println("Element Grater tha or equal to "+givenNumber+":"+result);


	}

}
