//
// Created by mk on 05.04.2017.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>
#include <set>
#include <memory>
#include <ostream>
#include "../../lab7/academiaqueries/StudentRepositoryQueries.h"

using ::std::make_unique;

namespace academia {
    class Query;

    class StudyYear {
    public:
        StudyYear(int i = 1);

//        bool operator==(const StudyYear &other) const;
        //friend bool operator==(const int i, const StudyYear &studyYear);

        StudyYear &operator++();

        StudyYear &operator--();

        StudyYear operator++(int);

        StudyYear operator--(int);

        ~StudyYear() {}

        bool operator<(const StudyYear &studyYear) const;

        void setYear_(int year_);

        int getYear_() const;

        friend std::ostream &operator<<(std::ostream &os, const StudyYear &year);

        operator int() const { return year_; }

    private:
        int year_;

    };

    class Student {
    private:
        std::string id;
        std::string first_name;
        std::string last_name;
        std::string program;
        StudyYear year;
    public:
        bool operator==(const Student &other) const;

        bool operator<(const Student &other) const;

        const std::string &Id() const;

        Student(std::string id, std::string first_name, std::string last_name, std::string program, int year);

        Student() {};

        ~Student() {};

        const std::string &First_name() const {
            return first_name;
        }

        const std::string &Last_name() const {
            return last_name;
        }

        const std::string &Program() const {
            return program;
        }

        int Year() const {
            return year;
        }

        void ChangeLastName(std::string last_name);
    };

    class StudentRepository {
    public:
        StudentRepository(std::initializer_list<Student> list);

        bool operator==(const StudentRepository &other);

        Student &operator[](std::string id);

        const Student &operator[](std::string id) const;

        int StudentCount();

        std::vector<Student> FindByQuery(std::unique_ptr<Query> query);

        ~StudentRepository() {}

    private:
        std::vector<Student> students_;
    };

    std::ostream &operator<<(std::ostream &os, const StudentRepository &studentRepository);

    std::istream &operator>>(std::istream &os, StudentRepository &studentRepository);

    std::ostream &operator<<(std::ostream &os, const Student &student);

    std::istream &operator>>(std::istream &os, Student &student);

    std::ostream &operator<<(std::ostream &os, const StudyYear &year);

    std::istream &operator>>(std::istream &is, const StudyYear &studyYear);

    bool operator==(const int i, const StudyYear &studyYear);
}
#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H