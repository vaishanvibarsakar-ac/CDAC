import java.util.Scanner;

class MenuDrive{

public static void main(String args[]){
	Scanner sc = new Scanner(System.in);


	System.out.println("--------Menu------");
	System.out.println("Grade Evaluation System");
	System.out.println("Leap Year Check");
	System.out.println("Day of the Week");
	System.out.println("Identity Default Values of Variables");
	System.out.println("Exit");

        System.out.println("Enter your choice ");
	int choice = sc.nextInt();

	switch(choice){

case 1:


System.out.println("Enter the marks :");
int marks = sc.nextInt();
if(marks>=90){
System.out.println("Grade A");
}else if (marks>=75){
System.out.println("Grade B");

}else if (marks>=60){
System.out.println("Grade C");

}else if (marks>=40){
System.out.println("Grade D");

}else {
System.out.println("Fail");
}

break;



case 2:

System.out.println("Enter Year:");
int year = sc.nextInt();

if(year % 400 == 0|| year % 100!=0 && year % 4 ==0){

System.out.println("This is the leap year");
}
else{
System.out.println("Not Leap year ");

}


break;



case 3:

System.out.println("Enter a day From(1to 7):");
int day = sc.nextInt();


switch(day){
case 1:
System.out.println("Monday");
break;

case 2:
System.out.println("Tuesday");
break;

case 3:
System.out.println("Wednesday");
break;

case 4:
System.out.println("Thrusday");
break;

case 5:
System.out.println("Friday");
break;

case 6:
System.out.println("Saturday");
break;

case 7:
System.out.println("Sunday");
break;



default:
System.out.println("Invalid choice");

}
break;





case 4:
int a = 20;
char b = 'v';
double c = 123.4567;
float d = 12.34F;

System.out.println("default value of a :"+a);
System.out.println("default value of b :"+b);
System.out.println("default value of c :"+c);
System.out.println("default value of d :"+d);

break;

case 5:
System.out.println("Exit!!!!!!");
break;


default:
System.out.println("Invalid choice ");
}

}
}



