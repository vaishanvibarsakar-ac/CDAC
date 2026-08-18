class Average{


public static void main(String args[]){

int math = 80;
int sci= 85;
int history =90;

int aver = (math+sci+history)/3;

System.out.println("average is:" +aver);

if (aver >=90){
System.out.println("Grade A");
}


else if(aver > 70 && aver < 89){
System.out.println("Grade B");
}

else if(aver > 50 && aver < 69)
{
System.out.println("Grade c");
}

else if(aver > 30 && aver < 49)
{
System.out.println("Grade D");
}

else if(aver <30)
{
System.out.println("Fail");
}
else
{
System.out.println("No Any Grade");
}
}

}
