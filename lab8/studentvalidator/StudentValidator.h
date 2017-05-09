//
// Created by mk on 03.05.2017.
//

#ifndef JIMP_EXERCISES_STUDENTVALIDATOR_H
#define JIMP_EXERCISES_STUDENTVALIDATOR_H



#include <string>
#include <vector>
#include <stdexcept>

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

    class AcademiaDataValidatorError : public std::runtime_error {
    public:
        AcademiaDataValidatorError() : runtime_error("") {}

        AcademiaDataValidatorError(const std::string &message) : runtime_error(message) {}

    };

    class InvalidNameSurname : public AcademiaDataValidatorError {
    public:
        InvalidNameSurname() : AcademiaDataValidatorError() {}

        InvalidNameSurname(const std::string &name) : AcademiaDataValidatorError("Invalid name: " + name) {}

        ~InvalidNameSurname() {};
    };

    class InvalidNameCharacters : public AcademiaDataValidatorError {
    public:
        InvalidNameCharacters() : AcademiaDataValidatorError() {}

        InvalidNameCharacters(const std::string &name) : AcademiaDataValidatorError("Name \"" + name + "\" contains invalid characters") {}

        ~InvalidNameCharacters() {};
    };

    class InvalidAge : public AcademiaDataValidatorError {
    public:
        InvalidAge() : AcademiaDataValidatorError() {}

        InvalidAge(int age) : AcademiaDataValidatorError("Invalid age: " + std::to_string(age) + ". Acceptable range is <10,100>") {}

        ~InvalidAge() {};
    };

    class InvalidProgram : public AcademiaDataValidatorError {
    public:
        InvalidProgram() : AcademiaDataValidatorError() {}

        InvalidProgram(const std::string &program) : AcademiaDataValidatorError("UnavailableProgram: " + program) {}

        ~InvalidProgram() {}
    };
}
#endif //JIMP_EXERCISES_STUDENTVALIDATOR_H

