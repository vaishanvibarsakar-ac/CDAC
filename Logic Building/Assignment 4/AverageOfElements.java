import java.util.Scanner;



class AverageOfElements{
public static void main(String args[]){

Scanner sc = new Scanner (System.in);


System.out.println("Enter the size of the array:");
int size = sc.nextInt();

int Elements[]=new int [size];


System.out.println("Enter"+size+ "Elements");

for(int i =0;i<Elements.length;i++){
Elements[i]=sc.nextInt();

}
int sum =0;

for(int num :Elements){
sum=sum+num;

}

double average = (double)sum / Elements.length;

System.out.println("sum = " +sum);
System.out.println("Average = " +average);


}
}
