#include <string>

//
// Created by mk on 26.03.2017.
//
bool is_palindrome(std::string str) {
    if (str.length() < 2) {
        return true;
    } else {
        return (str.back() == str.front() && is_palindrome(str.substr(1, str.size() - 2)));
    }
}

