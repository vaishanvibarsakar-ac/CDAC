//============================================================================
// Name        : Sensor.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main2() {
    int n;
    cout << "Enter number of readings : ";
    cin >> n;

    double readings[100];
    int skipped = 0;


    for (int i = 0; i < n; i++) {
        cin >> readings[i];
    }

    cout << "Readings entered : " << n << endl;
    cout << "Valid readings   : ";

    double minVal = 1e9, maxVal = -1e9, sum = 0;
    int normal = 0, warning = 0, critical = 0, shutdown = 0;
    bool foundCritical = false;

    for (int i = 0; i < n; i++) {
        double temp = readings[i];


        if (temp < 0) {
            skipped++;
            continue;
        }


        cout << fixed << setprecision(1) << temp << " ";  // it showing the 1 number after the ( . )
                                                     // without fixed we can say that after( . )there is only one digit will print

        if (!foundCritical && temp >= 45) {
            cout << endl << "First CRITICAL   : Index " << i
                 << " → " << temp << "°C" << endl;
            foundCritical = true;
        }


        if (temp < minVal)
        minVal = temp;

        if (temp > maxVal)
        	maxVal = temp;

        sum = sum + temp;


        if (temp <= 29) {
        	normal++;
        }else if (temp <= 44){
        	warning++;
        }else if (temp <= 59){
        			critical++;
        }else {
        	shutdown++;
        }


    cout << endl;
    cout << "Skipped (errors) : " << skipped << endl;

    double avg = sum / (n - skipped);
    cout << endl;
    cout << "Min : " << minVal << "°C   "
         << "Max : " << maxVal << "°C   "
         << "Avg : " << fixed << setprecision(2) << avg << "°C" << endl;

    cout << endl;
    cout << "Normal:" << normal
         << "  Warning:" << warning
         << "  Critical:" << critical
         << "  Shutdown:" << shutdown << endl;
    }

    return 0;
}





