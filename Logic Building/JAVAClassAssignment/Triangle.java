
public class Triangle {

	private int side1;
	private int side2;
	private int side3;
	double semip;
	
	//constructor 
	Triangle(int aTmp , int bTmp , int cTmp){
		
		side1= aTmp ;
		side2= bTmp ;
		side3= cTmp ;
		}
	
	public int getPerimeter() {
		return  side1 + side2 + side3 ;
	}
	
	public double getarea() {
		
		  semip   = getPerimeter()/2.0;
		  
		  return Math.sqrt(semip*(semip - side1)*(semip - side2)*(semip - side3)); 
		
		
	}
	

}
