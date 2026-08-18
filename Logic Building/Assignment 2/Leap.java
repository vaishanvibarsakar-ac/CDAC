class Leap{
public static void main (String args[]){

int year =1900 ;


if( year % 4 == 0 &&  year % 100 != 0) {

System.out.println("Year is the leap year");

}

else if(year % 400 == 0){
System.out.println("Year is the leap year");
}
else{

System.out.println("Not a leap year");
}


}
}