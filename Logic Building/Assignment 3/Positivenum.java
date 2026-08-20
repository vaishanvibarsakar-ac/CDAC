import java.util.Scanner;
class Positivenum{

static void askForPositiveNumbers(){

Scanner sc = new Scanner(System.in);

int num;

do {


System.out.println("Enter positive number");
num = sc.nextInt();

}
while(num<=0);

System.out.println("You entered a positive number :" +num);

}

public static void main (String args[]){

askForPositiveNumbers();
}

}