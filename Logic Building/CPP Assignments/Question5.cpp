/*
 * Question5.cpp
 *
 *  Created on: 28-Aug-2026
 *      Author: user
 */
#include <iostream>
using namespace std;


void resetSensorPairV1(int reading1, int reading2) {
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}


void resetSensorPairV2(int& reading1, int& reading2) {
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}


void resetSensorPairV3(int* reading1, int* reading2) {
    int temp = *reading1;
    *reading1 = *reading2;
    *reading2 = temp;
}

int main5() {
    int sensorA = 10, sensorB = 20;

    cout << "--- Demonstrating resetSensorPairV1 (Call by Value) ---\n";
    cout << "Before: A=" << sensorA << ", B=" << sensorB << endl;
    resetSensorPairV1(sensorA, sensorB);
    cout << "After:  A=" << sensorA << ", B=" << sensorB << endl;



    cout << "\n--- Demonstrating resetSensorPairV2 (Call by Reference) ---\n";
    cout << "Before: A=" << sensorA << ", B=" << sensorB << endl;
    resetSensorPairV2(sensorA, sensorB);
    cout << "After:  A=" << sensorA << ", B=" << sensorB << endl;

    cout << "\n--- Demonstrating resetSensorPairV3 (Call by Pointer) ---\n";
    cout << "Before: A=" << sensorA << ", B=" << sensorB << endl;
    resetSensorPairV3(&sensorA, &sensorB);
    cout << "After:  A=" << sensorA << ", B=" << sensorB << endl;

    return 0;
}
