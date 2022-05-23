//
// Created by Adrian Mysak on 21.05.22.
//

#ifndef RSA_ENCRYPT_H
#define RSA_ENCRYPT_H

#include <iostream>
#include <fstream>
#include "bigint.h"

#include "prime.h"
#include "euklid.h"
#include "getblocks.h"

using namespace std;

bool encrypt(string message) {
    // variables
    int e = 31;
    int p;
    int q;
    bigint N = 5293;
    bigint phi_N;
    bigint d = 0;

    // open files
    ofstream rsaPub("rsa.pub");
    ofstream rsaKey("rsa.key");
    ofstream dataTxt("data.txt");

    // setting random seed
    srand(time(NULL));

    int max = 200;
    bigint min_d = 1000;

    while (d < min_d) {
        // choosing e
        cout << "Choosing e" << endl;
        e = rand() % max;
        while (!prime(e)) {
            e = rand() % max;
        }

        // choosing p
        cout << "Choosing p" << endl;
        p = rand() % max;
        while (!prime(p)) {
            p = rand() % max;
        }

        // choosing q
        cout << "Choosing q" << endl;
        q = rand() % max;
        while (!prime(q)) {
            q = rand() % max;
        }

        // Calculating N
        cout << "Calculating N" << endl;
        bigint p_b = p;
        bigint q_b = q;
        N = p_b * q_b;

        // Calculating phi(N)
        cout << "Calculating phi(N)" << endl;
        phi_N = (p_b - (bigint) 1) * (q_b - (bigint) 1);

        // Calculating d
        cout << "Calculating d" << endl;
        d = extended_euklid_x(e, phi_N);
    }

    cout
            << endl
            << "e:       " << e << endl
            << "p:       " << p << endl
            << "q:       " << q << endl
            << "N:       " << N << endl
            << "phi(N):  " << phi_N << endl
            << "d:       " << d << endl;

    // storing keys to files
    rsaPub << e << "/" << N;
    rsaKey << d << "/" << N;

    // generating encoded message c
    vector<int> blocks = getBlocks(message);
    vector<bigint> blocks_calc;
    for (int i = 0; i < blocks.size(); i++) {
        bigint big_block = blocks[i];
        bigint big_e = e;

        bigint x_pow = big_pow(big_block, big_e);
        bigint x = x_pow % N;
        blocks_calc.push_back(x);
    }

    // storing c to file "data.txt"
    for (int i = 0; i < blocks_calc.size(); i++) {
        dataTxt << blocks_calc[i] << "/";
    }

    // closing files
    rsaPub.close();
    rsaKey.close();
    dataTxt.close();

    return true;
}

#endif //RSA_ENCRYPT_H
