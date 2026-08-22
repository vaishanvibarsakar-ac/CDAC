import java.util.Scanner;

class StringArray{
public static void main (String args[]){

Scanner sc = new Scanner(System.in);

System.out.println("Enter the size of the array");
int size = sc.nextInt();

String Name []= new String[size];
sc.nextLine();

System.out.println("Enter "+size+"Name:");

for(int i =0;i< Name.length;i++){
Name[i] = sc.nextLine();

}

System.out.println("Names Store in the array:");
for(String name : Name){

System.out.println(name);
}
}

}