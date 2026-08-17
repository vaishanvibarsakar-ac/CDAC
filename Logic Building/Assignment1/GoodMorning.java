import java.util.Scanner;

class GoodMorning{
public static void main(String args[]){

Scanner sc= new Scanner(System.in);
System.out.print("Enter a time : ");
int time = sc.nextInt();

System.out.print("Enter a period(AM/PM): ");
String period = sc.next();

if(period.equals("AM")&&  time >=5 && time<12)
System.out.print("Good Morning");

else
System.out.print("Not Morning");


}}