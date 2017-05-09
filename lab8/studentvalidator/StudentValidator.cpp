//
// Created by mk on 03.05.2017.
//

#include <string>
#include <regex>
#include <iostream>
#include "StudentValidator.h"

using std::cout;

namespace academia {

    void StudentValidator::checkProgram(const std::string &program) {
        for (std::string &program_ : programs) {
            if (program_.compare(program) == 0) {
                return;
            }
        }
        throw InvalidProgram();
    }

    void StudentValidator::checkAge(int age) {
        if (age < 10 || age > 100) {
            throw InvalidAge();
        }
    }

    void StudentValidator::checkNames(const std::string &names) {
        bool has_middle_name;
        std::regex without_middle_name{"^(\\S+)\\s(\\S+)$"};
        std::regex with_middle_name{"^(\\S+)\\s(\\S+)\\s(\\S+)$"};
        std::smatch matches_without_middle_name;
        std::smatch matches_with_middle_name;

        has_middle_name = std::regex_match(names, matches_with_middle_name, with_middle_name);
        if (!std::regex_match(names, matches_without_middle_name, without_middle_name) && !has_middle_name) {
            throw InvalidNameSurname();
        }
        if (has_middle_name) {
            validateName(matches_with_middle_name[1]);
            validateName(matches_with_middle_name[2]);
            validateSurname(matches_with_middle_name[3]);
        } else {
            validateName(matches_without_middle_name[1]);
            validateSurname(matches_without_middle_name[2]);
        }
    }

    void StudentValidator::validate_IsLower(char c) {
        if (!islower(c)) {
            throw InvalidNameCharacters();
        }
    }

    void StudentValidator::validate_IsUpper(char c) {
        if (!isupper(c)) {
            throw InvalidNameCharacters();
        }
    }

    void StudentValidator::validateName(const std::string &word) {
        validate_IsUpper(word[0]);
        for (int i = 1; i < word.length(); i++) {
            validate_IsLower(word[i]);
        }
    }

    void StudentValidator::validateSurname(const std::string &surname) {
        validate_IsUpper(surname[0]);
        int i = 1;
        while (i < surname.length()) {
            if (islower(surname[i])) {
                i++;
                continue;
            } else if (surname[i] == '-') {
                validate_IsUpper(surname[i + 1]);
                i += 2;
            } else {
                throw InvalidNameCharacters();
            }
        }
    }
}

//NOT TO USE "NEW"