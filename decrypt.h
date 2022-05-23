//
// Created by Adrian Mysak on 20.05.22.
//

#ifndef RSA_DECRYPT_H
#define RSA_DECRYPT_H

#include <fstream>
#include <string>
#include "bigint.h"
#include <sstream>

#include "getblocks.h"

using namespace std;

string decrypt(string message, string pub, string key) {
    int d;
    int N;
    int N_check;

    vector<int> tmp;

    tmp = segmentation(pub);
    if (tmp.size() != 2) {
        cout << "\033[1;31mThis is not a valid public key!\033[0m";
        return "";
    }
    N_check = tmp[1];

    tmp = segmentation(key);
    if (tmp.size() != 2) {
        cout << "\033[1;31mThis is not a valid private key!\033[0m";
        return "";
    }
    d = tmp[0];
    N = tmp[1];

    if (N != N_check) {
        cout << "\033[1;31mThis is not a pair of keys!\033[0m";
        return "";
    }

    tmp = segmentation(message);
    if (tmp.empty()) {

    }
}

#endif //RSA_DECRYPT_H