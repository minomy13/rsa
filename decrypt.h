//
// Created by Adrian Mysak on 20.05.22.
//

#ifndef RSA_DECRYPT_H
#define RSA_DECRYPT_H

#include <fstream>
#include <string>
#include "bigint/bigint.h"
#include <sstream>

#include "getblocks.h"

using namespace std;

string decrypt(string message, string pub, string key) {
    int d;
    int N;
    int N_check;

    vector<int> tmp;
    string result;

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

    cout << "d:       " << d << endl
         << "N:       " << N << endl;

    tmp = segmentation(message);
    if (tmp.empty()) {
        cout << "\033[1;31mMessage must not be empty!\033[0m";
        return "";
    }

    for (int i = 0; i < tmp.size(); i++) {
        bigint big_c = tmp[i];
        bigint big_d = d;
        bigint big_N = N;
        int m;

        bigint m_pow = big_pow(big_c, big_d);
        bigint big_m = m_pow % big_N;

        stringstream ss;
        ss << big_m;
        const char c = ss.str()[0];
        cout << "big_m= " << big_m << " c=" << c;
        result.push_back(c);

//        ofstream buffer("buffer");
//        ifstream buffer_in("buffer");
//        buffer << big_m;
//        buffer.close();
//        buffer_in >> m;
//        buffer_in.close();
//        result.push_back((char) m);
    }

    return result;
}

#endif //RSA_DECRYPT_H
