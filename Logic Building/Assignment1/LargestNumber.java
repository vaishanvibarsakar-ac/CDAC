import java.util.Scanner;

class LargestNumber{

public static void main(String[] args) {
 Scanner sc = new Scanner(System.in);

System.out.println("Enter The First Number:");
int a = sc.nextInt();

System.out.println("Enter The Second Number:");
int b = sc.nextInt();


System.out.println("Enter The Third Number:");
int c = sc.nextInt();

if (a>=b && a>=c){
System.out.println("a is Largest number");
}
else if (b>=a && b>=c){
System.out.println("b is Largest number");
}
else{
System.out.println("c is Largest number");
}

}

}