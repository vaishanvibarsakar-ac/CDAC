class StringObject {
    public static void main(String[] args) {

String str1 = "Hello";
String str2 = "Hello";
System.out.println("str1 = " + str1);
System.out.println("str2 = " + str2);

 if (str1 == str2) {
System.out.println("Both variables point to the same object.");
  } else {
System.out.println("Both variables point to different objects.");
  }

if (str1.equals(str2)) {
System.out.println("Both strings have the same content.");
        }
   }
}