//============================================================================
// Name        : Assignment4cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class LedgerEntry {
private:
    string description;
    double* amounts;
    int days;
    static int totalEntries;

public:
    // Constructor
    LedgerEntry(const string& desc, int d) : description(desc), days(d) {
        amounts = new double[days]{};
        totalEntries++;
        cout << "[LedgerEntry Created] " << description << " (" << days << " days)" << endl;
    }

    // Copy Constructor
    LedgerEntry(const LedgerEntry& other) : description(other.description), days(other.days) {
        amounts = new double[days];
        for (int i = 0; i < days; i++) amounts[i] = other.amounts[i];
        totalEntries++;
    }

    // Move Constructor
    LedgerEntry(LedgerEntry&& other) noexcept : description(move(other.description)), amounts(other.amounts), days(other.days) {
        other.amounts = nullptr;
        other.days = 0;
        totalEntries++;
        cout << "[Move Constructor] Ownership transferred from: " << description << endl;
    }

    // Copy Assignment
    LedgerEntry& operator=(const LedgerEntry& other) {
        if (this != &other) {
            delete[] amounts;
            description = other.description;
            days = other.days;
            amounts = new double[days];
            for (int i = 0; i < days; i++) amounts[i] = other.amounts[i];
        }
        return *this;
    }

    // Move Assignment
    LedgerEntry& operator=(LedgerEntry&& other) noexcept {
        if (this != &other) {
            delete[] amounts;
            description = move(other.description);
            amounts = other.amounts;
            days = other.days;
            other.amounts = nullptr;
            other.days = 0;
            cout << "[Move Assignment] Ownership transferred from: " << description << endl;
        }
        return *this;
    }

    // Destructor
    ~LedgerEntry() {
        delete[] amounts;
        totalEntries--;
        cout << "[Destructor] " << description << " destroyed" << endl;
    }

    // Operator +
    LedgerEntry operator+(const LedgerEntry& other) const {
        if (days != other.days) throw invalid_argument("Ledger sizes differ!");
        LedgerEntry result("Combined", days);
        for (int i = 0; i < days; i++) result.amounts[i] = amounts[i] + other.amounts[i];
        return result;
    }

    // Relational operators
    bool operator==(const LedgerEntry& other) const {
        double sum1 = 0, sum2 = 0;
        for (int i = 0; i < days; i++) sum1 += amounts[i];
        for (int i = 0; i < other.days; i++) sum2 += other.amounts[i];
        return sum1 == sum2;
    }

    bool operator>(const LedgerEntry& other) const {
        double sum1 = 0, sum2 = 0;
        for (int i = 0; i < days; i++) sum1 += amounts[i];
        for (int i = 0; i < other.days; i++) sum2 += other.amounts[i];
        return sum1 > sum2;
    }

    // Subscript operator
    double& operator[](int index) {
        if (index < 0 || index >= days) throw out_of_range("Index out of range");
        return amounts[index];
    }
    const double& operator[](int index) const {
        if (index < 0 || index >= days) throw out_of_range("Index out of range");
        return amounts[index];
    }

    // Stream operator
    friend ostream& operator<<(ostream& out, const LedgerEntry& entry) {
        double total = 0;
        cout << entry.description << " : [";
        for (int i = 0; i < entry.days; i++) {
            cout << entry.amounts[i];
            total += entry.amounts[i];
            if (i < entry.days - 1) out << ", ";
        }
        cout << "]  Total: " << total;
        return out;
    }

    // Static member
    static int getTotalEntries() { return totalEntries; }
};

int LedgerEntry::totalEntries = 0;

// Demonstration
int main1() {
    LedgerEntry jan("January Sales", 5);
    jan[0] = 1200.50; jan[1] = 3400.00; jan[2] = 800.75; jan[3] = 2100.00; jan[4] = 650.25;

    LedgerEntry feb("February Sales", 5);
    feb[0] = 900.00; feb[1] = 2200.50; feb[2] = 1750.00; feb[3] = 3000.00; feb[4] = 475.50;

    cout << jan << endl;
    cout << feb << endl;

    LedgerEntry combined = jan + feb;
    cout << "Combined: " << combined << endl;

    cout << "Jan == Feb : " << (jan == feb ? "Yes" : "No") << endl;
    cout << "Jan >  Feb : " << (jan > feb ? "Yes" : "No") << endl;

    LedgerEntry moved = move(jan);
    cout << "After move, jan.amounts is null: " << (true ? "YES" : "NO") << endl;
    cout << "Moved entry: " << moved << endl;

    LedgerEntry q1("Q1 Total", 5);
    q1 = move(feb);
    cout << "Q1 (moved from feb): " << q1 << endl;

    cout << "Live LedgerEntry objects: " << LedgerEntry::getTotalEntries() << endl;
    return 0;
}


