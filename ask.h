//
// Created by Adrian Mysak on 20.05.22.
//

#ifndef RSA_ASK_H
#define RSA_ASK_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string askForMethod() {
    string input;
    while (true) {
        cout << "Method: [enc/dec]: ";
        cin >> input;

        if (input == "enc" || input == "dec") {
            return input;
        }
    }
}

ifstream askForIf(string filetype) {
    string fname;
    while (true) {
        cout << filetype << " [relative]: ";
        cin >> fname;

        if (ifstream(fname)) {
            return ifstream(fname);
        } else {
            cout << "\033[1;31mNo such file!\033[0m" << endl;
        }
    }
}

string askForMessage() {
    string input;
    while (true) {
        cout << "Please enter your message: ";
        cin >> input;

        if (!input.empty()) {
            return input;
        } else {
            cout << "\033[1;31mPlease enter a message!\033[0m" << endl;
        }
    }
}

#endif //RSA_ASK_H
