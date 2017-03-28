//
// Created by mk on 26.03.2017.
//

#include "ReverseString.h"

std::string reverse(std::string str) {
    const char *characters = str.c_str();
    if (characters[0] == '\0') {
        return "";
    } else {
        size_t size = str.size();
        return reverse(str.substr(1, size - 1)).append(1, characters[0]);
    }
}

std::string reverseStringShorter(std::string str) {
    return (str.length() == 0 || str.length() == 1) ? str
                                                    : reverseStringShorter(str.substr(1, str.length() - 1)) + str.at(0);
}
/*
 * return std::string(reversed_characters);
 * TODO size_t, std::string, iterators
 */
