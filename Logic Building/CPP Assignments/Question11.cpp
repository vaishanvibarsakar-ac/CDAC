/*
 * Question11.cpp
 *
 *  Created on: 29-Aug-2026
 *      Author: user
 */

#include <iostream>
using namespace std;

struct Layout1 {
    char c1;
    int i;
    char c2;
};

struct Layout2 {
    int i;
    char c1;
    char c2;
};

int main11() {
    cout << "Size of Layout1 = " << sizeof(Layout1) << " bytes" << endl;
    cout << "Size of Layout2 = " << sizeof(Layout2) << " bytes" << endl;

    /*
    📌 Explanation:

    1. Why sizes differ:
       - In Layout1: `char c1` (1 byte) is followed by `int i` (4 bytes).
         The compiler inserts 3 bytes of padding after c1 to align `int` on a 4-byte boundary.
         Then `char c2` (1 byte) comes after `int`, but again padding is added
         to make the total size a multiple of 4. Result: 12 bytes.
       - In Layout2: `int i` (4 bytes) comes first, aligned naturally.
         Then `char c1` and `char c2` (2 bytes total). Padding is added to
         make the struct size a multiple of 4. Result: 8 bytes.

    2. What padding is:
       - Padding is extra unused memory inserted by the compiler
         to ensure proper alignment of data members for efficient access.

    3. Why member order matters:
       - In systems programming (network packet headers, hardware register maps),
         struct layout must match exact byte layouts expected by hardware or protocols.
         Wrong ordering can waste memory or break compatibility.
    */

    return 0;
}



