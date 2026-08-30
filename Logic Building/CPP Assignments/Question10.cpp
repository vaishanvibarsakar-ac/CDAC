/*
 * Question10.cpp
 *
 *  Created on: 29-Aug-2026
 *      Author: user
 */


#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    static int nextEmpId;
    static int employeeCount;

    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

public:
    // Constructor
    Employee() {
        empId = nextEmpId++;
        employeeCount++;
        isActive = true;
    }

    // Setters with validation
    void setName(const string& n) {
        if (n.empty()) cout << "Error: Name cannot be empty.\n";
        else name = n;
    }

    void setDepartment(const string& dept) {
        if (dept == "Engineering" || dept == "HR" || dept == "Finance" || dept == "Operations")
            department = dept;
        else cout << "Error: Invalid department.\n";
    }

    void setGrade(char g) {
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D')
            grade = g;
        else cout << "Error: Invalid grade.\n";
    }

    void setBasicSalary(double salary) {
        if (salary > 10000 && salary < 500000)
            basicSalary = salary;
        else cout << "Error: Salary must be between 10,000 and 5,00,000.\n";
    }

    void deactivate() { isActive = false; }

    // Getters
    int getEmpId() const { return empId; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    char getGrade() const { return grade; }
    double getBasicSalary() const { return basicSalary; }
    bool getIsActive() const { return isActive; }

    // Business logic
    double computeAllowances() const {
        switch (grade) {
            case 'A': return 0.40 * basicSalary;
            case 'B': return 0.30 * basicSalary;
            case 'C': return 0.20 * basicSalary;
            case 'D': return 0.10 * basicSalary;
            default: return 0.0;
        }
    }

    double computeGrossSalary() const {
        return basicSalary + computeAllowances();
    }

    double computeTax() const {
        double gross = computeGrossSalary();
        if (gross <= 50000) return 0.0;
        else if (gross <= 100000) return (gross - 50000) * 0.10;
        else return 5000 + (gross - 100000) * 0.20;
    }

    double computeNetSalary() const {
        return computeGrossSalary() - computeTax();
    }

    void printPayslip() const {
        cout << "\n--- Payslip ---\n";
        cout << "Employee ID: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Grade: " << grade << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Allowances: " << computeAllowances() << endl;
        cout << "Gross Salary: " << computeGrossSalary() << endl;
        cout << "Tax: " << computeTax() << endl;
        cout << "Net Salary: " << computeNetSalary() << endl;
        cout << "Active: " << (isActive ? "Yes" : "No") << endl;
    }

    static int getEmployeeCount() { return employeeCount; }

    // Input
    void acceptDetails() {
        string n, dept;
        char g;
        double sal;

        cout << "Enter name: ";
        getline(cin, n);
        setName(n);

        cout << "Enter department (Engineering/HR/Finance/Operations): ";
        getline(cin, dept);
        setDepartment(dept);

        cout << "Enter grade (A/B/C/D): ";
        cin >> g;
        setGrade(g);

        cout << "Enter basic salary: ";
        cin >> sal;
        setBasicSalary(sal);

        cin.ignore(); // clear buffer
    }
};

// Initialize static members
int Employee::nextEmpId = 1001;
int Employee::employeeCount = 0;

int main10() {
    // Create objects – one on stack, two on heap
    Employee e1;
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    cout << "\nEnter details for Employee 1:\n";
    e1.acceptDetails();

    cout << "\nEnter details for Employee 2:\n";
    e2->acceptDetails();

    cout << "\nEnter details for Employee 3:\n";
    e3->acceptDetails();

    // Uncommenting below lines will cause compiler errors (private members)
    // e1.empId = 999;
    // e1.basicSalary = -1000;

    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    // Simulate a resignation
    e3->deactivate();
    if (!e3->getIsActive())
        cout << e3->getName() << " is no longer active. Payroll skipped." << endl;

    cout << "\nTotal Employees : " << Employee::getEmployeeCount() << endl;

    delete e2;
    delete e3;

    return 0;
}


