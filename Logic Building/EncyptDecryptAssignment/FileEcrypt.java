
import java.io.*;

public class FileEcrypt {
	
	public static void createFile() {
	

        FileOutputStream file = null;
        DataOutputStream data=  null;

       

       
		try {
			file = new FileOutputStream("D:\\CDAC\\CdacKharghar.txt");

			data = new DataOutputStream(file);

			System.out.println("File Created Sucessfully");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
	
	finally {
		try {
			data.close();
			file.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	}
	
	
	
	public static String readfile() {
	FileInputStream file = null;
	InputStreamReader Input = null;
	BufferedReader buffer = null;
	
	String data = "";
	try {
	file= new FileInputStream("D:\\CDAC\\CdacKharghar.txt");
	
	Input = new InputStreamReader(file);
	
	buffer = new BufferedReader(Input);
	
	String line ;
	
	while ((line = buffer.readLine()) != null) {
		data = data + line + "";
	}
	System.out.println("File read Sucessfully");
	
	}
	catch(IOException Exp) {
		System.out.println("Error While reading file"+Exp);
	
	}finally {
		try {
			buffer.close();
			Input.close();
			file.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	return data;

}
	
public static void Encrypt() {
	
	FileInputStream fileinput = null; 
	FileOutputStream fileoutput = null;
	
	 
		
		try {
			fileinput = new FileInputStream("D:\\CDAC\\CdacKharghar.txt");
			
			fileoutput = new FileOutputStream("encrypted.txt");
			
			int ch ;
			
			while((ch = fileinput.read()) != -1) {
				int encryptedchar = ch+3;
				fileoutput.write(encryptedchar);
				
			}
			System.out.println("File encrypted successfully."); 
			System.out.println("Encrypted data stored in encrypted.txt");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally {
			
			try {
				fileinput.close();
				fileoutput.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	
	
}
	

public static void decryptFile() {
	try {
		FileInputStream file = null; 
		FileOutputStream fileoutput = null;
		
		file= new FileInputStream("encrypted.txt");
		
		fileoutput = new FileOutputStream("decrypted.txt");
		
		int ch;
		
		while((ch = file.read()) != -1) {
			int decryptedChar = ch - 3;
			
			fileoutput.write(decryptedChar);
		}
		
		System.out.println("File decrypted successfully."); 
		System.out.println("Decrypted data stored in decrypted.txt");
	} catch (FileNotFoundException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}	
			
}
	




	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		try {
			while (true) {
				System.out.println("\n========== FILE MENU ==========");
				System.out.println("1. Create File"); 
				System.out.println("2. Read File"); 
				System.out.println("3. Encrypt File"); 
				System.out.println("4. Decrypt File"); 
				System.out.println("5. Exit");
				
				System.out.print("Enter your choice: ");
				String choice = br.readLine();
				String result = switch (choice) {
				
				case "1" -> { 
					createFile();
				yield "CREATE";
				}
				
				case "2" -> { 
					String data = readfile(); 
					System.out.println("D:\\CDAC\\CdacKharghar.txt"); 
					System.out.println(data);
					
					yield "READ";
				}
				
				case "3" -> {
					Encrypt(); 
					yield "ENCRYPT";
					}
				
				case "4" -> { 
					decryptFile(); 
					yield "DECRYPT"; }
				
				
				case "5" -> { 
					System.out.println("Program terminated.");
					yield "EXIT"; }
				
				
				default -> { 
					System.out.println("Invalid choice.");
					yield "INVALID"; }
				};
				
				if (result.equals("EXIT"))
				{ 
					break; 
				} 
				}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
			
			
			
			
		}
	}

