/*
 * Question4.cpp
 *
 *  Created on: 28-Aug-2026
 *      Author: user
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main4(int argc, char* argv[]) {

    if (argc != 4) {
        cerr << "Usage: ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>\n";
        return 1;
    }

    int warn = stoi(argv[1]);
    int critical = stoi(argv[2]);
    int num_readings = stoi(argv[3]);


    if (warn >= critical) {
        cerr << "Error: warn_threshold must be less than critical_threshold.\n";
        return 1;
    }
    if (num_readings < 1 || num_readings > 500) {
        cerr << "Error: num_readings must be between 1 and 500.\n";
        return 1;
    }


    srand(time(0));


    int normalCount = 0, warnCount = 0, criticalCount = 0;

    cout << "--- Sensor Monitor Simulation ---\n";
    for (int i = 0; i < num_readings; i++) {
        int temp = rand() % 70;
        cout << "Reading " << i+1 << ": " << temp << "°C -> ";

        if (temp < warn) {
            cout << "NORMAL\n";
            normalCount++;
        } else if (temp < critical) {
            cout << "WARNING\n";
            warnCount++;
        } else {
            cout << "CRITICAL\n";
            criticalCount++;
        }
    }


    cout << "\n--- Summary ---\n";
    cout << "NORMAL: " << normalCount << endl;
    cout << "WARNING: " << warnCount << endl;
    cout << "CRITICAL: " << criticalCount << endl;

    return 0;
}
