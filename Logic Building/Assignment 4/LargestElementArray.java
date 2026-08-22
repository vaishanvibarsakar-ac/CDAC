import java.util.Scanner;
import java.util.Arrays;


class LargestElementArray{
public static void main(String args[]){

Scanner sc = new Scanner (System.in);


System.out.println("Enter the size of the array:");
int size = sc.nextInt();

int Elements[]=new int [size];



System.out.print("Enter"+size+ "Elements");

for(int i =0;i<Elements.length;i++){
Elements[i]=sc.nextInt();

}


Arrays.sort(Elements);  //Inbuilt method use to sort the array

int largest = Elements[Elements.length -1];

System.out.println("Largest Number is:"+largest);

}


}