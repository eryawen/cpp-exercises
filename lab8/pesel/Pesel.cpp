//
// Created by mk on 27.04.2017.
//

#include <string>
#include "Pesel.h"
#include <regex>

namespace academia {
    Pesel::Pesel(const std::string &pesel) {
        validatePESEL(pesel);
        pesel_ = pesel;
    }

    void Pesel::validatePESEL(const std::string &pesel) {
        if (pesel.length() != 11) {
            throw InvalidPeselLength(pesel, pesel.length());
        }

        std::regex reg("^\\d{11}$");
        if (!regex_match(pesel, reg)) {
            throw InvalidPeselCharacter(pesel);
        }

        int controlSum = 0;
        int rates[11] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
        for (int i = 0; i < 11; i++) {
            controlSum += digitAt(pesel, i) * rates[i];
        }

        if (controlSum % 10 != 0) {
            throw InvalidPeselChecksum(pesel, controlSum);
        }
    }

    int Pesel::digitAt(const std::string &pesel, int i) {
        return (pesel.at(i) - '0');
    }

    std::string AcademiaDataValidatorError::baseMessage(const std::string &pesel) {
        return "Invalid PESEL(" + pesel + ") ";
    }

}