import java.util.Scanner;

class AreaRectangle{

public static void main(String[] args) {
 Scanner sc = new Scanner(System.in);

System.out.println("Enter Length :");
int Length= sc.nextInt();

System.out.println("Enter width :");
int width = sc.nextInt();


 int area = Length * width ;
 System.out.println("Area of Rectangle  = " + area);
    }
}