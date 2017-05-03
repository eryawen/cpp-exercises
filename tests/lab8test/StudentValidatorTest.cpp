//
// Created by mk on 03.05.2017.
//


#include <gtest/gtest.h>
#include <memory>
#include <MemLeakTest.h>
#include <StudentValidator.h>

using ::std::string;
using ::academia::StudentValidator;
using ::academia::InvalidProgram;
using ::academia::InvalidAge;
using ::academia::InvalidNameCharacters;
using ::academia::InvalidPeselLength;
using ::academia::InvalidNameSurname;


class StudentValidatorTest : public ::testing::Test, MemLeakTest {
protected:
    static StudentValidator studentValidator; //todo clean-up (?)

    static void SetUpTestCase() {
        studentValidator = StudentValidator();
    }
};

StudentValidator StudentValidatorTest::studentValidator;

TEST_F(StudentValidatorTest, CorrectFirstNameAndSurname_DoesNotThrowException) {
    EXPECT_NO_THROW(studentValidator.checkNames("Sherlock Holmes"));
}

TEST_F(StudentValidatorTest, CorrectTwoNamesAndSurname_DoesNotThrowException) {
    EXPECT_NO_THROW(studentValidator.checkNames("The Snow Queen"));
}

TEST_F(StudentValidatorTest, SurnameWithHyphen_DoesNotThrowException) {
    EXPECT_NO_THROW(studentValidator.checkNames("Batman Spider-Man"));
}

TEST_F(StudentValidatorTest, StudentWithoutSurname_ThrowsInvalidNameSurnameException) {
    EXPECT_THROW(studentValidator.checkNames("Gandalf"), InvalidNameSurname);
}

TEST_F(StudentValidatorTest, FourNamesAndSurname_ThrowsInvalidNameSurnameException) {
    EXPECT_THROW(studentValidator.checkNames("Someone With Too Many Names"), InvalidNameSurname);
}

TEST_F(StudentValidatorTest, SurnameBeginsWithLowercaseLetter_ThrowsInvalidNameSurnameException) {
    EXPECT_THROW(studentValidator.checkNames("Jack sparrow"), InvalidNameSurname);
}

TEST_F(StudentValidatorTest, MiddleNameHasUppercaseLetterWithin_ThrowsInvalidNameSurnameException) {
    EXPECT_THROW(studentValidator.checkNames("Hermione JaNe Granger"), InvalidNameSurname);
}

TEST_F(StudentValidatorTest, FirstNameContainsInvalidSpecialCharacter_ThrowsInvalidNameCharactersException) {
    EXPECT_THROW(studentValidator.checkNames("Ellio%t Anderson"), InvalidNameCharacters);
}

TEST_F(StudentValidatorTest, MiddleNameContainsDigit_ThrowsInvalidNameCharactersException) {
    EXPECT_THROW(studentValidator.checkNames("Hermione Jan7e Granger"), InvalidNameCharacters);
}

TEST_F(StudentValidatorTest, CorrectAge_DoesNotThrowException) {
    EXPECT_NO_THROW(studentValidator.checkAge(21));
}

TEST_F(StudentValidatorTest, StudentIsTooYoung_ThrowsInvalidAgeException) {
    EXPECT_THROW(studentValidator.checkAge(7), InvalidAge);

}

TEST_F(StudentValidatorTest, StudentIsTooOld_ThrowsInvalidAgeException) {
    EXPECT_THROW(studentValidator.checkAge(101), InvalidAge);
}

TEST_F(StudentValidatorTest, AvailableProgram_DoesNotThrowException) {
    EXPECT_NO_THROW(studentValidator.checkProgram("informatyka"));
}

TEST_F(StudentValidatorTest, UnavailableProgram_ThrowsInvalidProgramException) {
    EXPECT_THROW(studentValidator.checkProgram("historia"), InvalidAge);
}

//todo memory leak