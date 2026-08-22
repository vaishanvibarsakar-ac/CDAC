import java.util.Scanner;

class Palindrome {
public static void main(String args[]){

Scanner sc = new Scanner (System.in);

System.out.println("Enter a String:");
String str =sc.nextLine();

String reverse = "";

for(int i = str.length()-1 ;i>= 0;i--){
reverse = reverse + str.charAt(i);
}

if(str.equals(reverse)){
System.out.println("The String is a palindrome .");

}else{
System.out.println("The String is not a palindrome .");

}
}

}
