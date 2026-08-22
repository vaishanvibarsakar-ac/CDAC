import java.util.Scanner;

class EvenNumbers{
public static void main(String args[]){
 Scanner sc = new Scanner(System.in);

System.out.println("Enter the N:");
int n = sc.nextInt();
int factorial =1;
for(int i=1 ; i<=n ;i++){
 if(i % 2 ==0){

System.out.println(i);
}
}



}
}