//
// Created by Adrian Mysak on 17.05.22.
//

#include <iostream>
#include <vector>

#include "ask.h"
#include "decrypt.h"
#include "encrypt.h"

using namespace std;

// main function
int main(int argc, char *argv[]) {
    // variables
    string method;

    cout << "RSA Decoder and Encoder" << endl
         << "V. 1.0.0" << endl
         << "by Adrian Mysak" << endl
         << endl;

    method = askForMethod();
    if (method == "dec") {
        string message;
        string pub;
        string key;

        ifstream data_if = askForIf("Data file") >> message;
        ifstream pub_if = askForIf("Public key") >> pub;
        ifstream key_if = askForIf("Private Key") >> key;

        data_if.close();
        pub_if.close();
        key_if.close();

        string m = decrypt(message, pub, key);
        if (m.empty()) {
            return 1;
        }
        cout << endl << "Message:" << endl << m << endl;

        return 0;

    } else if (method == "enc") {
        string message = askForMessage();
        encrypt(message);

        return 0;

    } else {
        cout << "Something went wrong..." << endl;
        return 1;

    }
}