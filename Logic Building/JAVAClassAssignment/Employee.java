
public class Employee {
	int salary;
    int hoursPerDay;

    // Method to take info
    void getInfo(int s, int h) {
        salary = s;
        hoursPerDay = h;
    }

    // Method to add $10 if salary < 500
    void addSal() {
        if (salary < 500) {
            salary += 10;
        }
    }

    // Method to add $5 if hours > 6
    void addWork() {
        if (hoursPerDay > 6) {
            salary += 5;
        }
    }

    // Method to print final salary
    void printSalary() {
        System.out.println("Final Salary: $" + salary);
    }
}