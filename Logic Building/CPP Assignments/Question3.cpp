/*
 * Question3.cpp
 *
 *  Created on: 28-Aug-2026
 *      Author: user
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main3() {
    const int FLOORS = 3;
    const int ROOMS = 3;
    const int WARNING = 30;

    int temps[FLOORS][ROOMS];


    cout << "Enter temperatures for each floor and room:\n";
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            cout << "Floor " << i+1 << ", Room " << j+1 << ": ";
            cin >> temps[i][j];
        }
    }

    cout << "\n--- Building Temperature Report ---\n";


    cout << setw(10) << "Room1" << setw(10) << "Room2" << setw(10) << "Room3" << endl;
    for (int i = 0; i < FLOORS; i++) {
        cout << "Floor " << i+1 << ": ";
        for (int j = 0; j < ROOMS; j++) {
            cout << setw(8) << temps[i][j];
        }
        cout << endl;
    }


    int maxTemp = temps[0][0];
    int hotFloor = 1, hotRoom = 1;
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            if (temps[i][j] > maxTemp) {
                maxTemp = temps[i][j];
                hotFloor = i+1;
                hotRoom = j+1;
            }
        }
    }
    cout << "\nHottest room: Floor " << hotFloor << ", Room " << hotRoom
         << " (" << maxTemp << "°C)\n";


    double maxAvg = 0;
    int avgFloor = 1;
    for (int i = 0; i < FLOORS; i++) {
        double sum = 0;
        for (int j = 0; j < ROOMS; j++) {
            sum += temps[i][j];
        }
        double avg = sum / ROOMS;
        if (avg > maxAvg) {
            maxAvg = avg;
            avgFloor = i+1;
        }
    }
    cout << "Floor with highest average: Floor " << avgFloor
         << " (" << fixed << setprecision(2) << maxAvg << "°C)\n";

    int warningCount = 0;
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            if (temps[i][j] >= WARNING) {
                warningCount++;
            }
        }
    }
    cout << "Rooms at/above WARNING threshold (" << WARNING << "°C): "
         << warningCount << endl;

    return 0;
}



