//
// Created by mk on 28.03.2017.
//

#include <string>
#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max_value_exclusive) {
    uint64_t sum = 0;
    for (int dec = 1; dec < max_value_exclusive; dec = dec + 2) {
        auto dec_number_as_string = std::to_string(dec);
        if (isPalindrome(dec_number_as_string) && isPalindrome(toBinaryString(dec))) {
            sum += dec;
        }
    }
    return sum;
}

bool isPalindrome(const std::string &number) {
    unsigned long length = number.length();
    unsigned long number_of_iterations = length / 2;
    for (int i = 0; i < number_of_iterations; i++) {
        if (number[i] != number[length - i - 1]) {
            return false;
        }
    }
    return true;
}

std::string toBinaryString(int dec_number) {
    std::string binary_string = "";
    while (dec_number != 0) {
        (dec_number % 2 == 0) ? binary_string += "0" : binary_string += "1";
        dec_number /= 2;
    }
    return binary_string;
};

