import java.util.Scanner;

class SumOfArray{

public static void main(String args[]){

Scanner sc= new Scanner(System.in);

System.out.println("Enter the size of the array:");
int size = sc.nextInt();

int numbers[] = new int[size];
System.out.println("Enter "+size+"Numbers:");

for(int i =0; i<numbers.length;i++){
numbers[i] = sc.nextInt();


}
int sum =0;
for(int num :numbers){
sum = sum+num;
}
System.out.println("Sum of the all Elements = "+sum);

}


}