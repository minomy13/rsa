//
// Created by Adrian Mysak on 20.05.22.
//

#ifndef RSA_GETBLOCKS_H
#define RSA_GETBLOCKS_H

#include <vector>
#include <string>
#include <sstream>

vector<int> getBlocks(string message) {
    vector<int> buffer;

    for (int i = 0; i < message.size(); i++) {
        int x = (int) message[i];
        buffer.push_back(x);
    }
    return buffer;
}

vector<int> segmentation(string message) {
    stringstream tmp;
    string segment;
    vector<int> tmp_vec;

    tmp << message;
    while (getline(tmp, segment, '/')) {
        tmp_vec.push_back(stoi(segment));
    }

    return tmp_vec;
}

#endif //RSA_GETBLOCKS_H
