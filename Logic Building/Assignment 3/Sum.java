import java.util.Scanner;


class Sum{

static int sumOfTwoNumbers(int a,int b){

return a + b;
}


public static void main (String args[]){

Scanner sc = new Scanner(System.in);

System.out.println("Enter the First Number:");
int num1 =sc.nextInt();

System.out.println("Enter the Second Number:");
int num2 =sc.nextInt();


int sum = sumOfTwoNumbers(num1 , num2);

System.out.println("sum: " +sum);


}
}