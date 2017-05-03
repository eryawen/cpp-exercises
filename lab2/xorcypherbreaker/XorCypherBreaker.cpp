//
// Created by mk on 01.05.2017.
//

#include <iostream>
#include "XorCypherBreaker.h"

std::string getNextKey(std::string key) {
    key[2]++;
    if (key[2] == 'z' + 1) {
        key[1]++;
        key[2] = 'a';
        if (key[1] == 'z' + 1) {
            key[0]++;
            key[1] = 'a';
        }
    }
    return key;
}

std::string XorCypherBreaker(std::vector<char> &encrypted, int key_length, std::vector<std::string> &dictionary) {
    std::vector<std::string> keys;
    int key_pos = 0;
    int encrypted_pos = 0;

    std::string key = "aaa";
    while (encrypted_pos != encrypted.size()) {
        int afterXor = encrypted[encrypted_pos] ^key[key_pos];

        if ((afterXor >= 32 && afterXor <= 90) || (afterXor >= 97 && afterXor <= 122)) {
            key_pos++;
            encrypted_pos++;
            if (key_pos == key_length) {
                key_pos = 0;
            }
        } else {
            key_pos = 0;
            encrypted_pos = 0;
            key = getNextKey(key);
            continue;
        }
    }
    return key;
}
