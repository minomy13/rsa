//
// Created by Adrian Mysak on 20.05.22.
//

#ifndef RSA_OWNBIGPOW_H
#define RSA_OWNBIGPOW_H

#include "bigint/bigint.h"
#include <iostream>

using namespace std;

bigint ownBigPow(bigint base, int exponent) {
    int p = 0;

    if (exponent < 2) {
        return 0;
    }

    bigint res = base;
    for (int i = 2; i < exponent + 1; i++) {
        res = res * base;

        int p_tmp = i * 100 / exponent;
        if (p_tmp > p) {
            cout << "□";
            p++;
        }
    }

    return res;
}

#endif //RSA_OWNBIGPOW_H
