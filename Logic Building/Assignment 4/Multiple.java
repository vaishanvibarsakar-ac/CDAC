import java.util.Scanner;

class Multiple{
public static void main(String args[]){
 Scanner sc = new Scanner(System.in);

System.out.println("Enter the N:");
int n = sc.nextInt();

for(int i=1 ; i<=n ;i++){   /*also i used for(int i= 3 ;i<=n ;i=i+3)then if condition i have to skip */

if(i % 3 == 0){
System.out.println(i);
}
}

}
}