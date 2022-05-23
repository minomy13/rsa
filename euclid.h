//
// Created by Adrian Mysak on 20.05.22.
//

#ifndef RSA_EUCLID_H
#define RSA_EUCLID_H

#include "bigint/bigint.h"
#include <vector>
#include <cmath>

using namespace std;

bigint euclid(bigint num1, bigint num2) {
    // helpers
    int a = 0;
    int b = 1;
    int q = 2;
    int r = 3;

    vector<vector<bigint> > table;
    table.push_back(vector<bigint>(6));

    bool done = false;
    bigint finished_on = 0;

    table[0][a] = num1;
    table[0][b] = num2;
    div_t divided_result;
    divided_result = div(6, 5);
    table[0][q] = divided_result.quot;
    table[0][r] = divided_result.rem;

    for (int i = 1; !done; i++) {
        table.push_back(vector<bigint>(6));

        table[i][a] = table[i - 1][b];
        table[i][b] = table[i - 1][r];

        table[i][q] = table[i][a] / table[i][b];
        table[i][r] = table[i][a] % table[i][b];

        if (table[i][r] == finished_on) {
            done = true;
            return table[i - 1][r];
        }
    }
}

bigint extended_euclid_x(bigint num1, bigint num2) {
    // helpers
    int a = 0;
    int b = 1;
    int q = 2;
    int r = 3;
    int x = 4;
    int y = 5;

    vector<vector<bigint> > table;
    table.push_back(vector<bigint>(6));

    bool done = false;
    bigint finished_on = 0;
    int last_i;

    table[0][a] = num1;
    table[0][b] = num2;
    table[0][q] = num1 / num2;
    table[0][r] = num1 % num2;

    for (int i = 1; !done; i++) {
        table.push_back(vector<bigint>(6));

        table[i][a] = table[i - 1][b];
        table[i][b] = table[i - 1][r];

        table[i][q] = table[i][a] / table[i][b];
        table[i][r] = table[i][a] % table[i][b];

        if (table[i][r] == finished_on) {
            done = true;
            last_i = i;
        }
    }

    table[last_i][x] = 0;
    table[last_i][y] = 1;

    for (int i = last_i - 1; i >= 0; i--) {
        table[i][x] = table[i + 1][y];
        table[i][y] = table[i + 1][x] - table[i][q] * table[i + 1][y];

        if (i == 0) {
            return table[0][x];
        }
    }
}

#endif //RSA_EUCLID_H
