/*
 * question9.cpp
 *
 *  Created on: 29-Aug-2026
 *      Author: user
 */

#include <iostream>
#include <cmath>
using namespace std;


inline double distanceBetween(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

inline double toRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}

inline double clamp(double value, double minVal, double maxVal) {
    if (value < minVal) return minVal;
    if (value > maxVal) return maxVal;
    return value;
}

inline bool isInSafeZone(double x, double y, double cx, double cy, double radius) {
    return distanceBetween(x, y, cx, cy) <= radius;
}

int main9() {

    double homeX = 0.0, homeY = 0.0;
    double safeRadius = 50.0;


    double waypoints[3][2] = {
        {10.0, 20.0},
        {40.0, 30.0},
        {60.0, 0.0}
    };

    for (int i = 0; i < 3; i++) {
        double x = waypoints[i][0];
        double y = waypoints[i][1];
        double dist = distanceBetween(homeX, homeY, x, y);
        bool safe = isInSafeZone(x, y, homeX, homeY, safeRadius);

        cout << "Waypoint " << i + 1 << " (" << x << ", " << y << "): "
             << "Distance from home = " << dist
             << ", Inside safe zone? " << (safe ? "Yes" : "No") << endl;
    }

    return 0;
}



