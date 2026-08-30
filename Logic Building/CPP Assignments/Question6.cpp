/*
 * Question6.cpp
 *
 *  Created on: 29-Aug-2026
 *      Author: user
 */

#include <iostream>
#include <cmath>
using namespace std;


double computeRMS(double* signal, int n) {
    double sumSq = 0.0;
    double* ptr = signal;
    for (int i = 0; i < n; i++, ptr++) {
        sumSq += (*ptr) * (*ptr);
    }
    return sqrt(sumSq / n);
}


void normalise(double* signal, int n) {
    double maxAbs = 0.0;
    double* ptr = signal;
    for (int i = 0; i < n; i++, ptr++) {
        double val = *ptr;
        double absVal = (val < 0) ? -val : val;  // manual absolute value
        if (absVal > maxAbs) maxAbs = absVal;
    }
    ptr = signal;
    for (int i = 0; i < n; i++, ptr++) {
        *ptr = *ptr / maxAbs;
    }
}


int countZeroCrossings(double* signal, int n) {
    int count = 0;
    double* ptr = signal;
    for (int i = 0; i < n - 1; i++, ptr++) {
        if ((*ptr > 0 && *(ptr + 1) < 0) || (*ptr < 0 && *(ptr + 1) > 0)) {
            count++;
        }
    }
    return count;
}


void applyGain(double* signal, int n, double gainFactor) {
    double* ptr = signal;
    for (int i = 0; i < n; i++, ptr++) {
        *ptr = (*ptr) * gainFactor;
    }
}


void printSignal(double* signal, int n) {
    double* ptr = signal;
    cout << "{ ";
    for (int i = 0; i < n; i++, ptr++) {
        cout << *ptr;
        if (i < n - 1) cout << ", ";
    }
    cout << " }" << endl;
}

int main() {
    double signal[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};
    int n = sizeof(signal) / sizeof(signal[0]);

    cout << "Original signal: ";
    printSignal(signal, n);

    cout << "RMS value: " << computeRMS(signal, n) << endl;
    cout << "Zero crossings: " << countZeroCrossings(signal, n) << endl;

    normalise(signal, n);
    cout << "After normalisation: ";
    printSignal(signal, n);

    applyGain(signal, n, 2.0);
    cout << "After applying gain (x2): ";
    printSignal(signal, n);

    return 0;
}



