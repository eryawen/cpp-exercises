//
// Created by mk on 05.04.2017.
//

#include <cstring>
#include "StudentRepository.h"
//#include "json.hpp"
//using json = nlohmann::json;
namespace academia {
    StudyYear &StudyYear::operator++() {
        year_++;
        return *this;

    }

    StudyYear &StudyYear::operator--() {
        year_--;
        return *this;
    }

    StudyYear StudyYear::operator++(int) {
        StudyYear temp = *this;
        ++(this->year_);
        return temp;
    }

    StudyYear StudyYear::operator--(int) {
        StudyYear temp = *this;
        --(this->year_);
        return temp;
    }

    void StudyYear::setYear_(int year) {
        year_ = year;
    }

    int StudyYear::getYear_() const {
        return year_;
    }

    StudyYear::StudyYear(int year) {
        year_ = year;
    }

    bool StudyYear::operator<(const StudyYear &studyYear) const {
        return year_ - studyYear.year_ < 0;
    }

//    bool StudyYear::operator==(const StudyYear &other) const {
//        return year_ == other.year_;
//    }

    bool StudentRepository::operator==(const StudentRepository &other) {
        return students_.size() == other.students_.size()
               && std::equal(students_.begin(), students_.end(), other.students_.begin());
    }

    Student &StudentRepository::operator[](std::string id) {
        //todo
    }

    const Student &StudentRepository::operator[](std::string id) const { //todo
        for (auto &student : students_) {
            if (student.Id().compare(id)) {
                return student;
            }
        }
    }

    int StudentRepository::StudentCount() {
        return students_.size();
    }

    StudentRepository::StudentRepository(std::initializer_list<Student> list) {
        for (auto &s : list) {
            students_.insert(s);
        }
    }

    bool Student::operator==(const Student &other) const {
        return id.compare(other.id) == 0;
    }

    const std::string &Student::Id() const {
        return id;
    }

    Student::Student(std::string id, std::string first_name, std::string last_name, std::string program, int year) {
        this->id = id;
        this->first_name = first_name;
        this->last_name = last_name;
        this->program = program;
        this->year = year;
    }

    void Student::ChangeLastName(std::string last_name) {
        this->last_name = last_name;
    }

    bool Student::operator<(const Student &other) const {
        return id < other.id;
    }

    std::ostream &operator<<(std::ostream &os, const StudentRepository &studentRepository) {
        return os; //todo
    }

    std::istream &operator>>(std::istream &os, StudentRepository &studentRepository) {
        return os; //todo
    }

    std::ostream &operator<<(std::ostream &os, const Student &student) {
        return os; //todo
    }

    std::istream &operator>>(std::istream &is, Student &student) {
        return is; //todo
    }

    std::ostream &operator<<(std::ostream &os, const StudyYear &year) {
        os << year.getYear_();
        return os;
    }

//    bool operator==(const int i, const StudyYear &studyYear) {
//        return i == studyYear.getYear_();
//    }

    std::istream &operator>>(std::istream &is, StudyYear &studyYear) {
        return is; //todo
    }
}
