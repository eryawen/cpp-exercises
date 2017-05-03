//
// Created by mk on 03.05.2017.
//

#ifndef JIMP_EXERCISES_STUDENTVALIDATOR_H
#define JIMP_EXERCISES_STUDENTVALIDATOR_H

#include <string>
#include <vector>
#include "../../lab8/pesel/Pesel.h"

using academia::AcademiaDataValidatorError;
namespace academia {
    class StudentValidator {
    public:
        StudentValidator() {}

        void checkNames(const std::string &names);

        void checkProgram(const std::string &program);

        void checkAge(int age);

        ~StudentValidator() {};
    private:
        std::vector<std::string> programs{"informatyka", "filozofia", "fizyka", "ekonomia", "matematyka"};

        void validateName(const std::string &word);

        void validateSurname(const std::string &surname);

        void validate_IsUpper(char c);

        void validate_IsLower(char c);
    };

    class InvalidNameSurname : public AcademiaDataValidatorError {
    public:
        InvalidNameSurname() : AcademiaDataValidatorError() {}
    };

    class InvalidNameCharacters : public AcademiaDataValidatorError {
    public:
        InvalidNameCharacters() : AcademiaDataValidatorError() {}
    };

    class InvalidAge : public AcademiaDataValidatorError {
    public:
        InvalidAge() : AcademiaDataValidatorError() {}

    };

    class InvalidProgram : public AcademiaDataValidatorError {
    public:
        InvalidProgram() : AcademiaDataValidatorError() {}
    };
}
#endif //JIMP_EXERCISES_STUDENTVALIDATOR_H

//todo destructor, message, separate file for exceptions