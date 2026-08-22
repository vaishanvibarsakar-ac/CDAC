import java.util.Scanner;
import java.util.Arrays;


class SortArray{
public static void main(String args[]){

Scanner sc = new Scanner (System.in);


System.out.println("Enter the size of the array:");
int size = sc.nextInt();

int Elements[]=new int [size];


System.out.println("Enter"+size+ "Elements");

for(int i =0;i<Elements.length;i++){
Elements[i]=sc.nextInt();

}

 Arrays.sort(Elements);

System.out.println("Sorted array :");

for(int num :Elements){
System.out.println(num);

}

}


}