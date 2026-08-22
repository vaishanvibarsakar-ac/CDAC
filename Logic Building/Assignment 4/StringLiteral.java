class StringLiteral {
 public static void main(String[] args) {

String str1 = "world";
String str2 = "world";
String str3 = "world";

System.out.println("Are all three literals the same object? " + (str1 == str2 && str2 == str3));
    }
}