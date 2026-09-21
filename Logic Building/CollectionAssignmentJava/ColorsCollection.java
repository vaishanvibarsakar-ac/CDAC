package vaishnavi.org;

import java.util.ArrayList;
import java.util.Collections;
import java.util.TreeSet;

import java.util.NavigableSet;

public class ColorsCollection {

	public static void main(String[] args) {
		ArrayList<String> Color = new ArrayList();
		
		Color.add("Red");
		Color.add("Black");
		Color.add("Blue");
		Color.add("Yellow");
		Color.add("Green");
		Color.add("Brown");
		Color.add("White");
		
		System.out.println("List of the Colors is :"+Color); // Taking and array list adding colors
		
		Color.add(0, "Silver");   // Adding the element at 1st index
		
		System.out.println("List of the Colors is :"+Color);
		  
		String Colors = Color.get(3); // Retriving the element at index 3 
		System.out.println("Element at the index 3 is:"+Colors);
		
		String Update = Color.set(4, "Pink");
		System.out.println("Updated Element at indes 4 is:"+Update);
		System.out.println("List of the Colors is :"+Color); 
		
		String Remove = Color.remove(2);
		System.out.println(" Removed  Element  is:"+Remove);
		System.out.println("After removing the 3rd element List of the Colors is :"+Color);
		
		 String searchColor = "Green";

	        if (Color.contains(searchColor)) {
	            System.out.println(searchColor + " is present in the List");
	        } else {
	            System.out.println(searchColor + " is not present in the Listc");
	        }
		
	        System.out.println("-----------------------------------------------------------");  
	        //Sort
	        System.out.println("Before Sorting :"+Color);
	        
	        Collections.sort(Color);
	        
	        System.out.println("After Sorting :"+Color);
	        
	        //Copy
	        
	        ArrayList<String> newColor = new ArrayList<>();
	        
	        for(int Tmp = 0 ; Tmp < newColor.size() ; Tmp ++) {
	        	newColor.add("");
	        	
	        }
	        
	        Collections.copy(newColor, Color);
	        
	        System.out.println("Orignal ArrayList:"+Color);
	        
	        System.out.println("Copy ArrayList:"+newColor);
	        System.out.println("-----------------------------------------------------------"); 
	        // Shuffle
	        
	        System.out.println("Bafore Shuffle ArrayList:"+Color);
	        
	        Collections.shuffle(Color);
	        
	        System.out.println("After Shuffle ArrayList:"+Color);
	        System.out.println("-----------------------------------------------------------");   
	        
	        //Reverse Elements
	        
	        System.out.println("Before Reverse ArrayList:"+Color);
	        
	        Collections.reverse(Color);
	        
	        System.out.println("After Reverse ArrayList:"+Color);

	     
	        
	       
	      

	}

}
