//
// Created by mk on 20.04.2017.
//

#include "StudentRepositoryQueries.h"

bool academia::AndQuery::Accept(const academia::Student &student) const {
    return fst->Accept(student) && snd->Accept(student);
}

bool academia::OrQuery::Accept(const academia::Student &student) const {
    return fst->Accept(student) || snd->Accept(student);
}

bool academia::ByLastName::Accept(const academia::Student &student) const {
    return student.Last_name() == lastName_;
}

bool academia::ByYearLowerOrEqualTo::Accept(const academia::Student &student) const {
    return student.Year() <= year_;
}

bool academia::ByOneOfPrograms::Accept(const academia::Student &student) const {
    for (auto p : programs_) {
        if (p == student.Program()) {
            return true;
        }
    }
    return false;
}

bool academia::ByFirstName::Accept(const academia::Student &student) const {
    return student.First_name() == firstName_;
}

academia::OrQuery::OrQuery(std::unique_ptr<Query> first, std::unique_ptr<Query> second) {
    fst = std::move(first);
    snd = std::move(second);
}

academia::AndQuery::AndQuery(std::unique_ptr<Query> first, std::unique_ptr<Query> second) {
    fst = std::move(first);
    snd = std::move(second);
}