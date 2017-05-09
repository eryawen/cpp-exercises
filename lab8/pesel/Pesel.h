//
// Created by mk on 27.04.2017.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include "../../lab8/studentvalidator/StudentValidator.h"
#include <string>
#include <stdexcept>

using ::academia::AcademiaDataValidatorError;

namespace academia {
    std::string basePeselMessage(const std::string &pesel);

    class Pesel {
    public:
        Pesel(const std::string &pesel);

        void validatePESEL(const std::string &pesel);

    private:
        std::string pesel_;

        int digitAt(const std::string &pesel, int i);
    };

    class InvalidPeselChecksum : public AcademiaDataValidatorError {
    public:
        InvalidPeselChecksum(const std::string &pesel, int controlSum) : AcademiaDataValidatorError(
                basePeselMessage(pesel) + "checksum: " + std::to_string(controlSum)) {}

    };

    class InvalidPeselLength : public AcademiaDataValidatorError {
    public:
        InvalidPeselLength(const std::string &pesel, int length)
                : AcademiaDataValidatorError(basePeselMessage(pesel) + "length: " + std::to_string(length)) {}

    };

    class InvalidPeselCharacter : public AcademiaDataValidatorError {
    public:
        InvalidPeselCharacter(const std::string &pesel) : AcademiaDataValidatorError(
                basePeselMessage(pesel) + "character set") {}

    };

}


#endif //JIMP_EXERCISES_PESEL_H

