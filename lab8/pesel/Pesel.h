//
// Created by mk on 27.04.2017.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>

namespace academia {

    class Pesel {
    public:
        Pesel(const std::string &pesel);

        void validatePESEL(const std::string &pesel);

    private:
        std::string pesel_;

        int digitAt(const std::string &pesel, int i);
    };

    class AcademiaDataValidatorError : public std::runtime_error {
    public:
        AcademiaDataValidatorError() : std::runtime_error("") {}

        AcademiaDataValidatorError(const std::string &message) : std::runtime_error(message) {}

        std::string baseMessage(const std::string &pesel);

    };

    class InvalidPeselChecksum : public AcademiaDataValidatorError {
    public:
        InvalidPeselChecksum(const std::string &pesel, int controlSum) : AcademiaDataValidatorError(
                baseMessage(pesel) + "checksum: " + std::to_string(controlSum)) {}

    };

    class InvalidPeselLength : public AcademiaDataValidatorError {
    public:
        InvalidPeselLength(const std::string &pesel, int length)
                : AcademiaDataValidatorError(baseMessage(pesel) + "length: " + std::to_string(length)) {}

    };

    class InvalidPeselCharacter : public AcademiaDataValidatorError {
    public:
        InvalidPeselCharacter(const std::string &pesel) : AcademiaDataValidatorError(
                baseMessage(pesel) + "character set") {}

    };

}


#endif //JIMP_EXERCISES_PESEL_H

//todo message