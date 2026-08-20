import java.util.Scanner;

class AgeChecker{


static void checkAgeCategoryS(int age ){


String result =(age <=18)?"Minor":(age<=60) ? "Adult" :"Senior Citizen";
System.out.println(result);

/* if (age <18){

System.out.println("Minor");

}
else if (age<60){
System.out.println("Adult");

}
else{
System.out.println("Senior Citizen");

}*/

}

public static void main(String args[]){

Scanner sc = new Scanner(System.in);

System.out.println("Enter the age :");

int age = sc.nextInt();


checkAgeCategoryS(age);

}



}
