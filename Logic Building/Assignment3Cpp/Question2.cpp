/*
 * Question2.cpp
 *
 *  Created on: 02-Sept-2026
 *      Author: user
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;


using Header     = pair<string, string>;
using HeaderList = vector<Header>;
using Port       = unsigned int;
using IPAddress  = string;


typedef unsigned long long RequestId;


void printHeaders(const HeaderList& headers) {
    cout << "\nHeaders:" << endl;
    for (const auto& h : headers) {
        cout << "  " << h.first << " : " << h.second << endl;
    }
}

int main2() {

    RequestId reqId = 1748293847;
    Port serverPort = 8080;

    cout << "Request ID   : " << reqId << endl;
    cout << "Server Port  : " << serverPort << endl;

    HeaderList headers =
    {
        {"Content-Type", "application/json"},
        {"Authorization", "Bearer eyJhbGci..."},
        {"Accept-Language", "en-US"}
    };

    printHeaders(headers);

    return 0;
}


