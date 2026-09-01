/*
 * Question3.cpp
 *
 *  Created on: 01-Sept-2026
 *      Author: user
 */

#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

public:
    //Constructor 1 - Default : id =0 , name -"Unknown", age = 0 , ward - "General", bloodgroup ="o+"
    Patient() : patientId(0), name("Unknown"), age(0), ward("General"), bloodGroup("O+") {
        cout << "[Constructor] Default admission: " << name << endl;
    }

    // Constructor 2 — Emergency Admission : only id and name known
    Patient(int id, const string& pname)
        : patientId(id), name(pname), age(), ward("Emergency"), bloodGroup("O+") {
        cout << "[Constructor] Emergency admission: " << name << endl;
    }

    // Constructor 3 — Full admission details
    Patient(int id, const string& pname, int a, const string& w, const string& bg)
        : patientId(id), name(pname), age(a), ward(w), bloodGroup(bg) {
        cout << "[Constructor] Full admission: " << name << endl;
    }


    ~Patient() {
        cout << "[Destructor] Patient " << name << " discharged." << endl;
    }

    void displayRecord() const {
        cout << "ID: " << patientId<< endl ;
        cout<< " Name: " << name << endl ;
        cout<< " Age: " << age << endl ;
        cout << " Ward: " << ward<< endl;
        cout << " Blood Group: " << bloodGroup << endl;
    }

    void transferWard(const string& newWard) {
        ward = newWard;
        cout << "Patient " << name << " transferred to " << ward << " ward." << endl;
    }
};

int main3() {

    Patient p1;
    Patient p2(101, "Raj Patel");
    Patient p3(102, "merra joshi", 30, "ICU", "B+");

    cout << "\n--- Patient Records ---\n";
    p1.displayRecord();
    p2.displayRecord();
    p3.displayRecord();


    cout << "\n--- Dynamic Patients ---\n";
    Patient* arr = new Patient[4];

    for (int i = 0; i < 4; i++) {
        arr[i].displayRecord();
    }

    arr[2].transferWard("Surgery");
    cout << "ward treansfer";

    delete[] arr;
    cout << "destructor get call";
    return 0;
}



