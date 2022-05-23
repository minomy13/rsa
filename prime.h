//
// Created by Adrian Mysak on 20.05.22.
//

#ifndef RSA_PRIME_H
#define RSA_PRIME_H

using namespace std;

// check if number is prime
// returns true on prime
bool prime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

#endif //RSA_PRIME_H
