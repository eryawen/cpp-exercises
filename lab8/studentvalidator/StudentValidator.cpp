//
// Created by mk on 03.05.2017.
//

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
        bool hasMiddleName;
        std::regex withoutMiddleName{"^(\\S+)\\s(\\S+)$"};
        std::regex withMiddleName{"^(\\S+)\\s(\\S+)\\s(\\S+)$"};
        std::smatch matchesWithoutMiddleName;
        std::smatch matchesWithMiddleName;

        hasMiddleName = std::regex_match(names, matchesWithMiddleName, withMiddleName);
        if (!std::regex_match(names, matchesWithoutMiddleName, withoutMiddleName) && !hasMiddleName) {
            throw InvalidNameSurname();
        }
        if (hasMiddleName) {
            validateName(matchesWithMiddleName[1]);
            validateName(matchesWithMiddleName[2]);
            validateSurname(matchesWithMiddleName[3]);
        } else {
            validateName(matchesWithoutMiddleName[1]);
            validateSurname(matchesWithoutMiddleName[2]);
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
//todo refactoring, messages