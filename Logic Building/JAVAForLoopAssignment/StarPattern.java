
public class StarPattern {

	
		
		// 4. Star pattern increasing
	    void starPatternIncreasing() {
	        for (int i = 1; i <= 5; i++) {
	            for (int j = 1; j <= i; j++) {
	                System.out.print("*");
	            }
	            System.out.println();
	        }
	    }

	    // 5. Star pattern decreasing
	    void starPatternDecreasing() {
	        for (int i = 5; i >= 1; i--) {
	            for (int j = 1; j <= i; j++) {
	                System.out.print("*");
	            }
	            System.out.println();
	        }
	    }

	    // 6. Number triangle
	    void numberTriangle() {
	        int num = 1;
	        for (int i = 1; i <= 4; i++) {
	            for (int j = 1; j <= i; j++) {
	                System.out.print(num + " ");
	                num++;
	            }
	            System.out.println();
	        }
	    }

	    // 7. Increasing number pattern
	    void increasingNumberPattern() {
	        for (int i = 1; i <= 6; i++) {
	            for (int j = 1; j <= i; j++) {
	                System.out.print(j + " ");
	            }
	            System.out.println();
	        }
	    }

	    // 8. Decreasing number pattern
	    void decreasingNumberPattern() {
	        for (int i = 6; i >= 1; i--) {
	            for (int j = 1; j <= i; j++) {
	                System.out.print(j + " ");
	            }
	            System.out.println();
	       
	        }
	    }
}



